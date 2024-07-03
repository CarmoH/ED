#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nod
{
    char letra;
    struct nod *prox;
    struct nod *anterior;
    
};
typedef struct nod Nod;

struct listad
{
    Nod* inicio;
    Nod* fim;
};
typedef struct listad Listad;

struct no
{
    int info;
    char letra;
    struct no *prox;
    
};
typedef struct no No;

struct listnod
{
    No* inicio;
    No* fim;
};
typedef struct listnod Listnod;


Listad* cria_listad();
Listnod* cria_listnod();
Nod* criar_no(char valor);
No* criar_nod(char valor);
void mostrar(Listad* l);
void inserir_fim(Listad* l, char valor);
void inserir_fimd(Listnod* list, char valor);
void mostrarno(Listnod* inicio);
void repetidos(Listad* l, Listnod* list);
No* criar_nod(char valor);
void quantidade(Listad* l, Listnod* list);
void alfab(Listnod* list);

Listad* cria_listad(){
    Listad *L = (Listad*)malloc(sizeof(Listad));
    L->inicio = L->fim = NULL;
    return L;
}

Listnod* cria_listnod(){
    Listnod *N = (Listnod*)malloc(sizeof(Listnod));
    N->inicio = N->fim = NULL;
    return N;
}

Nod* criar_no(char valor){
    Nod* novo= (Nod*)malloc(sizeof(Nod));
    novo->letra= valor;
    novo->prox= NULL;
    novo->anterior=NULL;

    return novo;
}
No* criar_nod(char valor){
    No* novo = (No*)malloc(sizeof(No));
    novo->letra = valor;
    novo->info = 1;
    novo->prox = NULL;

    return novo;
}

void inserir_fim(Listad* l, char valor){
    Nod* novo = criar_no(valor);
    Nod* aux =NULL;

    if(l->inicio == NULL){
        l->inicio = novo;
        l->fim= novo;
    }
    else{
        aux=l->inicio;
        while(aux->prox!= NULL)  //achar o ultimo valor
            aux = aux->prox;
        aux->prox = novo;
        novo->anterior = aux;
        l->fim= novo;
    }
}

void repetidos(Listad* l, Listnod* list){
    Nod* i=NULL;
    No* n =NULL;
    int flag=0;
    for(i =l->inicio; i!=NULL; i = i->prox){
        if(list->inicio == NULL){
            inserir_fimd(list, i->letra);
        }
        else{
            flag=0;
            for(n = list->inicio; n!=NULL; n=n->prox){
                if(i->letra == n->letra){
                    flag++;
                }
            }
            if(flag==0)
                inserir_fimd(list, i->letra);
        }
    }
}
void alfab(Listnod* list){
    No* i=NULL, *j=NULL;
    int aux1=0, aux2=0;

    for(i = list->inicio; i!=NULL; i = i->prox){
        for(j = i->prox; j!=NULL; j = j->prox){
            if(i ->letra > j->letra){
                aux1 = i->letra;
                aux2 = i->info;
                
                i->letra = j->letra;
                i->info = j->info;  

                j->letra = aux1;
                j->info = aux2;
            }
        }
    }
}
void quantidade(Listad* l, Listnod* list){
    Nod* i=NULL, *j=NULL;
    No* n=NULL;
    int qtd=1;
    for(i =l->inicio; i!=NULL; i = i->prox){
        qtd=1;
        for(j =i->prox; j!=NULL; j = j->prox){
            if(i->letra == j->letra){
                qtd++;
            }
            for(n = list->inicio; n!=NULL; n=n->prox){
                if(i->letra == n->letra){
                    if(n->info < qtd || n->info ==1)
                        n->info = qtd;
                }
            }
        }
    }
}

void mostrar(Listad* l){
    Nod* aux =l->inicio;
    while(aux!= NULL){
        printf(" %c", aux->letra);
        aux= aux->prox;
    }

}
void mostrarno(Listnod* list){
    No* aux = list->inicio;
    while(aux != NULL){
        printf("%c %d\n", aux->letra, aux->info);
        aux= aux->prox;
    }
}

void inserir_fimd(Listnod* list, char letra){ //inserindo um valor no fim da lista
    No* novo = criar_nod(letra);
    No* aux =NULL;

    if(list->inicio == NULL){
        list->inicio = novo;
        list->fim= novo;
    }
    else{
        aux=list->inicio;
        while(aux->prox!= NULL)  //achar o ultimo valor
            aux = aux->prox;
        aux->prox = novo;
        list->fim= novo;
    }
}


int main(){
    Listad *l=NULL;
    Listnod* list=NULL;
    int n=0, tam=0;
    char letra[100];
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        l= cria_listad();
        list= cria_listnod();
        getchar();
        scanf("%s", letra);
        tam = strlen(letra);
        for(int j=0; j<tam; j++){
            inserir_fim(l, letra[j]);
        }
        repetidos(l, list);
        quantidade(l, list);
        alfab(list);
        mostrarno(list);
        free(l);
        free(list);
    }

    return 0;
}