// Implements a dictionary's functionality
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// record # of words loaded in dictionary
int words_in_dict = 0;

// Puts word node in hash table
void put(char *word)
{
    int index = hash(word);
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        printf("Could not allocate memory for new node.\n");
        return;
    }
    strcpy(n->word, word);
    n->next = NULL;
    if (table[index] != NULL)
    {
        node *current = table[index];
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = n;
    }
    else
    {
        table[index] = n;
    }
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int index = hash(word);
    if (table[index] != NULL)
    {
        node *current = table[index];
        while (current != NULL)
        {
            if (strcasecmp(current->word, word) == 0)
            {
                return true;
            }
            current = current->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    char alph[26] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 26; i++)
    {
        if (word[0] == alph[i] || word[0] == (alph[i] - 32))
        {
            return i;
        }
    }
    return 26; // Out of range
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open dicionary file
    FILE *d = fopen(dictionary, "r");
    if (d == NULL)
    {
        printf("Could not open dictionary file.\n");
        return false;
    }
    // Word buffer to store each word
    char word[LENGTH + 1];
    // Read each word one at a time until fscanf() returns => EOF
    while (fscanf(d, "%s", word) != EOF)
    {
        put(word);
        words_in_dict++;
    }
    fclose(d);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return words_in_dict;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < 26; i++)
    {
        if (table[i] != NULL)
        {
            node *n = table[i];
            while (n != NULL)
            {
                node *t = n->next;
                free(n);
                n = t;
            }
        }
    }
    return true;
}
