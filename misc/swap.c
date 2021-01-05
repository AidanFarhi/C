#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int a = 10;
    int b = 20;
    
    printf("a: %i\n", a);
    printf("b: %i\n", b);
    swap(&a, &b);
    printf("a: %i\n", a);
    printf("b: %i\n", b);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}