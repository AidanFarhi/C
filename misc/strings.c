#include <stdio.h>
#include <string.h>

int main(void) 
{
    // To define a string that can be manipulated
    char name[] = "Aidan";
    int n = strlen(name);
    // The reasoning here is we are iterating until
    // we reach the end of the string arrray, which
    // in C, is a char labeled: '\0'
    for (int i = 0; name[i] != '\0'; i++)
    {
        printf("%c", name[i]);
    }
    printf("\n");
    // A simpler way of doing it
    for (int j = 0; j < n; j++) 
    {
        printf("%c", name[j]);
    }
    printf("\n");

    // Lets get the ASCII codes for all the chars
    for (int p = 0; p < n; p++)
    {
        printf("Char %c = %i\n", name[p], (int) name[p]);
    }

    // Change every char to uppercase
    for (int k = 0, m = strlen(name); k < m; k++)
    {
        if (name[k] >= 'a' && name[k] <= 'z')
        { 
            // Here we take advantage of the fact that
            // the ASCII codes for lowercase letters are
            // 32 more than the uppercase letter.
            printf("%c", name[k] - 32);
        }
        else
        {
            printf("%c", name[k]);
        }
    }
    printf("\n");
}