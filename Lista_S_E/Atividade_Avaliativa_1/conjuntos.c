#include <stdio.h>
#include <stdlib.h>

struct no
{
    int info;
    struct no *prox;
    
};
typedef struct no No;

No* criar_no(int valor);
void mostrar(No* inicio);
No* lista(int n, int *vetor);
No* intersecao(No* inicio_n, No* inicio_m);
No* inserir_fim(No* novo, int valor);
No* uniao(No* inicio_n, No* inicio_m, int n, int m);
void remover_valor(No **aux, int tirar);
int menor_valor(No* aux);
No* crescente (No* inicio);


No* criar_no(int valor){
    No* novo= (No*)malloc(sizeof(No));
    novo->info= valor;
    novo->prox= NULL;

    return novo;
}


No* inserir_fim(No* novo, int valor){ //inserindo um valor no fim da lista
    No* lista, *aux=NULL;
    lista = criar_no(valor);


    if(novo == NULL){
        novo = lista;
    }
    else{
        aux = novo;
        while(aux->prox!= NULL)  //achar o ultimo valor
            aux = aux->prox;
        aux->prox = lista; //add no fim
    }
    return novo;
}

void mostrar(No* inicio){
    while(inicio != NULL){
        printf(" %d", inicio->info);
        inicio= inicio->prox;
    }
}

No* lista(int n, int *vetor){
    int i=0, aux=0;
    No* novo = NULL, *lista=NULL;

    vetor = (int*)malloc(n*sizeof(int));

    for(i=0; i<n; i++){
        scanf("%d", &vetor[i]);
    }
    i=0;
    while(i<n){
        aux = vetor[i];
        novo = inserir_fim(novo, aux);
        lista = novo;
        i++;
    }

    return lista;
}

No* intersecao(No* inicio_n, No* inicio_m){
    No* aux_n= inicio_n, *aux_m= inicio_m, *i, *inter=NULL;
    
    while(aux_n!=NULL){
        for(i=aux_m; i != NULL; i = i->prox){
            if(aux_n->info == i->info){
                inter = inserir_fim(inter, aux_n->info);
            }
        }
        aux_n = aux_n->prox;
    }
    if(inter == NULL)
        inter = NULL;
    
    return inter;
}

No* uniao(No* inicio_n, No* inicio_m, int n, int m){
    No* aux_n= inicio_n, *aux_m= inicio_m, *i, *uni=inicio_n;
    int qtd=0;

    
    while (aux_n!=NULL)
    {
        for(i=aux_m; i != NULL; i = i->prox){
            if(aux_n->info == i->info){
                qtd++;
                remover_valor(&aux_m, aux_n->info);
            }
        }
        aux_n= aux_n->prox;
    }
    if(qtd == n && qtd== m){
        uni = NULL;
    }
    while (aux_m!=NULL)
    {
        uni = inserir_fim(uni, aux_m->info);

        aux_m = aux_m->prox;
    }

    return uni;
}
void remover_valor(No **aux, int tirar){
    No* lista, *anterior= NULL;

    lista = *aux;
    if(lista != NULL){
        while(lista!= NULL && lista->info!= tirar){
            anterior = lista;
            lista = lista -> prox;
        }
        if(lista != NULL){
            if(lista == *aux){
                *aux = lista->prox;
            }
            else{
                anterior->prox = lista->prox;
                lista->prox = NULL;
            }
        }
    }
}
No* crescente (No* inicio){
    No* aux= inicio;
    No*lista=NULL;
    int removido=0, menor=0;
    
    while(aux!= NULL){
        menor= menor_valor(aux);
        remover_valor(&aux, menor);
        lista = inserir_fim(lista, menor);
    }
    return lista;
}

int menor_valor(No* aux){
    int menor=aux->info;
    No* lista=aux, *anterior=NULL;
    while(lista != NULL){
        anterior = lista;
        if(menor > anterior->info){
            menor = anterior->info;
        }
        lista= lista->prox;
    }
    return menor;
}

int main(){
    No* inicio_n= NULL, *inicio_m=NULL, *inter=NULL, *uni=NULL;
    int n=0, m=0, i=0, valor_n=0, valor_m=0;
    int *vetor_n, *vetor_m;

    scanf("%d %d", &n, &m);

    inicio_n = lista(n, vetor_n);
    inicio_m = lista(m, vetor_m);

    inter = intersecao(inicio_n, inicio_m);
    mostrar(inter);
    printf("\n");

    uni = uniao(inicio_n, inicio_m, n, m);

    uni = crescente(uni);
    mostrar(uni);
    printf("\n");

    return 0;
}