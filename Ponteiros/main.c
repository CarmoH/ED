#include <stdio.h>
#include <stdlib.h>
void troca(int *v1, int *v2){ //(*) atribui os valores da variável
    int aux=0;

    aux = *v1;
    *v1 = *v2;
    *v2 = aux;

}

//===============================
int main()
{
    int v1=10, v2=20;

    troca(&v1, &v2); // (&)endereço do ponteiro

        printf("\n Novo valor de v1: %d", v1);

        printf("\n Novo valor de V2: %d", v2);
    return 0;
}
