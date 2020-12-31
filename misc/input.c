#include <stdio.h>

int main(void) 
{
    // First declare a string of max 20 length.
    char name[20];
    // Now prompt the user for the input.
    printf("Enter your name: ");
    // Now scan the input, and store it in the name variable
    scanf("%s", name);
    // Now print the result
    printf("Hello there %s\n", name);
}