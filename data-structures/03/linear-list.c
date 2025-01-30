#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Listas lineares é uma estrutura de dados na qual cada elemento é precedido por um elemento e sucedido por outro, exceto o primeiro e o último.
// Listas Lineares sequenciais é uma lista linear na qual os elementos são armazenados em sequência na memória.

#define MAX_SIZE 50

typedef int KeyType;

typedef struct {
    KeyType key;
} Register;

typedef struct {
    Register elements[MAX_SIZE];
    int numberOfElements;
} SequentialList;

// Inicializa uma lista na memória
void initializeList(SequentialList* list) {
    list->numberOfElements = 0;
}

// Retorna o número de elementos na lista
int getListSize(SequentialList* list) {
    return list->numberOfElements;
}

// Imprime todos os elementos da lista
void printList(SequentialList* list) {
    printf("List: \" ");
    for (int i = 0; i < list->numberOfElements; i++) {
        printf("%i ", list->elements[i].key);
    }
    printf("\"\n");
}

// Realiza uma busca sequencial na lista
int sequentialSearch(SequentialList* list, KeyType targetKey) {
    for (int i = 0; i < list->numberOfElements; i++) {
        if (targetKey == list->elements[i].key) {
            return i; // Retorna a posição do elemento encontrado
        }
    }
    return -1; // Retorna -1 se o elemento não for encontrado
}

// Realiza uma busca com sentinela na lista
int sentinelSearch(SequentialList* list, KeyType targetKey) {
    if (list->numberOfElements >= MAX_SIZE) return -1;  // Verifica se há espaço para a sentinela

    int i = 0;
    list->elements[list->numberOfElements].key = targetKey;  // Adiciona a sentinela
    while (list->elements[i].key != targetKey) {
        i++;
    }
    if (i == list->numberOfElements) {
        return -1;  // Elemento não encontrado
    }
    return i;  // Retorna a posição do elemento encontrado
}

// Realiza uma busca binária na lista
int binarySearch(SequentialList* list, KeyType k) {
    int lt = 0;
    int rt = list->numberOfElements - 1;
    
    while(lt <= rt) {
        int mid = lt + ((rt - lt) >> 1); // Uso de deslocamento por 1 para divisão por 2

        if (list->elements[mid].key == k) return mid;
        if (list->elements[mid].key < k) lt = mid + 1;
        else rt = mid - 1;
    }
    return -1;
}

// Adiciona um elemento na lista em uma posição específica
bool insertElement(SequentialList* list, Register newElement, int position) {
    if (list->numberOfElements == MAX_SIZE || position < 0 || position > list->numberOfElements) {
        return false; // Retorna falso se a lista estiver cheia ou a posição for inválida
    }
    for (int j = list->numberOfElements; j > position; j--) {
        list->elements[j] = list->elements[j - 1]; // Desloca os elementos para a direita
    }
    list->elements[position] = newElement;
    list->numberOfElements++;
    return true;
}

// Adiciona um elemento na lista de forma ordenada
bool insertSortElement(SequentialList* list, Register newElement) {
    if(list->numberOfElements >= MAX_SIZE) return false;
    int position = list->numberOfElements;

    while(position > 0 && list->elements[position-1].key > newElement.key) {
        list->elements[position] = list->elements[position-1];
        position--;
    }

    list->elements[position] = newElement;
    list->numberOfElements++;
    return true;
}

// Remove um elemento da lista com base na chave
bool removeElement(SequentialList* list, KeyType targetKey) {
    int position = sequentialSearch(list, targetKey);
    if (position == -1) {
        return false; // Retorna falso se o elemento não for encontrado
    }
    for (int j = position; j < list->numberOfElements - 1; j++) {
        list->elements[j] = list->elements[j + 1]; // Desloca os elementos para a esquerda
    }
    list->numberOfElements--;
    return true;
}

// Remove um elemento da lista com base na chave usando busca binaria para encontrar
bool binaryRemoveElement(SequentialList* list, KeyType targetKey) {
    int position, i;
    position = binarySearch(list, targetKey);

    if (position == -1) return false;

    for(i=position; i < list->numberOfElements-1; i++) {
        list->elements[i] = list->elements[i+1];
    }
    list->numberOfElements--;
    return true;
}

// Reinicializa a lista, removendo todos os elementos
void clearList(SequentialList* list) {
    list->numberOfElements = 0;
}

int main() {
    // Declaração de uma lista linear sequencial
    SequentialList list;
    initializeList(&list);

    // Exemplo de uso das funções
    Register reg1 = {10};
    Register reg2 = {20};
    insertElement(&list, reg1, 0);
    insertElement(&list, reg2, 1);

    printList(&list);

    int position = sequentialSearch(&list, 20);
    if (position != -1) {
        printf("Elemento 20 encontrado na posição %d\n", position);
    } else {
        printf("Elemento 20 não encontrado\n");
    }

    removeElement(&list, 10);
    printList(&list);

    clearList(&list);
    printList(&list);

    return 0;
}