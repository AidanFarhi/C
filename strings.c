#include <stdio.h>

int main(void) {
    // To define a read only string
    char *name = "Aidan Farhi";
    // To define a string that can be manipulated
    char name2[] =  "Aidan Farhi";
    printf("%s\n", name);
    printf("%s\n", name2);
}