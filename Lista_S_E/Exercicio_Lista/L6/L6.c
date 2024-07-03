/* Implemente uma função q recebe um vetor com n valores inteiros e construa uma lsita
encadeada armazenando os elementos do vetor nos nós da lista*/

#include <stdio.h>
#include <stdlib.h>

struct no
{
    int info;
    struct no *prox;
    
};
typedef struct no No;

No* criar_no(int valor);
No* insere_inicial(No* inicio, int valor);
void mostrar(No* inicio);
No* lista(int n, int *vetor);

No* lista(int n, int *vetor){
    int i=0, aux=0;
    No* novo = NULL, *lista=NULL;
    printf("\n Digite o tamanho do vetor: ");
    scanf("%d", &n);

    vetor = (int*)malloc(n*sizeof(int));

    for(i=0; i<n; i++){
        printf("\n Digte um tamanho para %d: ",i+1);
        scanf("%d", &vetor[i]);
    }
    i=0;
    while(i<n){
        aux = vetor[i];
        novo = insere_inicial(novo, aux);
        lista = novo;
        i++;
    }

    return lista;
}


No* criar_no(int valor){
    No* novo= (No*)malloc(sizeof(No));
    novo->info= valor;
    novo->prox= NULL;

    return novo;
}

No* insere_inicial(No* inicio, int valor){
    No* novo=criar_no(valor);
    

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
    No* inicio = NULL;
    int *vetor, n=0, aux=0, i=0;

/*
    printf("\n Digite o tamanho do vetor: ");
    scanf("%d", &n);

    vetor = (int*)malloc(n*sizeof(int));

    for(i=0; i<n; i++){
        printf("\n Digte um tamanho para %d: ",i+1);
        scanf("%d", &vetor[i]);
    }
    i=0;
    while (i<n)
    {
        aux = vetor[i];
        inicio=insere_inicial(inicio, aux);
        i++;
    }
*/

    inicio = lista(n, vetor);
    mostrar(inicio);

    return 0;
}