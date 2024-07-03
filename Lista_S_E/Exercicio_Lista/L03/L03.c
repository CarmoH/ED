/* 3. Reverse(): Versão que inverte a posição dos elementos da lista sem criar uma nova lista*/

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
No* reverse(No* inicio);

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

void mostrar(No* inicio){
    while(inicio != NULL){
        printf(" %d", inicio->info);
        inicio= inicio->prox;
    }
}

No* reverse(No* inicio){
    No* aux = inicio, *novo = NULL;
    while(aux != NULL){
        novo = inserir_incial(novo, aux->info);
        aux = aux->prox;
    }
    return novo;

}

int main(){
    No* inicio=NULL;

    inicio= inserir_incial(inicio, 6);
    inicio= inserir_incial(inicio, 10);
    inicio= inserir_incial(inicio, 5);
    inicio= inserir_incial(inicio, 2);

    printf("\n Lista Normal:");
    mostrar(inicio);

    inicio = reverse(inicio);
    printf("\n Lista inversa:");
    mostrar(inicio);

    return 0;
}