#include <stdio.h>
#include <stdlib.h>

/* Prototypes */
int connected(int x, int y, int *roots); // O(1) -> 1 == connected & 0 == not connected
void make_union(int x, int y, int *roots, int size); // O(N) 
void show_roots(int *roots, int size);

/* Test Client */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./quick_find <int>\n");
    }
    int size = atoi(argv[1]);
    // Maintain an array of roots
    // int size = 8;
    int roots[size];
    // Initialize each item to be it's own root
    for (int i = 0; i < size; i++)
    {
        roots[i] = i;
    }
    // Run Tests
    make_union(0, 3, roots, size);
    make_union(1, 7, roots, size);
    make_union(1, 6, roots, size);
    make_union(3, 7, roots, size);
    printf("%i and %i connected: %s\n", 0, 3, connected(0, 3, roots) == 1 ? "true" : "false");
    printf("%i and %i connected: %s\n", 6, 0, connected(6, 0, roots) == 1 ? "true" : "false");
    show_roots(roots, size);
}

/* Functions */
int connected(int x, int y, int *roots)
{
    if (roots[x] == roots[y])
    {
        return 1;
    }
    return 0;
}

void make_union(int x, int y, int *roots, int size)
{
    int x_root = roots[x];
    int y_root = roots[y];
    for (int i = 0; i < size; i++)
    {
        if (roots[i] == y_root)
        {
            roots[i] = x_root;
        }
    }
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