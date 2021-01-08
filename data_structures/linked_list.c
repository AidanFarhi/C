#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Node definition */
typedef struct Node 
{
    int data;
    struct Node *next;
}
Node;

/* Initialize a NULL head Node */
Node *head = NULL;

/* Define our functions here */
void add_front(int data); // O(1)
int remove_front(); // O(1)
void add_back(int data); // O(N)
int remove_end(); // O(N)
bool search(int data); // O(N)
void show_items();

/* Test Client */
int main(void)
{
    // Add some nodes to front
    add_front(100);
    add_front(200);
    add_front(300);
    add_back(400);
    add_back(500);
    remove_front();
    remove_end();
    printf("200 in list: %s\n", search(200) ? "true" : "false");
    printf("600 in list: %s\n", search(600) ? "true" : "false");
    // Print the nodes
    show_items();
}

/* Functions */
void add_front(int data)
{
    // Create a new Node and add to front
    Node *n = malloc(sizeof(Node));
    n->data = data;
    n->next = head;
    head = n;  
}

void add_back(int data)
{
    if (head == NULL) // Check if list is empty
    {
        add_front(data);
    }
    else // Iterate until we reach end of list and insert Node after last Node
    {
        Node *new_node = malloc(sizeof(Node)); // Create new Node
        new_node->data = data;
        new_node->next = NULL;
        Node *t = head;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = new_node;
    }
}

int remove_front()
{
    Node *t = head;
    int data = head->data;
    head = head->next;
    free(t);
    return data;
}

int remove_end()
{
    Node *n = head;
    while (n->next->next != NULL)
    {
        n = n->next;
    }
    int data = n->next->data;
    n->next = NULL;
    free(n->next);
    return data;
}

bool search(int data)
{
    Node *n = head;
    while (n != NULL)
    {
        if (n->data == data)
        {
            return true;
        }
        n = n->next;
    }
    return false;
}

void show_items()
{
    Node *n = head;
    printf("[Head:");
    while (n != NULL)
    {
        if (n->next == NULL)
        {
            printf("%i", n->data);
        }
        else
        {
            printf("%i->", n->data);
        }
        n = n->next;
    }
    printf("]\n");
}