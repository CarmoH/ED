/* 4. Copy(): Copia elementos da lista atual para uma nova lista; a lista  original permanece intacta (sem uso de nó adicional temporário)*/

#include <stdio.h>
#include <stdlib.h>

struct no
{
    int info;
    struct no *prox;
};
typedef struct no No;

No* criar_no(int valor);
No* inserir(No* inicio, int valor);
void mostrar(No* inicio);
No* inserir_fim(No* novo, int valor);
No* copia(No* inicio, No* novo);


No* criar_no(int valor){
    No* novo = (No*)malloc(sizeof(No));
    novo->info = valor;
    novo->prox = NULL;

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

No* copia(No* inicio, No* novo){
    No* aux = inicio;

    while(aux != NULL){
        novo = inserir_fim(novo, aux->info);
        aux = aux->prox;
    }
    return novo;
}
void mostrar(No* inicio){
    while(inicio != NULL){
        printf(" %d", inicio->info);
        inicio= inicio->prox;
    }
}

int main(){
    No* inicio=NULL, *novo=NULL;

    inicio= inserir_incial(inicio, 6);
    inicio= inserir_incial(inicio, 10);
    inicio= inserir_incial(inicio, 5);
    inicio= inserir_incial(inicio, 2);

    novo = copia(inicio, novo);

    printf("\n Lista inicial:");
    mostrar(inicio);
    printf("\n Lista Copia:");
    mostrar(novo);

    return 0;
}