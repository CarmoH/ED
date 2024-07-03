#include <stdio.h>
#include <stdlib.h>

/* Escreve uma função q retire o ultimo elemento de uma lista dada. Esta função deve ter
como valor de retono o ponteiro para a lista alterada e deve obedecer o segunite protótipo
(Lista* retira_ultimo(Lista* L);)*/

struct no
{
    int info;
    struct no *prox;
};
typedef struct no No;

No* criar_no(int valor);
No* inserir(No* inicio, int valor);
void mostrar(No* inicio);
No* remover(No* inicio);


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


No* remover(No* inicio){
    No* aux = inicio, *anterior = NULL;

    if(aux != NULL){
        while(aux->prox!= NULL){ //Encontrando o PENULTIMO valor da lista
            anterior = aux; //penultimo
            aux = aux->prox;
        }

        if(aux != NULL){
            if(aux-> prox == NULL){ //se o prox valor for null ent este é o ultimo elemento
                anterior->prox = NULL;  //exculindo o ultimo valor
            }
        }
    }
    return aux;
}



int main(){
    No* inicio=NULL;

    inicio= inserir_incial(inicio, 6);
    inicio= inserir_incial(inicio, 10);
    inicio= inserir_incial(inicio, 20);
    inicio= inserir_incial(inicio, 2);
    
    printf("\n Lista completa_______: ");
    mostrar(inicio);

    //Removendo o Ultimo valor da lista
    No* removido=0;

    removido= remover(inicio);

    printf("\n Ultimo valor removido: ");
    mostrar(inicio);

    return 0;
}