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
        int lo = i;
        for (int j = i; j < len; j++)
        {
            if (arr[j] < arr[lo])
            {
                lo = j;
            }
        }
        swap(arr, i, lo);
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