#include <stdio.h>
#include <stdlib.h>

struct nod{
    int info;
    int min;
    struct nod *prox;
    struct nod *ant;
};
typedef struct nod Nod;

struct listad
{
    Nod* ini;
    Nod* fim;
};
typedef struct listad Listad;
typedef Listad Fila;


Fila* cria_fila();
Fila* cria_listad();
void enqueue(Fila *f, int valor, int min);
Nod* dequeue(Fila *f);
Nod* cria_nod(int info, int minu);
void insere_fim_listad(int info, int min, Listad *L);
Nod* remove_inicio(Listad *L);
int inicio_info(Listad *L);
int inicio_min(Listad *L);
int consulta_info(Fila*f);
int consulta_min(Fila*f);

Fila* cria_fila(){
    Fila *f = cria_listad();
    return f;
}

Fila* cria_listad(){
    Listad *L = (Listad*)malloc(sizeof(Listad));
    L->ini = L->fim = NULL;
    return L;
}

void enqueue(Fila *f, int valor, int min){
    insere_fim_listad(valor, min, f);
}

Nod* dequeue(Fila *f){
    return remove_inicio(f);
}

Nod* cria_nod(int info, int minu){
    Nod *novo= (Nod*)malloc(sizeof(Nod));
    novo->info = info;
    novo->min = minu;
    novo->ant = novo->prox = NULL;
    return novo;
}

void insere_fim_listad(int info, int min, Listad *L){
    Nod* novo = cria_nod(info, min);

    if (L->ini==NULL){
        L->ini = L->fim = novo;
    }
    else{
        novo->ant = L->fim;
        L->fim->prox = novo;
        L->fim = novo;
    }
}

Nod* remove_inicio(Listad *L){
    Nod* aux = NULL;
    if (L != NULL && L->fim != NULL){
        aux = L->ini;
        if (L->ini == L->fim){
            L->ini = L->fim = NULL;
        }
        else{
            L->ini = L->ini->prox;
            L->ini->ant = NULL;
        }
    }
    return aux;
}

int consulta_info(Fila*f){
    return inicio_info(f);
}
int consulta_min(Fila*f){
    return inicio_min(f);
}

int inicio_info(Listad *L){
    int valor_inicio = -1;
    if (L != NULL && L->fim != NULL){
        valor_inicio = L->ini->info;
    }
    return valor_inicio;
}
int inicio_min(Listad *L){
    int valor_inicio = -1;
    if (L != NULL && L->fim != NULL){
        valor_inicio = L->ini->min;
    }
    return valor_inicio;
}

int main(){
    Fila *f = cria_fila();
    int c=0, p=0, chegada=0, min=0, tempo=0, menor=0, cont=0, aux=0, k=0;

    scanf("%d %d", &c, &p);
    int caixa[c];
    for(int i=0; i<p; i++){
        scanf("%d %d", &chegada, &min);
        enqueue(f, chegada, min);
    }
    for(int i=0; i<c; i++){
        caixa[i]=0;
    }
    while(f->ini!=NULL){
        chegada= consulta_info(f);
        tempo= consulta_min(f);
        aux = caixa[0];
        for(int j=0; j<c; j++){
            if(aux>=caixa[j]){
                menor = caixa[j];
                k=j;
                //caixa[j] = caixa[j]+tempo;
            }
        }
        caixa[k] = caixa[k]+tempo;
        menor = menor-chegada;
        if(menor >= 20)
            cont++;
        dequeue(f);
    }

    printf("%d\n", cont);
    return 0;
}