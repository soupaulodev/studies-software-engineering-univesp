#include <stdio.h>
#include <stdbool.h>

// Queues/Filas são estruturas FIFO

#define MAX_SIZE 50

typedef int KeyType;

typedef struct
{
    KeyType key;
} Register;

typedef struct
{
    Register element[MAX_SIZE];
    int start;
    int numberOfElements;
} Queue;

void initializeQueue(Queue *q)
{
    q->start = 0;
    q->numberOfElements = 0;
}

int sizeQueue(Queue *q)
{
    return q->numberOfElements;
}

void printQueue(Queue *q)
{
    printf("Queue: \" ");
    int i = q->start;
    int temp;
    for (temp = 0; temp < q->numberOfElements; temp++)
    {
        printf("%i ", q->element[i].key);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\"\n");
}

bool insertElement(Queue *q, Register reg)
{
    if (q->numberOfElements >= MAX_SIZE)
        return false;
    int position = (q->start + q->numberOfElements) % MAX_SIZE;
    q->element[position] = reg;
    q->numberOfElements++;
    return true;
}

bool removeElement(Queue *q, Register *reg)
{
    if (q->numberOfElements == 0)
        return false;
    *reg = q->element[q->start];
    q->start = (q->start + 1) % MAX_SIZE;
    q->numberOfElements--;
    return true;
}

void clearQueue(Queue *q)
{
    initializeQueue(q);
}

int main()
{
    Queue q;
    initializeQueue(&q);

    Register reg1 = {10};
    Register reg2 = {20};
    Register reg3 = {30};

    insertElement(&q, reg1);
    insertElement(&q, reg2);
    insertElement(&q, reg3);

    printQueue(&q);

    Register removedReg;
    if (removeElement(&q, &removedReg))
    {
        printf("Elemento removido: %i\n", removedReg.key);
    }

    printQueue(&q);

    clearQueue(&q);
    printQueue(&q);

    return 0;
}