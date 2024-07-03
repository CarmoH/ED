/* Sort(): Ordena elementos da lista em ordem crescente (sem uso de nó adicionaltemporário)*/

#include <stdio.h>
#include <stdlib.h>

struct no
{
    int info;
    struct no *prox;
    
};
typedef struct no No;

No* criar_no(int valor);
No* inserir_incial(No* inicio, int valor);
void mostrar(No* inicio);
No* crescente (No* inicio);
void remover_valor(No **aux, int tirar);
int menor_valor(No* inicio);
No* inserir_fim(No* novo, int valor);

No* criar_no(int valor){
    No* novo= (No*)malloc(sizeof(No));
    novo->info= valor;
    novo->prox= NULL;

    return novo;
}

No* inserir_incial(No* inicio, int valor){
    No* novo = criar_no(valor);

    if(inicio == NULL){
        inicio = novo;
    }
    else{
        novo->prox= inicio;
        inicio = novo;
    }
    return inicio;
}

void mostrar(No* inicio){
    while(inicio != NULL){
        printf(" %d", inicio->info);
        inicio= inicio->prox;
    }
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
void remover_valor(No **aux, int tirar){
    No* lista, *anterior= NULL;

    lista = *aux;
    if(lista != NULL){
        while(lista != NULL && lista->info!= tirar){
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
        //printf("\n LISTA:");
        //mostrar(aux);
        menor= menor_valor(aux);
        //printf("\n MENOR: %d", menor);
        remover_valor(&aux, menor);
        lista = inserir_fim(lista, menor);
    }
    return lista;
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

int main(){
    No* inicio = NULL;

    inicio= inserir_incial(inicio, 6);
    inicio= inserir_incial(inicio, 10);
    inicio= inserir_incial(inicio, 2);
    inicio= inserir_incial(inicio, 20);

    mostrar(inicio);

    inicio = crescente(inicio);
    printf("\n ORDEM CRESCENTE:");
    mostrar(inicio);

    return 0;
}