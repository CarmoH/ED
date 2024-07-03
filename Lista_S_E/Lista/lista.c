#include <stdio.h>
#include <stdlib.h>

struct no
{
    int info;
    struct no *prox;
    
};
typedef struct no No;

No* criar_no(int valor){
    No* novo= (No*)malloc(sizeof(No));
    novo->info= valor;
    novo->prox= NULL;

    return novo;
}

No* insere_inicial(No* inicio, int valor){
    No* novo= criar_no(valor);

    if(inicio==NULL){//verificando se esta recebendo o valor
        inicio = novo; //pela primeria vez
    }
    else{
        novo->prox=inicio; //o proximo valor sera oq estava no inicio
        inicio = novo; //o valor novo se torna o inicio

    }
    return inicio;
}

void mostrar(No* inicio){
    while(inicio != NULL){
        printf(" %d", inicio->info);
        inicio= inicio->prox;
    }
}

int main(){
    No* inicio= NULL;

    inicio = insere_inicial(inicio, 6); //o primeiro valor sera o ultimo
    inicio = insere_inicial(inicio, 10);

    mostrar(inicio);
    
}