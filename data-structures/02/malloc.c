#include <stdio.h>
#include <malloc.h>

#define maxHeight 225

typedef struct
{
    int height;
    int weight;
} WeightHeight;

int mallocFunction1()
{
    // criando um ponteiro para y
    // cast de malloc para int*
    // malloc aloca um espaço de memória dito pelo sizeof(int)
    // sizeof(int) retorna o tamanho de um int em bytes
    int *y = (int *)malloc(sizeof(int));
    if (y == NULL) // Verifica se a alocação foi bem-sucedida
    {
        printf("Erro ao alocar memória\n");
        return 1;
    }
    // atribuindo 20 para o endereço de memória apontado por y
    *y = 20;

    // sizeof retorna o tamanho de um tipo em bytes (nesse casso 4 bytes)
    int z = sizeof(int);
    printf("*y=%i, z=%i\n", *y, z);

    free(y);
    return 0;
}

int mallocFunction2()
{
    WeightHeight *wH = (WeightHeight *)malloc(sizeof(WeightHeight));

    if (wH == NULL) // Verifica se a alocação foi bem-sucedida
    {
        printf("Erro ao alocar memória\n");
        return 1;
    }

    // atribuindo valores para os campos de wH
    wH->height = 73;
    wH->weight = 200;

    if (wH->height > maxHeight)
    {
        printf("Height is greater than %d\n", maxHeight);
    }
    else
    {
        printf("Height is less than %d\n", maxHeight);
    }

    free(wH);
    return 0;
}

int main()
{
    printf("Testando mallocFunction1:\n");
    if (mallocFunction1() != 0)
    {
        printf("mallocFunction1 falhou!\n");
    }

    printf("\nTestando mallocFunction2:\n");
    if (mallocFunction2() != 0)
    {
        printf("mallocFunction2 falhou!\n");
    }

    return 0;
}