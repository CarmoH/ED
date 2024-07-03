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

Listad* cria_listad();
Nod* criar_no(int valor);
void* insere_inicial(Listad *l, int valor);
void mostrar(Listad* l);
void* reverter(Listad* l, int tam);

Listad* cria_listad(){
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

void* insere_inicial(Listad *l, int valor){
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
}

void mostrar(Listad* l){
    Nod* aux =l->inicio;
    while(aux!= NULL){
        printf(" %d", aux->info);
        aux= aux->prox;
    }

}

void* reverter(Listad* l, int tam){
    Nod* aux1= l->inicio, *aux2= l->fim;
    int cont=0, ou=0;
    if(tam%2 == 0){
        while (cont < (tam/2)){
            ou= aux1->info;
            aux1->info = aux2->info;
            aux2->info = ou;

            cont++;
            aux1= aux1->prox;
            aux2= aux2->anterior;
        }
        
    }
    else{
        while(aux1 != aux2){
            ou= aux1->info;
            aux1->info = aux2->info;
            aux2->info = ou;

            aux1= aux1->prox;
            aux2= aux2->anterior;
        }
    }

}

int main(){
    Listad *l=NULL;

    l= cria_listad();

    insere_inicial(l, 6);
    insere_inicial(l, 5);
    insere_inicial(l, 7);
    //insere_inicial(l, 9);
    int tam=3;
    mostrar(l);

    reverter(l, tam);
    printf("\n");
    mostrar(l);


    return 0;
}