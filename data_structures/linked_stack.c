#include <stdio.h>
#include <stdlib.h>

/* Define Node */
typedef struct Node 
{
    int data;
    struct Node *next;
}
Node;

/* Prototypes */
void push(int item);
int pop();
void show_items();
void cleanup();

/* Global variables */
Node *head = NULL;

int main(void)
{
    for (int i = 100; i <= 1000; i += 100)
    {
        push(i);
    }
    show_items();
    for (int j = 0; j < 10; j++){
        printf("Item: %i\n", pop());
    }
}

void push(int item)
{
    Node *n = malloc(sizeof(Node));
    n->data = item;
    n->next = head;
    head = n;
}

int pop()
{
    if (head == NULL)
    {
        return -1;
    }
    Node *t = head;
    int data = head->data;
    head = head->next;
    free(t);
    return data;
}

void show_items()
{
    printf("Head->");
    Node *c = head;
    while (c != NULL)
    {
        printf("%i->", c->data);
        c = c->next;
    }
    printf("Tail\n");
}

void cleanup()
{
    Node *c = head;
    while (c != NULL)
    {
        Node *t = c;
        c = c->next;
        free(t);
    }
}