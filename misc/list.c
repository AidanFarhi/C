#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Allocate a chunk of memory large enough to hold 3 integers
    // This is equivalent to: int list[3];
    int *list = malloc(3 * sizeof(int)); 
    // Assign values to each slot in memory
    list[0] = 100;
    list[1] = 200;
    list[2] = 300;
    // Now allocate a larger chunk of memory to copy old values into
    int *temp = malloc(4 * sizeof(int));
    // Now copy old values into new list
    for (int i = 0; i < 3; i++)
    {
        temp[i] = list[i];
    }
    // Now release the memory of the old list
    free(list);
    // Assign a value to the end of our new list
    temp[3] = 400;
    // Make *list point to *temp
    list = temp;
    // Now print out values
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }
    // Now free list at the end
    free(list);
}