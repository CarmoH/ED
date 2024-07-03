#ifndef BIBLI_H_INCLUDED
#define BIBLI_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

struct endereco {
	char rua[100];
	int numero;
	char bairro[100];
	char cidade[50];
};

struct cliente{
    char nome[30];
	char cpf[11];
	int idade;
    struct endereco endcasa;
};

struct conta {
    int num;
    float saldo;
    struct cliente correntista;
};
typedef struct conta Conta;

Conta* alocar(int tam);
void receber(Conta contaCorrente[], int tam);
void mostrar(Conta contaCorrente[], int tam);
void transferir(Conta contaCorrente[], int tam);
void client(int i, Conta contaCorrente[]);
void ende(int i, Conta contaCorrente[]);

#endif