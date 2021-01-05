#include <stdio.h>

int main(void)
{
    // Opens a file, or creates if it does not exist
    FILE *file = fopen("phonebook.csv", "a"); // "a" = append
    char name[20];
    char number[20];
    printf("Enter Name: ");
    scanf("%s", name);
    printf("Enter Number: ");
    scanf("%s", number);
    fprintf(file, "%s,%s\n", name, number); // Writes to the csv file
    printf("Entry Added.\n");
    fclose(file);
}