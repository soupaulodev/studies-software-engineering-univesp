#include <stdio.h>
#include <stdbool.h>

// Pilha/Stack é uma estrutura linear LIFO

#define MAX_SIZE 50

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

bool push(Stack* stack, Register newElement) {
    if (stack->top >= MAX_SIZE - 1) return false;
    stack->top = stack->top+1;
    stack->element[stack->top] = newElement;
    return true;
}

bool pop(Stack* stack, Register* reg) {
    if(stack->top == -1) return false;
    *reg = stack->element[stack->top];
    stack->top = stack->top-1;
    return true;
}

void clearStack(Stack* stack) {
    stack->top = -1;
}

int main() {
    Stack stack;
    initialize(&stack);

    Register reg1 = {10};
    Register reg2 = {20};
    Register reg3 = {30};

    push(&stack, reg1);
    push(&stack, reg2);
    push(&stack, reg3);

    printStack(&stack);

    Register poppedReg;
    if (pop(&stack, &poppedReg)) {
        printf("Popped: %i\n", poppedReg.key);
    }

    printStack(&stack);

    clearStack(&stack);

    printStack(&stack);

    return 0;
}