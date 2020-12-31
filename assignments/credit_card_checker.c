#include <stdio.h>

int check_type(long number); // checks for card length and starting digits: -1 == INVALID | 1 == AMEX | 2 == VISA | 3 == MASTERCARD
int check_sum(long number); // calculates the validity of the card number using Luhn's algorithm

int main(void)
{
    long num;
    printf("Enter a Credit Card Number: ");
    scanf("%li", &num);
    if (num < 1000000000000)
    {
        printf("INVALID\n");
    }
    else
    {
       if (check_sum(num) > -1) // success == 0, fail = -1
       {
            int result = check_type(num);
            if (result == 1)
            {
                printf("AMEX\n");
            }
            else if (result == 2)
            {
                printf("VISA\n");
            }
            else if (result == 3)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
       }
       else
       {
           printf("INVALID\n");
       }
    }
    return 0;
}

// Luhn's algorithm to check the validity of a number
int check_sum(long number)
{
    long copy = number;
    int count = 0;
    int first_sum = 0;
    int second_sum = 0;
    while (copy > 0)
    {
        int rem = copy % 10;
        copy /= 10;
        if (count % 2 > 0)
        {
            int doubled = rem * 2;
            if (doubled > 9)
            {
                first_sum += doubled % 10;
                first_sum += doubled / 10;
            }
            else
            {
                first_sum += doubled;
            }

        }
        else
        {
            second_sum += rem;
        }
        count++;
    }
    if ((second_sum + first_sum) % 10 == 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }
    return -1;
}

int check_type(long number) // -1 == INVALID | 1 == AMEX | 2 == VISA | 3 == MASTERCARD
{
    if (number > 99999999999999 && number < 1000000000000000) // 15 digit number
    {
        long copy = number;
        int first_dig = 0;
        int second_dig = 0;
        while (copy > 0)
        {
            if (copy < 100) // we are down to two digits
            {
                second_dig = copy % 10;
                copy /= 10;
                first_dig = copy % 10;
                if (first_dig == 3)
                {
                    if (second_dig == 4 || second_dig == 7)
                    {
                        return 1; // 1 == AMEX
                    }
                    else
                    {
                        return -1;
                    }
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                copy /= 10;
            }
        }
    }
    // 16 or 13 digit number
    else if ((number > 999999999999999 && number < 10000000000000000) || (number > 999999999999 && number < 10000000000000))
    {
        long copy = number;
        int first_dig = 0;
        int second_dig = 0;
        while (copy > 0)
        {
            if (copy < 100) // we are down to two digits
            {
                second_dig = copy % 10;
                copy /= 10;
                first_dig = copy % 10;
                if (first_dig == 4)
                {
                    return 2; // 2 == VISA
                }
                else if (first_dig == 5)
                {
                    if (second_dig > 0 && second_dig < 6)
                    {
                        return 3; // 3 == Mastercard
                    }
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                copy /= 10;
            }
        }
    }
    else
    {
        return -1;
    }
    return -1;
}