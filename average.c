#include <stdio.h>

// A simple program that calculates the average of an array
int main(void) {
    int grades[] = {1, 2, 3, 4, 5, 6, 3, 4, 5, 6, 1, 1, 6, 6, 7, 8, 8, 8};
    int total = 0;
    int n = sizeof grades / sizeof grades[0]; // This gets us the length of the array.
    for (int i = 0; i < n; i++) {
        total += grades[i];
    }
    printf("Average grade: %d\n", total / n);
}