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
    int size = 0;

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
        printf("%i ", end->reg.key);
        end = end->nextElement;
    }
    printf("\"\n");
}

bool isEmpty(Stack* stack) {
    return (stack->top == NULL);
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