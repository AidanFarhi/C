#include <stdio.h>

int main(void) 
{
    // Intialize variables;
    int age_in_years;
    int age_in_days;

    // Get age from user
    printf("Enter your age in years: ");
    scanf("%i", &age_in_years);

    // Calculate age in days
    age_in_days = age_in_years * 365;

    // Print result
    printf("You are exactly %i days old.\n", age_in_days);
}