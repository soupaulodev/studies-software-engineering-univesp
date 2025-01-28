#include <stdio.h>
#include <malloc.h>

int mallocFunction1() {
    // criando um ponteiro para y
    // cast de malloc para int*
    // malloc aloca um espaço de memória dito pelo sizeof(int)
    // sizeof(int) retorna o tamanho de um int em bytes
    int* y = (int*)malloc(sizeof(int));

    // atribuindo 20 para o endereço de memória apontado por y
    *y = 20;

    // sizeof retorna o tamanho de um tipo em bytes (nesse casso 4 bytes)
    int z = sizeof(int);
    printf("*y=%i, z=%i\n", *y, z);
    return 0;
}

#define maxHeight 225

typedef struct {
    int height;
    int weight;
} WeightHeight;

int mallocFunction2() {
    WeightHeight* wH = (WeightHeight*) malloc(sizeof(WeightHeight));
    
    // atribuindo valores para os campos de wH
    wH->height = 73;
    wH->weight = 200;

    return 0;
}