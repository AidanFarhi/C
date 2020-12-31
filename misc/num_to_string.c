#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) 
{
    char string[5];
    sprintf(string, "%i", 1000);
    printf("%c", string[0]);
}