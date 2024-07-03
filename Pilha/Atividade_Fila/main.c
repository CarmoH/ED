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
typedef Listad Fila;


Fila* cria_fila();
Fila* cria_listad();
void enqueue(Fila *f, int valor);
Nod* dequeue(Fila *f);
Nod* cria_nod(int info);
void insere_fim_listad(int info, Listad *L);
void mostra_listad(Listad *L);
Nod* remove_inicio(Listad *L);
int inicio(Listad *L);
int consulta_inicio(Fila*f);


Fila* cria_fila(){
    Fila *f = cria_listad();
    return f;
}

Fila* cria_listad(){
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

Nod* remove_inicio(Listad *L){
    Nod* aux = NULL;
    if (L != NULL && L->fim != NULL){
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

int consulta_inicio(Fila*f){
    return inicio(f);
}

int inicio(Listad *L){
    int valor_inicio = -1;
    if (L != NULL && L->fim != NULL)
    {
        valor_inicio = L->ini->info;
    }
    return valor_inicio;
}
int main(){
    Fila *f = cria_fila(), *f_final=cria_fila();
    int n=0, valor=0, m=0, flag=0;

    scanf("%d", &n);

    for(int i=0; i<n;i++){
        scanf("%d", &valor);
        enqueue(f, valor);//inserindo na lista
    }

    scanf("%d", &m);
    int vetor[m];
    for(int i=0; i<m; i++){
        scanf("%d", &vetor[i]);
    }
    for(int j=0; j<n;j++){
        for(int i=0; i<m; i++){
            if(vetor[i]==consulta_inicio(f))//ve se o topo da lista é igual a algum vetor
                flag=1; // se for flag é 1
        }
        if(flag==0) // caso o topo n for igual a nenhum vetor
            printf("%d ", consulta_inicio(f)); // mostra
        flag=0;
        dequeue(f); // e remove
    }
    printf("\n");

    return 0;
}
