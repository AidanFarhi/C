#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{   
    // First get a string from the user
    char *original;
    printf("Enter your name: ");
    scanf("%s", original);

    // Now make a copy of that string
    char *copy = malloc(strlen(original) + 1);

    for (int i = 0, n = strlen(original); i <= n; i++)
    {
        copy[i] = original[i];
    }

    printf("Original string: %s\n", original);
    printf("Original address: %p\n", original);
    printf("Copy string: %s\n", copy);
    printf("Copy string address: %p\n", copy);

    free(copy);
}