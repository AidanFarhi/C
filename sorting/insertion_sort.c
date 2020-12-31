#include <stdio.h>

void swap(int arr[], int i, int j);
void show_items(int arr[], int len);

int main(void)
{
    int arr[] = {5, 4, 6, -1, -44, 2, 66, 232, -55, -1, 5555};
    int len = sizeof arr / sizeof arr[0]; // Get length of array
    printf("length: %i\n", len);
    show_items(arr, len);
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr, j, j - 1);
            }
            else
            {
                break;
            }
            
        }
    }
    show_items(arr, len);
}

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
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