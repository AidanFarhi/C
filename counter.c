#include <stdio.h>

// In C, we have to declare all the functions at the top of the file.
int increment(int num, int times);

// By convention, main() should be at the top of our program,
// under any declared functions we are using.
int main(void) 
{
    int num = 1;
    int times;
    printf("Enter the number of times: ");
    scanf("%i", &times);
    num = increment(num, times);
    printf("Result: %d\n", num);
}

// This is where we implement the functions we use.
int increment(int num, int times) 
{
    int result = num;
    for (int i = 0; i < times; i++) 
    {
        result += 1;
    }
    return result;
}
