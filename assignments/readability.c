#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(char s[], int len); // gets count of letters in string
int count_words(char s[], int len); // gets count of words in string
int count_sentences(char s[], int len); // gets count of sentences in string
int is_valid_char(char c); // Checks if char is a valid letter. 0 == valid | 1 == invalid
int is_end_of_sentence(char c); // Checks if char is one of these: [ '.', '!', '?']
void print_result(int index); // Prints the correct end result based on given index
/*
This calculates the Coleman-Liau index, which usese the following formula:
index = 0.0588 * L - 0.296 * S - 15.8
L = average number of letters per 100 words in the text
S = average number of sentences per 100 words in the text
*/
int calculate_index(int letter_count, int word_count, int sentence_count);

int main(void)
{  
    printf("Enter a sentence: \n");
    char s[1000];
    fgets(s, sizeof(s), stdin);
    int len = strlen(s);
    int letter_count =  count_letters(s, len);
    int word_count = count_words(s, len);
    int sentence_count = count_sentences(s, len);
    int index = calculate_index(letter_count, word_count, sentence_count);
    print_result(index);
}

int calculate_index(int letter_count, int word_count, int sentence_count)
{
    /*
     Coleman-Liau Formula
     index = 0.0588 * L - 0.296 * S - 15.8
     L = average number of letters per 100 words in the text
     S = average number of sentences per 100 words in the text
    */
    float l = (float) letter_count / (float) word_count * 100; // average number of letters per 100 words in the text
    float s = (float) sentence_count / (float) word_count * 100; // average number of sentences per 100 words in the text
    float index = 0.0588 * l - 0.296 * s - 15.8; // Coleman-Liau formula
    return round(index);
}

int count_letters(char s[], int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        if (is_valid_char(s[i]) == 0)
        {
            sum++;
        }
    }
    return sum;
}

int count_words(char s[], int len)
{
    int total_words = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == ' ' || i == len - 1)
        {
            total_words++;
        }
    }
    return total_words;
}

int count_sentences(char s[], int len)
{
    int total_sentences = 0;
    for (int i = 0; i < len; i++)
    {
        if (is_end_of_sentence(s[i]) == 0)
        {
            total_sentences++;
        }
    }
    return total_sentences;
}

int is_valid_char(char c) // -> 0 == valid | 1 == invalid
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        return 0;
    }
    return 1;
}

int is_end_of_sentence(char c) // -> 0 == true | 1 == false
{
    if (c == '!' || c == '.' || c == '?')
    {
        return 0;
    }
    return 1;
}

void print_result(int index)
{
    if (index < 0)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}