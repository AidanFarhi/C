#include <stdio.h>

int main(void)
{
    char *s = "Aidan";
    // Pointer arithmetic
    printf("First char: %c\n", *s);
    printf("Second char: %c\n", *(s+1));
    printf("Third char: %c\n", *(s+2));
    printf("Fourth char: %c\n", *(s+3));
    printf("Fifth char: %c\n", *(s+4));
}