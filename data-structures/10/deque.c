#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

// Deque é uma estrutura de dados na qual os elementos podem ser inseridos ou excluidos de qualquer uma de suas extremidades (inicio ou fim).

typedef int KeyType;

typedef struct {
    KeyType key;
} Register;

typedef struct auxElement {
    Register reg;
    struct auxElement* previousElement;
    struct auxElement* nextElement;
} Element;

typedef Element* Pointer;

typedef struct {
    Pointer head;
} Deque;

void initialize(Deque* deque) {
    deque->head = (Pointer) malloc(sizeof(Element));
    deque->head->previousElement = deque->head;
    deque->head->nextElement = deque->head;
}

int dequeSize(Deque* deque) {
    Pointer end = deque->head->nextElement;
    int size = 0;

    while(end != deque->head) {
        size++;
        end = end->nextElement;
    }
    return size;
}

void printDequeEndToStart(Deque* deque) {
    Pointer end = deque->head->previousElement;
    printf("Deque End To Start: \"");
    while(end != deque->head) {
        printf("%i ", end->reg.key);
        end = end->previousElement;
    }
    printf("\"\n");
}

bool pushStart(Deque* deque, Register reg) {
    Pointer newElement = (Pointer) malloc(sizeof(Element));
    newElement->reg = reg;
    newElement->previousElement = deque->head;
    newElement->nextElement = deque->head->nextElement;
    deque->head->nextElement->previousElement = newElement;
    deque->head->nextElement = newElement;
    return true;
}

bool pushEnd(Deque* deque, Register reg) {
    Pointer newElement = (Pointer) malloc(sizeof(Element));
    newElement->reg = reg;
    newElement->nextElement = deque->head;
    newElement->previousElement = deque->head->previousElement;
    deque->head->previousElement->nextElement = newElement;
    deque->head->previousElement = newElement;
    return true;
}

bool popStart(Deque* deque, Register* reg) {
    if (deque->head->nextElement == deque->head) return false;
    Pointer target = deque->head->nextElement;
    *reg = target->reg;
    deque->head->nextElement = target->nextElement;
    target->nextElement->previousElement = deque->head;
    free(target);
    return true;
}

bool popEnd(Deque* deque, Register* reg) {
    if (deque->head->previousElement == deque->head) return false;
    Pointer target = deque->head->previousElement;
    *reg = target->reg;
    deque->head->previousElement = target->previousElement;
    target->previousElement->nextElement = deque->head;
    free(target);
    return true;
}

void clearDeque(Deque* deque) {
    Pointer end = deque->head->nextElement;

    while(end != deque->head) {
        Pointer target = end;
        end = end->nextElement;
        free(target);
    }
    deque->head->nextElement = deque->head;
    deque->head->previousElement = deque->head;
}

int main() {
    Deque deque;
    initialize(&deque);

    Register reg1 = {10};
    Register reg2 = {20};
    Register reg3 = {30};

    pushStart(&deque, reg1);
    pushEnd(&deque, reg2);
    pushStart(&deque, reg3);

    printDequeEndToStart(&deque);

    Register poppedReg;
    if (popStart(&deque, &poppedReg)) {
        printf("Popped from start: %i\n", poppedReg.key);
    }

    if (popEnd(&deque, &poppedReg)) {
        printf("Popped from end: %i\n", poppedReg.key);
    }

    printDequeEndToStart(&deque);

    clearDeque(&deque);

    return 0;
}