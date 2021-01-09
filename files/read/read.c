/* A simple program that reads from txt files */

#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("File: %s could not be opened.\n", argv[1]);
    }
    char buffer[50];
    while(fscanf(file, "%s", buffer) != EOF)
    {
        printf("%s\n", buffer);
    }
    fclose(file);
}