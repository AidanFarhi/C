#include <stdio.h>
#include <stdlib.h>

/* Prototypes */
int connected(int x, int y, int *id); // Returns 1 if connected else 0
int get_root(int n, int *id);
void make_union(int x, int y, int *id);
void show_roots(int *roots, int size);

/* Declare a pointer to an id's array */
int *id;

/* Client */
int main(int argc, char *argv[])
{
    // Initialize ids array
    int size = atoi(argv[1]);
    id = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        id[i] = i;
    }
    make_union(0, 1, id);
    make_union(3, 8, id);
    make_union(1, 6, id);
    make_union(4, 12, id);
    make_union(5, 3, id);
    printf("%i connected to %i: %s\n", 5, 8, connected(5, 8, id) == 1 ? "True" : "False");
    show_roots(id, size);
    free(id);
}

/* Functions */
int connected(int x, int y, int *id)
{
    if (get_root(x, id) == get_root(y, id))
    {
        return 1;
    }
    return 0;
}

int get_root(int n, int *id)
{
    while (n != id[n])
    {
        n = id[n];
    }
    return n;
}

void make_union(int x, int y, int *id)
{
    int x_root = get_root(x, id);
    int y_root = get_root (y, id);
    id[x_root] = y_root;
}

void show_roots(int *roots, int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        if (i == size - 1)
        {
            printf("%i", roots[i]);
            break;
        }
        printf("%i, ", roots[i]);
    }
    printf("]\n");
}