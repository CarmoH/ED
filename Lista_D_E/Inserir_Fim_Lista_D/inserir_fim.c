#include <stdio.h>
#include <stdlib.h>

struct nod
{
    int info;
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

Listad* cria_listad(Listad* l);
Nod* criar_no(int valor);
void mostrar(Listad* l);
Listad* inserir_fim(Listad* l, int valor);

Listad* cria_listad(Listad* l){
    Listad *L = (Listad*)malloc(sizeof(Listad));
    L->inicio = L->fim = NULL;
    return L;
}
Nod* criar_no(int valor){
    Nod* novo= (Nod*)malloc(sizeof(Nod));
    novo->info= valor;
    novo->prox= NULL;
    novo->anterior=NULL;

    return novo;
}

void mostrar(Listad* l){
    Nod* aux =l->inicio;
    while(aux!= NULL){
        printf(" %d", aux->info);
        aux= aux->prox;
    }

}

Listad* inserir_fim(Listad* l, int valor){
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

int main(){
    Listad *l=NULL;

    l= cria_listad(l);

    l = inserir_fim(l, 6);
    l = inserir_fim(l, 5);
    l = inserir_fim(l, 7);
    l = inserir_fim(l, 9);

    mostrar(l);

    return 0;
}