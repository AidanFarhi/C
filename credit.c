#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_valid_num(long num); // Checks initial length of the number
char* get_card_type(long num); // Checks type of number
int luhns_algorithm(char* num); // Checks if the number is a valid credit card number
int get_length(long num); // Gets the length of the number

int main(void)
{   
    while (1) 
    {
        long credit_card_long;
        printf("Enter a credit card number: ");
        scanf("%lo", &credit_card_long);
        if (check_valid_num(credit_card_long) == 0) // 0 == fail, 1 == sucess
        {
            printf("Invalid number.\n");
            continue;
        }
        else
        {
            char * card_type = get_card_type(credit_card_long);
            char string_number[get_length(credit_card_long)];
            int result = luhns_algorithm(string_number);
            if (result == 0)
            {
                printf("Card type: %s\n", card_type);
            }
            else {
                printf("Invalid Number.\n");
            }
        }
    }
}

// This function checks if the number is between 13-16 digits
int check_valid_num(long num) 
{
    if (num < 1000000000000) 
    {
        return 0;
    }
    else if (num > 9999999999999999)
    {
        return 0;
    }
    else 
    {
        return 1;
    }
}

/**
* This function checks the count of digits of a credit card number, 
* examines the first digits, and returns the card type.
* AE = [34, 37]
* MC = [51, ..., 55]
* VS = [4]
*/
char* get_card_type(long num) 
{
    if (num < 10000000000000) // 13 digits, have to check if Visa or Mastercard
    {
        char string[13];
        sprintf(string, "%ld", num); // Convert to string
        int first_dig = atoi(string[0]);
        if (atoi(&string[0]) == 4) 
        {
            return "VISA";
        }
        else
        {
            return "MASTERCARD";
        }
    }
    else if (num > 99999999999999 && num < 10000000000000000) // 15 digits
    {
        return "AMEX";
    }
    else // 16 digits
    {
        return "VISA";
    }
}

// Gets the length of the credit card number
int get_length(long num) {
    if (num > 999999999999 && num < 10000000000000) // 13 digits 
    {
        return 13;
    }
    else if (num > 99999999999999 && num < 1000000000000000) // 15 digits
    {
        return 15;
    }
    else 
    {
        return 16;
    }
}

// Final validator based on Luhn's algorithm. Return 0 for sucess 1 for failure.
int luhns_algorithm(char* num) 
{
    int len = get_length(atoi(num));
    int arr[len];
    int index = 0;
    for (int i = len - 1; i >= 0; i -= 2) 
    {
        arr[index] = atoi(&num[i]) * 2;
    }
    int first_sum = 0;
    for (int j = 0; j < len; j++) 
    {
        int current = arr[j];
        if (current > 9) 
        {
            char num_string[2];
            sprintf(num_string, "%d", current);
            first_sum += atoi(&num_string[0]);
            first_sum += atoi(&num_string[1]);
        }
        else
        {
            first_sum += current;
        }
    }
    long final_sum = first_sum;
    for (int k = 0; k < len; k++) 
    {
        final_sum += arr[k];
    }
    if (final_sum % 10 == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}