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
No* buscar_valor(No* inicio, int limite);
void inserir(No* inicio, int valor, int limite);
No* remover_valor(No **inicio, int tirar);



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

No* buscar_valor(No* inicio, int limite){
    No* aux = inicio;

    while(aux != NULL && aux->info!= limite){
        aux = aux->prox;
    }
    return aux;
}

void inserir(No* inicio, int valor, int limite){
    No* novo = criar_no(valor);
    No* aux = inicio;
    //No* novo_valor=NULL;
    aux = buscar_valor(inicio, limite);
    if(aux!= NULL){ 
        novo->prox= aux->prox; //o prox de novo sera o prox de aux, ou seja, aux = [10|6], novo[3|20], FINAL= novo[3|6]  
        aux->prox = novo;    // aux = [10|3]
    }
    else{
        printf("\n Não existe esse valor \n");
    }
}

No* remover_valor(No **inicio, int tirar){
    No* aux, *anterior= NULL;

    aux = *inicio;
    if(aux != NULL){
        while(aux != NULL && aux->info!= tirar){
            anterior = aux;
            aux = aux -> prox;
        }
        if(aux != NULL){
            if(aux == *inicio){
                *inicio = aux->prox;
            }
            else{
                anterior->prox = aux->prox;
                aux->prox = NULL;
            }
        }
    }
    return aux;

}

int main(){
    No* inicio= NULL;

    inicio = insere_inicial(inicio, 6); //o primeiro valor sera o ultimo
    inicio = insere_inicial(inicio, 10);
    inicio = insere_inicial(inicio, 20);

    //Inserindo um valor
    int valor=3, limite= 10;

    inserir(inicio, valor, limite);

    mostrar(inicio);

    //Removendo um valor
    int removido=0, tirar=10;

    removido = remover_valor(&inicio, tirar);
    
    printf("\n Removendo o valor %d\n ", tirar);
    mostrar(inicio);
}