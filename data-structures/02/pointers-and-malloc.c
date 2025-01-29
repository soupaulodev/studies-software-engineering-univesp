#include <stdio.h>

int pointers() {
    int x = 25; // aloca memoria para x e atribui 25 a ele

    // int* indica que o valor de y será uma referencia/endereço de memória
    // &x retorna o endereço de x
    int* y = &x; // aloca memoria para y e atribui o endereco de x a ele
    
    // *y indica que o valor de y é uma referencia/endereço de memória
    // então *y acessa o valor de x (25) e atribui 30 a ele
    *y = 30; // atribui 30 ao valor de x

    return 0;
}