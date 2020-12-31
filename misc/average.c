#include <stdio.h>

void show_items(int arr[], int len);
float get_average(int arr[], int len);

// A simple program that calculates the average of an array
int main(void) 
{   
    // Get the size of array and create an array of that length
    printf("Enter an array size: ");
    int n;
    scanf("%i", &n);
    int scores[n];

    // Get each array item from command line
    for (int i = 0; i < n; i++) {
        int next;
        printf("Enter integer: ");
        scanf("%i", &next);
        scores[i] = next;
    }

    // Calculate and show average
    printf("Scores: ");
    show_items(scores, n);
    printf("Average: %.2f\n", get_average(scores, n));
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

float get_average(int arr[], int len)
{
    float sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += (float) arr[i];
    }
    return sum / (float) len;
}