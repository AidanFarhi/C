#include <stdio.h>

int fibonacci(int n); // returns the nth fibonacci number

int main(void)
{
    while (1)
    {   
        int n = 0;
        while (n < 1)
        {
            printf("Enter an int > 0: ");
            scanf("%i", &n);
            printf("You entered: %i\n", n);
        }
        int result = fibonacci(n);
        printf("%ith fibonacci number: %i\n", n, result);
    }

}

int fibonacci(int n)
{
    int memo[n];
    memo[0] = 0;
    memo[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        memo[i] = memo[i - 1] + memo[i - 2];
    }
    return memo[n];
}