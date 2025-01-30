#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

// Stack/Pilha dynamica
// Cada elemento aponta para seu sucessor (quem está "abaixo") 

#define true 1
#define false 0

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
    Pointer top;
} Stack;

void initialize(Stack* stack) {
    stack->top = NULL;
}

int stackSize(Stack* stack) {
    Pointer end = stack->top;
    int size;

    while(end != NULL) {
        size++;
        end = end->nextElement;
    }
    return size;
}

void printStack(Stack* stack) {
    Pointer end = stack->top;

    printf("Stack: \" ");
    while (end != NULL) {
        printf("%i ", end);
        end = end->nextElement;
    }
    printf("\"\n");
}

bool isEmpty(Stack* stack) {
    if (stack->top == NULL) return true;
    return false;
}

bool push(Stack* stack, Register newElement) {
    Pointer new = (Pointer) malloc(sizeof(Element));
    new->reg = newElement;
    new->nextElement = stack->top;
    stack->top = new;
    return true;
}

bool pop(Stack* stack, Register* reg) {
    if(stack->top == NULL) return false;
    *reg = stack->top->reg;
    Pointer target = stack->top;
    stack->top = stack->top->nextElement;
    free(target);
    return true;
}

void clearStack(Stack* stack) {
    Pointer target;
    Pointer position = stack->top;

    while(position != NULL) {
        target = position;
        position = position->nextElement;
        free(target);
    }
    stack->top = NULL;
}