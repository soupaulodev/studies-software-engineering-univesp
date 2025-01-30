#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

// A instância tem um ponteiro para o primeiro elemento da lista
// Cada elemento indica seu sucessor
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

int getListSize(LinkedList* list) {
    Pointer end = list->start;
    int size = 0;
    
    while(end != NULL) {
        size++;
        end = end->nextElement;
    }
    return size;
}

// void printList(LinkedList* list) {
//     Pointer end = list->start;
    
//     printf("List: \" ");
//     while(end != NULL) {
//         printf("%i ", end->reg.key);
//         end = end->nextElement;
//     }
//     printf("\"\n");
// }


void printList(LinkedList* list) {
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
        next = next->nextElement;
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

    if (i == NULL) return false;
    if (previous == NULL) list->start = i->nextElement;
    else previous->nextElement = i->nextElement;

    free(i);
    return true;
}

void clearList(LinkedList* list) {
    Pointer end = list->start;

    while (end != NULL) {
        Pointer current = end;
        end = end->nextElement;
        free(current);
    }
    list->start = NULL;
}

int main() {
    LinkedList list;
    initialize(&list);

    Register reg1 = {10};
    Register reg2 = {20};
    Register reg3 = {30};

    
    insertionOrdered(&list, reg1);
    insertionOrdered(&list, reg2);
    insertionOrdered(&list, reg3);

    printList(&list);

    Pointer found = searchElement(&list, 20);
    if (found != NULL) {
        printf("Element 20 found!\n");
    }

    removeElement(&list, 20);

    printList(&list);

    clearList(&list);

    printList(&list);

    return 0;
}