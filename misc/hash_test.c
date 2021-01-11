#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LENGTH 45 // Maximum word length

typedef struct Node
{
    char word[LENGTH + 1];
    int data;
    struct Node *next;
}
Node;

// Simple hash table using the first letter as key.
// a == 0, b == 1, ect..
Node *hash_table[26];

/* Prototypes */
int hash_function(char c);
void put(char key[], int data);
void get(char key[]);

/* Test Client */
int main(void)
{
    // Initialize each entry to NULL
    // for (int i = 0; i < 26; i++)
    // {
    //     hash_table[i] = NULL;
    // }
    // Test some keys and values
    put("App", 100);
    put("ApP", 200);
    put("app", 300);
    put("Baa", 400);
    get("App");
    get("ApP");
    get("app");
    get("Baa");
    get("Ap");
}

/* Functions */

// Returns index of char or -1 if not found
int hash_function(char c)
{
    char alph[26] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 26; i++)
    {
        if (c == alph[i] || c == (alph[i] - 32))
        {
            return i;
        }
    }
    return -1;
}

void put(char key[], int data)
{
    int index = hash_function(key[0]);
    Node *n = malloc(sizeof(Node));
    strcpy(n->word, key);
    n->next = NULL;
    n->data = data;
    if (hash_table[index] != NULL)
    {
        Node *current = hash_table[index];
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = n;
    }
    else
    {
        hash_table[index] = n;
    }
}

void get(char key[])
{
    int index = hash_function(key[0]);
    if (hash_table[index] != NULL)
    {
        Node *current = hash_table[index];
        while (current != NULL)
        {
            if (strcmp(current->word, key) == 0)
            {
                printf("Data: %i\n", current->data);
                return;
            }
            current = current->next;
        }
    }
    printf("Key not found.\n");
}