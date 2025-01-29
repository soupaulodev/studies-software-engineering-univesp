#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

// A instância tem um ponteiro para o primeiro elemento da lista
// Cada elemento indica seu sucessor

typedef int bool;
typedef int KeyType;

typedef struct {
    KeyType key;
} Register;

typedef struct aux {
    Register reg;
    struct aux* nextElement;
} Element;

typedef Element* Pointer;

typedef struct {
    Pointer start;
} LinkedList;

void initialize(LinkedList* list) {
    list->start = NULL;
}

void getListSize(LinkedList* list) {
    Pointer end = list->start;
    int size = 0;
    
    while(end != NULL) {
        size++;
        end = end->nextElement;
    }
    return size;
}

int printList(LinkedList* list) {
    Pointer end = list->start;
    
    printf("List: \" ");
    while(end != NULL) {
        printf("%i ", end->reg.key);
        end->nextElement;
    }
    printf("\"\n");
}

Pointer searchElement(LinkedList* list, KeyType targetKey) {
    Pointer next = list->start;

    while(next != NULL && next->reg.key < targetKey) {
        next->nextElement;
    }
    if (next != NULL && next->reg.key == targetKey) return next;
    
    return NULL;
}

Pointer sequentialExcSearch(LinkedList* list, KeyType targetKey, Pointer* previous) {
    *previous = NULL;
    Pointer current = list->start;

    while((current != NULL) && (current->reg.key<targetKey)) {
        *previous = current;
        current = current->nextElement;
    }
    if ((current != NULL) && current->reg.key == targetKey) return current;

    return NULL;
}

bool insertionOrdered(LinkedList* list, Register newElement) {
    KeyType key = newElement.key;
    Pointer previous, i;

    i = sequentialExcSearch(list, key, &previous);
    if(i!=NULL) return false;
    i = (Pointer) malloc(sizeof(Element));
    i->reg = newElement;

    if (previous == NULL) {
        i->nextElement = list->start;
        list->start = i;
    } else {
        i->nextElement = previous->nextElement;
        previous->nextElement = i;
    }

    return true;
}

bool removeElement(LinkedList* list, KeyType key) {
    Pointer previous, i;
    i = sequentialExcSearch(list, key, &previous);

    if (i == NULL) return NULL;
    if (previous == NULL) list->start = i->nextElement;
    else previous->nextElement = i->nextElement;

    free(i);
    return true;
}

void cleanList(LinkedList* list) {
    Pointer end = list->start;

    while (end != NULL) {
        Pointer current = end;
        end = end->nextElement;
        free(current);
    }
    list->start = NULL;
}