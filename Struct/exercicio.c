#include "bibli.h"

int main(){
    Conta *contaCorrente;
    int tam=0;
    
    printf("\n Digite quantas contas deseja armazenar: ");
    scanf("%d", &tam);

    contaCorrente= alocar(tam);

    printf("\n Lendo os dados da primeria conta:");
    receber(contaCorrente, tam);

    printf("\n Mostrar Contas:");
    mostrar(contaCorrente, tam);

    //getch();
    //system("cls");

    printf("\n Tranferencia:");
    transferir(contaCorrente, tam);

    //Mostrando os novos valores
    printf("\n Contas:");
    mostrar(contaCorrente, tam);

    printf("\n Obrigado pela preferencia! \n");

    free(contaCorrente);

    return 0;
}

