#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nod
{
    char letra;
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
Nod* criar_no(char valor);
void inserir_fim(Listad* l, char valor);
void mostrar(Listad* l);
Nod* remover(Listad* l, Nod* valor);
void inserir (Listad* l, char par, Nod* limite);
//void depois_remov1(Listad* l, char par1[]);
void troca1(Listad* l1, char par1[], char par2[], int qtd);
void depois_remov2(Listad* l, char par1[], char par2[]);

Listad* cria_listad(){
    Listad *L = (Listad*)malloc(sizeof(Listad));
    L->inicio = L->fim = NULL;
    return L;
}

Nod* criar_no(char valor){
    Nod* novo= (Nod*)malloc(sizeof(Nod));
    novo->letra= valor;
    novo->prox= NULL;
    novo->anterior=NULL;

    return novo;
}

void inserir_fim(Listad* l, char valor){
    Nod* novo = criar_no(valor);
    Nod* aux =NULL;

    if(l->inicio == NULL){
        l->inicio = novo;
        l->fim= novo;
    }
    else{
        aux=l->inicio;
        while(aux->prox!= NULL)  //achar o ultimo valor
            aux = aux->prox;
        aux->prox = novo;
        novo->anterior = aux;
        l->fim= novo;
    }
}

void mostrar(Listad* l){
    Nod* aux =l->inicio;
    while(aux!= NULL){
        printf(" %c", aux->letra);
        aux= aux->prox;
    }

}

void troca1(Listad* l1, char par1[], char par2[], int qtd){
    Nod* aux=l1->inicio, *aux2=NULL;
    int i=0, tam1=0, tam2=0, cont=0, j=0;

    tam1=strlen(par1);
    tam2=strlen(par2);
    while(aux!= NULL){
        for(i=0; i<tam1; i++){
            // printf("J: %d", j);
            // printf("AUX->PROX: %p", aux->prox);
            // printf("\n AUX: %c \t J: %d", aux->letra, j);
            if(aux != NULL && aux->letra == par1[j]){
                cont++;
                //printf("\n AUX: %c \t CONT: %d", aux->letra, cont);
                printf("\n CONT: %d  AUX: %c", cont, aux->letra);
                if(i<tam1-1){
                    j++;
                    if (aux->prox != NULL)
                        aux= aux->prox;
                }
            }
            //printf("\n I: %d, AUX: %c", i, aux->letra);
        }
        //printf("\n TAM: %d", tam1);
        if(cont == tam1){
            //printf("\n AUX_INSERIR: %c\n", aux->letra);
            for(j=0; j<tam2; j++){
                inserir(l1, par2[j], aux);
                aux = aux->prox;
            }
            // printf("\n");
            // mostrar(l1);
        }
        // if(qtd>1)
        // if(tam1>tam2)
        j=0;
        cont=0;
        aux = aux->prox;
    }
}


// void depois_remov1(Listad* l, char par1[]){
//     Nod* aux=l->inicio;
//     int tam1=0, cont=0, i=0, j=0;

//     tam1=strlen(par1);

//     while(aux!= NULL){
//         for(i=0; i<tam1; i++){
//             if(aux->letra == par1[j]){
//                 cont++;
//                 if(i<tam1-1){
//                     j++;
//                     aux= aux->prox;
//                 }
//             }

//         }
//         if(cont == tam1){
//             for(j=0; j<tam1; j++){
//                 aux = remover(l, aux);
//             }
//         }
//         cont=0;
//         aux= aux->prox;
//     }
// }


void depois_remov2(Listad* l, char par1[], char par2[]){
    Nod* aux=l->inicio, *aux2=NULL, *aux3=NULL;
    int tam1=0, tam2=0, cont=0, i=0, j=0, k=0, cont2=0;

    tam1=strlen(par1);
    tam2=strlen(par2);
    while(aux!= NULL){
        for(i=0; i<tam1; i++){
            //printf("\n I: %d", i);
            //printf("\n AUX: %c", aux->letra);
            if(aux != NULL && aux->letra == par1[j]){
                cont++;
                if(i<tam1-1){
                    j++;
                    if (aux->prox != NULL)
                        aux= aux->prox;
                }
            }
            aux3=aux->prox;
            //printf("\n AUX: %c, Aux_ANT: %c", aux->letra, aux->anterior->letra);
        }
        if (cont == tam1) {
            for (j=0; j<tam2; j++){
                if(aux3 != NULL && aux3->letra == par2[k]){
                    cont2++;
                    if(j<tam2-1){
                        k++;
                        if (aux3->prox != NULL)
                            aux3= aux3->prox;
                    }
                    //printf("CONT2: %d\n", cont2);
                }
            }
        }
        
        if(cont2 == tam2){
            aux2 = aux->prox;
            //printf("\n AUX: %c", aux->letra);
            for(j=0; j<tam1; j++){
                //printf("\n AUX_LIMITE: %c", aux->letra);
                aux = remover(l, aux);
                //printf("   AUX_REMOVE: %c", aux->letra);
            }
            if(aux==NULL)
                aux=aux2;
        }
        // if(qtd>1)
        //     j=0;
        j=0;
        k=0;
        cont2=0;
        cont=0;
        aux= aux->prox;
    }
}

Nod* remover(Listad* l, Nod* valor){
    Nod* aux = valor;
    Nod* aux2 = NULL;

    aux2= aux->anterior;
    if(aux !=NULL){

        if(aux == l->inicio){
            aux->prox->anterior=NULL;
            l->inicio = aux->prox;
            aux->prox = NULL;
        }
        else if(aux == l->fim){
            aux->anterior->prox=NULL;
            l->fim = aux->anterior;
            aux->anterior=NULL;
        }
        else{
            aux->anterior->prox=aux->prox;
            aux->prox->anterior = aux->anterior;
        }
        free(aux);
    }
    return aux2;
}

void inserir (Listad* l, char par, Nod* limite){
    Nod* aux= limite;
    Nod* novo = criar_no(par);

    if(aux!=NULL){

        if(aux == l->inicio){
            aux->anterior = novo;
            novo->prox = aux;
            l->inicio = novo;
        }
        else if(aux == l->fim){
            aux->prox = novo;
            novo->anterior = aux; 
            l->fim= novo;
        }
        else{
            novo->prox=aux->prox;
            novo->anterior=aux;
            aux->prox->anterior=novo;
            aux->prox=novo;
        }
    }
}

int main(){
    Listad *l1=NULL;
    Listad *l2=NULL;
    int qtd=0, tam=0, cont=0;
    char par1[100], par2[100], letra1[100], letra2[100];

    l1= cria_listad();
    l2= cria_listad();

    //getchar();
    scanf("%s", letra1);
    tam = strlen(letra1);
    for(int j=0; j<tam; j++){
        inserir_fim(l1, letra1[j]);
    }

    //getchar();
    scanf("%s", letra2);
    tam = strlen(letra2);
    for(int j=0; j<tam; j++){
        inserir_fim(l2, letra2[j]);
    }

    scanf("%d", &qtd);

    while(cont < qtd){
        getchar();
        scanf("%s", par1);
        getchar();
        scanf("%s", par2);

        troca1(l1, par1, par2, qtd);
        //printf("\n LISTAA:");
        // mostrar(l1);
        // printf("\n");
        depois_remov2(l1, par1, par2);
        troca1(l2, par2, par1, qtd);
        depois_remov2(l2, par2, par1);
        // mostrar(l2);
        // printf("\n");

        cont++;
    }
    mostrar(l1);
    printf("\n");
    mostrar(l2);
    printf("\n");
}