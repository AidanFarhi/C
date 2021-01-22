#include <stdio.h>
#include <stdlib.h>

/* Prototypes */
void push(int item);
int pop();
void constructor();
void resize(int new_size);

/* Global Variables */
int *stack;
int head;
int capacity;

/* Test client */
int main(void)
{
    constructor();
    push(100);
    push(200);
    push(300);
    push(400);
    push(500);
    push(600);
    push(700);
    push(800);
    printf("Item: %i\n", pop());
    printf("Item: %i\n", pop());
    printf("Item: %i\n", pop());
    printf("Item: %i\n", pop());
    printf("Item: %i\n", pop());
    printf("Item: %i\n", pop());
    printf("Item: %i\n", pop());
    free(stack);
}

void constructor()
{
    stack = malloc(sizeof(int) * 2);
    head = 0;
    capacity = 2;
}

void push(int item)
{
    if (head == capacity)
    {
        resize(capacity * 2);
    }
    stack[head++] = item;
}

int pop()
{
    int item = stack[--head];
    if (head > 0 && head == capacity / 4)
    {
        resize(capacity / 2);
    }
    return item;
}

void resize(int new_size)
{
    printf("Resizing to size: %i\n", new_size);
    capacity = new_size;
    stack = realloc(stack, new_size);
}