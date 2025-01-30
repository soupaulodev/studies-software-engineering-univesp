#include <stdio.h>

void pointers()
{
    int x = 25; // Declara a variável x e atribui 25 a ela

    // int* indica que y é um ponteiro para um inteiro
    // &x retorna o endereço de memória de x, que é armazenado em y
    int *y = &x;

    // *y acessa o valor armazenado no endereço apontado por y (ou seja, x)
    // Portanto, essa linha modifica x para 30
    *y = 30;

    // Exibe os valores para verificação
    printf("Valor de x: %d\n", x);
    printf("Valor de *y: %d\n", *y);
}

int main()
{
    printf("Testando a função pointers():\n");
    pointers();
    return 0;
}
