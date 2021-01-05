#include <stdio.h>

// Prints out a string representation of an array in the command line.
void show_items(int arr[], int len); 
// Performs a linear search on an array. Returns index if found, or -1 if not found.
int linear_search(int arr[], int len, int target); 
// Prints out proper result based on whether target was found or not
void print_result(int result, int target);

int main(void)
{
    int arr[] = {55, 1, -54, 66, 14, 99, 300, 57, 39, 24, 2, -65, -9};
    int len = 13;
    while (1)
    {
        int target;
        show_items(arr, len);
        printf("Enter a number to search for: ");
        scanf("%i", &target);
        int result = linear_search(arr, len, target);
        print_result(result, target);
    }
}

int linear_search(int arr[], int len, int target)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

void show_items(int arr[], int len)
{   
    printf("[");
    for (int i = 0; i < len; i++)
    {   
        if (i == len - 1)
        {
            printf("%i", arr[i]);
        }
        else
        {
            printf("%i, ", arr[i]);
        }
    }
    printf("]\n");
}

void print_result(int result, int target)
{
    if (result > -1)
    {
        printf("Target number %i found at index: %i\n", target, result);
    }
    else
    {
        printf("Target number %i not found.\n", target);
    }
}
