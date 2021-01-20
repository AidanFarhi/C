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
void enqueue(int item);
int dequeue();
void show_items();
void cleanup();

/* Global variables */
Node *head = NULL;
Node *tail = NULL;

/* Test Client */
int main(void)
{
    for (int i = 10; i < 20; i++)
    {
        enqueue(i);
    }
    show_items();
    for (int j = 0; j < 5; j++)
    {
        printf("Item: %i\n", dequeue());
    }
    show_items();
    cleanup();
}

void enqueue(int item)
{
    Node *old_tail = tail;
    tail = malloc(sizeof(Node));
    tail->data = item;
    tail->next = NULL;
    if (head == NULL)
    {
        head = tail;
    }
    else
    {
        old_tail->next = tail;
    }
}

int dequeue()
{
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