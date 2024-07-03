/*  2. Reverse(): Versão que inverte a posição dos elementos criando uma nova lista; a lista original permanece intacta*/

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
    No* anterior=NULL, *atual=NULL, *seguinte=NULL;
    
    atual = inicio;
    while(atual!= NULL){
        seguinte = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = seguinte;
    }
    /*
    while(aux != NULL){
        novo = inserir_incial(novo, aux->info);
        aux = aux->prox;
    }
    */
    return anterior;
}

int main(){
    No* inicio=NULL;

    inicio= inserir_incial(inicio, 6);
    inicio= inserir_incial(inicio, 10);
    inicio= inserir_incial(inicio, 5);
    inicio= inserir_incial(inicio, 2);
    mostrar(inicio);

    inicio = reverse(inicio);
    
    printf("\n Lista nova:");
    mostrar(inicio);

    return 0;
}