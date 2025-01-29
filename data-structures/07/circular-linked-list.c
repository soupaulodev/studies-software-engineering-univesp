#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

// Lista ligada circular com nó cabeça
// Ultimo elemento aponta para o primeiro

typedef int KeyType;

typedef struct {
    KeyType key;
} Register;

typedef struct TempRegister {
    Register reg;
    struct TempRegister* nextElement;
} Element;

typedef Element* Pointer;

typedef struct {
    Pointer head;
} List;

void initialize(List* list) {
    list->head = (Pointer) malloc(sizeof(Element));
    list->head->nextElement = list->head;
}

int size(List* list) {
    Pointer end = list->head->nextElement;
    int size = 0;

    while(end != list->head) {
        size++;
        end = end->nextElement;
    }
    return size;
}

void printList(List* list) {
    Pointer end = list->head->nextElement;

    printf("List: \"");
    while(end != list->head) {
        printf("%i ", end->reg.key);
        end = end->nextElement;
    }
    printf("\"\n");
}

Pointer sentinelSearch(List* list, KeyType targetKey) {
    Pointer next = list->head->nextElement;
    list->head->reg.key = targetKey;

    while (next->reg.key != targetKey) next = next->nextElement;
    if (next != list->head) return next;
    
    return NULL;
}

Pointer orderedSentinelSearch(List* list, KeyType targetKey) {
    Pointer next = list->head->nextElement;
    list->head->reg.key = targetKey;

    while (next->reg.key < targetKey) next = next->nextElement;
    if (next != list->head && next->reg.key == targetKey) return next;
    
    return NULL;
}

Pointer sequentialExcSearch(List* list, KeyType targetKey, Pointer* previous) {
    *previous = list->head;
    Pointer current = list->head->nextElement;
    list->head->reg.key = targetKey;

    while (current->reg.key < targetKey) {
        *previous = current;
        current = current->nextElement;
    }
    if (current != list->head && current->reg.key == targetKey) return current;
    
    return NULL;    
}

Pointer insertionOrdered(List* list, Register newElement) {
    Pointer previous, i;
    i = sequentialExcSearch(list, newElement.key, &previous);

    if (i != NULL) return false;
    i = (Pointer) malloc(sizeof(Element));
    i->reg = newElement;
    i->nextElement = previous->nextElement;
    previous->nextElement = i;
    return true;
}

Pointer removeElement(List* list, KeyType targetKey) {
    Pointer previous, i;
    i = sequentialExcSearch(list, targetKey, &previous);

    if(i == NULL) return false;
    previous->nextElement = i->nextElement;
    free(i);

    return true;
}

void clearList(List* list) {
    Pointer end = list->head->nextElement;

    while (end != list->head) {
        Pointer current = end;
        end = end->nextElement;
        free(current);
    }

    list->head->nextElement = list->head;
}
