#include "bibli.h"

Conta* alocar(int tam){
    Conta *contaCorrente = (Conta*)malloc(sizeof(Conta));

    return contaCorrente;
}

void receber(Conta contaCorrente[], int tam){
    int i=0;
    for(i=0; i < tam; i++){
        client(i, contaCorrente);
        printf("\n Numero da conta: ");
        scanf("%d", &contaCorrente[i].num);
        printf("\n Seu saldo: ");
        scanf("%f", &contaCorrente[i].saldo);
    }
}

void mostrar(Conta contaCorrente[], int tam){
    for(int i=0; i < tam; i++){
        printf("\n Usuario: %s", contaCorrente[i].correntista.nome);
        printf("\n CPF: %s", contaCorrente[i].correntista.cpf);
        printf("\n Idade: %d", contaCorrente[i].correntista.idade);
        printf("\n Rua: %s", contaCorrente[i].correntista.endcasa.rua);
        printf("\n Numero: %d", contaCorrente[i].correntista.endcasa.numero);
        printf("\n Bairro: %s", contaCorrente[i].correntista.endcasa.bairro);
        printf("\n Cidade: %s", contaCorrente[i].correntista.endcasa.cidade);
        printf("\n Conta: %d", contaCorrente[i].num);
        printf("\n Saldo: %.2f", contaCorrente[i].saldo);
        printf("\n");
    }
}

void transferir(Conta contaCorrente[], int tam){
    int transf=0, nume=0, novo=0, aux=0;
    float valor=0;
    printf("\n Digite o numero da conta que vai transferir: ");
    scanf("%d", &transf);
    printf("\n Digite o numero da conta para qual deseja transferir: ");
    scanf("%d", &nume);

    printf("\n Digite o valor a ser transferido: ");
    scanf("%f", &valor);

    for(int i=0; i < tam; i++){
        if(contaCorrente[i].num == nume){
            contaCorrente[i].saldo = contaCorrente[i].saldo + valor;
        }
        if(contaCorrente[i].num == transf){
            contaCorrente[i].saldo = contaCorrente[i].saldo - valor;
        }
    }
}

void client(int i, Conta contaCorrente[]){
    printf("\n Nome: ");
    fflush(stdin);
    gets(contaCorrente[i].correntista.nome);
    printf("\n Seu CPF: ");
    fflush(stdin);
    scanf("%s", &contaCorrente[i].correntista.cpf);
    printf("\n Sua idade: ");
    scanf("%d", &contaCorrente[i].correntista.idade);

    ende(i, contaCorrente);
}

void ende(int i, Conta contaCorrente[]){
    printf("\n Rua: ");
    fflush(stdin);
    gets(contaCorrente[i].correntista.endcasa.rua);
    printf("\n Numero da casa: ");
    fflush(stdin);
    scanf("%d", &contaCorrente[i].correntista.endcasa.numero);
    printf("\n Bairro: ");
    fflush(stdin);
    scanf("%s", &contaCorrente[i].correntista.endcasa.bairro);
    printf("\n Cidade: ");
    fflush(stdin);
    scanf("%s", &contaCorrente[i].correntista.endcasa.cidade);
}
