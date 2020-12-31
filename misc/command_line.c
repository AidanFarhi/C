#include <stdio.h>

// argc == number of arguments | argv == an array of strings
int main(int argc, char** argv)
{
    if (argc >= 2)
    {
        for (int i = 1; i < argc; i++)
        {
            printf("%s\n", argv[i]);
        }
    } 
    else 
    {
        printf("No arguments passed except for program name.\n");
    }
}