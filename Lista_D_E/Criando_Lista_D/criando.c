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
Listad* insere_inicial(Listad *l, int valor);
void mostrar(Listad* l);
void mostrar_contra(Listad* l);

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

Listad* insere_inicial(Listad *l, int valor){
    Nod* novo= criar_no(valor);

    if(l->inicio==NULL){//verificando se esta recebendo o valor
        l->inicio = novo; //pela primeria vez
        l->fim = novo;
    }
    else{
        novo->prox=l->inicio; //prox valor sera o ex inicio
        l->inicio->anterior = novo; //o valor anteriror do ex inicio será o novo valor
        l->inicio = novo; 

    }
    return l;
}

void mostrar(Listad* l){
    while(l->inicio != NULL){
        printf(" %d", l->inicio->info);
        l->inicio= l->inicio->prox;
    }

}

void mostrar_contra(Listad* l){
    while(l->fim != NULL){
        printf(" %d", l->fim->info);
        l->fim= l->fim->anterior;
    }

}

int main(){
    Listad *l=NULL;

    l= cria_listad(l);

    l = insere_inicial(l, 6);
    l = insere_inicial(l, 5);
    l = insere_inicial(l, 7);
    l = insere_inicial(l, 9);

    mostrar(l);
    printf("\n");
    mostrar_contra(l);

    return 0;
}