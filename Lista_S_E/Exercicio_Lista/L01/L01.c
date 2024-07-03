/* 1. Minimum()/Maximum(): Retorna ponteiro p que o elemento de menor (maior) valor x se encontra na lista; caso não encontre, retorna p igual a NULL;*/
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
int menor_valor(No* inicio);
int maior_valor(No* inicio);

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

int menor_valor(No* inicio){
    int menor=inicio->info;
    No* aux=inicio, *anterior=NULL;
    while(aux->prox != NULL){
        anterior = aux;
        if(menor > anterior->info){
            menor = anterior->info;
        }
        aux= aux->prox;
    }
    return menor;
}

int maior_valor(No* inicio){
    int maior=inicio->info;
    No* aux=inicio, *anterior=NULL;
    while(aux->prox != NULL){
        anterior = aux;
        if(maior < anterior->info){
            maior = anterior->info;
        }
        aux= aux->prox;
    }
    return maior;
}

int main(){
    No* inicio=NULL;
    int menor=0, maior=0;

    inicio= inserir_incial(inicio, 6);
    inicio= inserir_incial(inicio, 10);
    inicio= inserir_incial(inicio, 20);
    inicio= inserir_incial(inicio, 2);

    mostrar(inicio);

    menor = menor_valor(inicio);
    printf("\n Menor valor da lista: %d", menor);

    maior = maior_valor(inicio);
    printf("\n Maior valor da lista: %d\n", maior);

    return 0;
}