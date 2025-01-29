#include <stdio.h>

// Pilha/Stack é uma estrutura linear LIFO

#define MAX_SIZE 50
#define true 1
#define false 0

typedef int KeyType;

typedef struct {
    KeyType key;
} Register;

typedef struct {
    Register element[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack* stack) {
    stack->top = -1;
}

int stackSize(Stack* stack) {
    return stack->top+1;
}

void printStack(Stack* stack) {
    printf("Stack: \" ");
    for(int i=stack->top; i>=0; i--) {
        printf("%i ", stack->element[i].key);
    }
    printf("\"\n");
} 

void push(Stack* stack, Register newElement) {
    if (stack->top >= MAX_SIZE-1) return false;
    stack->top = stack->top+1;
    stack->element[stack->top] = newElement;
    return true;
}

void pop(Stack* stack, Register* reg) {
    if(stack->top == -1) return false;
    *reg = stack->element[stack->top];
    stack->top = stack->top-1;
    return true;
}

void cleanStack(Stack* stack) {
    stack->top = -1;
}
