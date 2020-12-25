#include <stdio.h>

int main(void) 
{
    int num;
    printf("Enter a number: ");
    scanf("%i", &num);
    if (num % 2 == 0) 
    {
        printf("Number is even.\n");
    } 
    else 
    {
        printf("Number is odd.\n");
    }
}