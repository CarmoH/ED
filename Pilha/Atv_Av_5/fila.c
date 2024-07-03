#include <stdio.h>
#include <stdlib.h>

struct nod{
    int info;
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

//prototipos de lista
Listad* criar_listad();
Nod* cria_nod(int info);
void insere_inicio_listad(int info, Listad *L);
void insere_fim_listad(int info, Listad *L);
void mostra_listad(Listad *L);
Nod* remove_inicio(Listad *L);
int inicio(Listad *L);//consulta inicio 
Listad* libera_listad(Listad *L);

typedef Listad Fila;
//prototipos de fila
Fila* cria_fila();
void enqueue(Fila*, int);
Nod* dequeue(Fila*);
int consulta_inicio(Fila*);
int fila_vazia(Fila*);
Fila* libera_fila(Fila*);

Fila* cria_fila(){
    Fila* f = criar_listad();
    return f;
}

Listad* cria_listad(Listad* l){
    Listad *L = (Listad*)malloc(sizeof(Listad));
    L->ini = L->fim = NULL;
    return L;
}

void enqueue(Fila *f, int valor){
    insere_fim_listad(valor,f);
}
Nod* dequeue(Fila *f){
    return remove_inicio(f);
}
int consulta_inicio(Fila*f){
    return inicio(f);
}
int fila_vazia(Fila* f){
    int res = 1;
    if (f->ini == NULL)
    {
        res = 0;
    }
    return res;
}
Fila* libera_fila(Fila *f){
    libera_listad(f);
    return NULL;
}


Nod* cria_nod(int info){
    Nod *novo= (Nod*)malloc(sizeof(Nod));
    novo->info = info;
    novo->ant = novo->prox = NULL;
    return novo;
}


void insere_fim_listad(int info, Listad *L){
    Nod* novo = cria_nod(info);

    if (L->ini==NULL)
    {
        L->ini = L->fim = novo;
    }
    else
    {
        novo->ant = L->fim;
        L->fim->prox = novo;
        L->fim = novo;
    }
}

void mostra_listad(Listad *L){
    Nod *aux = L->ini;

    while (aux != NULL)
    {
        printf("%d ", aux->info);
        aux = aux->prox;
    }
}
Listad* libera_listad(Listad *L){
    Nod* aux;

    while(L->ini != NULL)
    {
        aux = L->ini;
        L->ini = L->ini->prox;
        free(aux);
    }
    free(L);
    return NULL;
}

Nod* remove_inicio(Listad *L){
    Nod* aux = NULL;
    if (L != NULL && L->fim != NULL) //caso haja elemento
    {
        aux = L->ini;
        if (L->ini == L->fim)
        {   
            L->ini = L->fim = NULL;
        }
        else
        {
            L->ini = L->ini->prox;
            L->ini->ant = NULL;
        }
    }
    return aux;
}
int inicio(Listad *L){   //consulta inicio 
    int valor_inicio = -1;
    if (L != NULL && L->fim != NULL) //caso haja elemento
    {
        valor_inicio = L->ini->info;
    }
    return valor_inicio;
}
int main(){
    Fila *f = cria_fila(), *f_final=cria_fila();
    int n=0, valor=0, m=0, saiu=0;

    scanf("%d", &n);

    for(int i=0; i<n;i++){
        scanf("%d", &valor);
        enqueue(f, valor);
    }
    
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        Fila *aux = f;
        scanf("%d", &saiu);
        for(int j=0; i<n;i++){
            if(aux->ini->info != saiu){
                enqueue(f_final, aux->ini->info);
            }
            aux->ini=aux->ini->prox;
        }
    }

    mostra_listad(f_final);


    return 0;
}
