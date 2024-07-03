#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct no
{
    char info;
    struct no *prox;
    
};
typedef struct no No;
typedef No Pilha;

Pilha* push(Pilha* p, char valor);
Pilha* insere_inicial(Pilha* inicio, char valor);
void mostrar(Pilha* inicio);
Pilha* criar_no(char valor);
int eh_pilha_vazia(Pilha *p);
Pilha* pop(Pilha **p);
No* remove_inicio(No **L);

Pilha* push(Pilha* p, char valor){
   p = insere_inicial(p,valor);
}

Pilha* insere_inicial(Pilha* inicio, char valor){
    Pilha* novo= criar_no(valor);

    if(inicio==NULL){//verificando se esta recebendo o valor
        inicio = novo; //pela primeria vez
    }
    else{
        novo->prox=inicio; //o proximo valor sera oq estava no inicio
        inicio = novo; //o valor novo se torna o inicio

    }
    return inicio;
}
Pilha* criar_no(char valor){
    Pilha* novo= (Pilha*)malloc(sizeof(Pilha));
    novo->info= valor;
    novo->prox= NULL;

    return novo;
}
void mostrar(Pilha* inicio){
    
    while(inicio != NULL){
        printf(" %c", inicio->info);
        inicio= inicio->prox;
    }
}
int eh_pilha_vazia(Pilha *p){
    int res = 1;
    if (p != NULL)
    {
        res=0;
    }
    return res;
}
Pilha* pop(Pilha **p){
    return remove_inicio(p);
}

No* remove_inicio(No **L){
    No *aux = *L;

    if (*L != NULL)
    {
        *L = (*L)->prox;
    }
    return aux;
}
int main(){
    Pilha *p = NULL, *p2=NULL;
    int n=0, aux=0, qtd=0, flag=0, cont_a=0, cont_b=0;
    char conta[1000];
    scanf("%d", &n);

    for(int j=0; j<n; j++){
        getchar();
        scanf("%s", conta);
        qtd= strlen(conta);
        cont_b = cont_a=0;
        for(int i=0; i<qtd; i++){
            if(conta[i]=='('){
                p=push(p, conta[i]);
                cont_a++;
            }
            else if(conta[i]==')'){
                free(pop(&p));
                cont_b++;
                flag =0;
            }
        }
        if(cont_b!=cont_a || conta[0]==')')
            flag=1;
        //printf("\n CONTA: %d CONTB:%d\n", cont_a, cont_b);
        if(!eh_pilha_vazia(p))
            flag=1;
        if(flag == 0)
            printf("correta\n");
        else
            printf("incorreta\n");

    }
    return 0;
}