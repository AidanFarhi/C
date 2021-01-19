#include <stdio.h>
#include <stdlib.h>

/* Prototypes */
void push(int item);
int pop();
int valid_input(int index);
void resize(int new_size);
void show_items();
void free_memory();
void array_init();

/* Global array and variables*/
int *ARRAY;
int SIZE = 0;
int CAPACITY = 8;

/* Initializes Array to size 8 */
void array_init()
{
    ARRAY = malloc(sizeof(int) * CAPACITY);
}

int pop()
{
    if (SIZE == 0)
    {
        printf("Array is empty.\n");
        return 0;
    }
    int item = ARRAY[--SIZE];
    if (SIZE > 0 && SIZE == CAPACITY / 4)
    {
        resize(CAPACITY / 2);
    }
    return item;
}

void push(int item)
{
    if (SIZE == CAPACITY)
    {
        resize(CAPACITY * 2);
    }
    ARRAY[SIZE++] = item;
}

void resize(int new_size)
{
    ARRAY = realloc(ARRAY, sizeof(int) * new_size);
    CAPACITY = new_size;
}

void show_items()
{
    printf("[");
    for (int i = 0; i < CAPACITY; i++)
    {
        if (i == CAPACITY - 1)
        {
            printf("%i", ARRAY[i]);
            break;
        }
        printf("%i, ", ARRAY[i]);
    }
    printf("]\n");
}

int valid_input(int index)
{
    if (index < 0 || index >= CAPACITY)
    {
        return 1;
    }
    return 0;
}

void free_memory()
{
    free(ARRAY);
}
