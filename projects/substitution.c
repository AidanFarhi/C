#include <stdio.h>
#include <cs50.h>
#include <string.h>

int is_key_valid(string key, int len); // returns 0 if valid | 1 if invalid
int get_index(char c); // returns the index of a given char in the alphabet -> a | A = 0, b | B = 1, c | C = 2...
void make_cipher_text(string s, string key); // Returns a string of ciphertext
void convert_key_to_uppercase(string key); // converts key to uppercase to make life easier later

int main(int argc, string argv[])
{
    if (argc < 2) // no key given
    {
        printf("Please enter valid key.\n");
        return 1;
    }
    string key = argv[1]; // Get key from user
    int len = strlen(key); // store the length of the string for later use
    if(is_key_valid(key, len) == 1) // 0 == pass and 1 == fail
    {
        printf("Please enter valid key.\n");
        return 1;
    }
    convert_key_to_uppercase(key);
    string s = get_string("plaintext: "); // Get string from user
    make_cipher_text(s, key); // make and output ciphertext
    return 0;
}

int is_key_valid(string key, int len)
{
    // Maintain an array of length 26. For every letter of the alph, there should be only 1 entry.
    int indexes_seen[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    // First check length
    if (len != 26)
    {
        return 1;
    }
    // Check if each char is a valid char
    for (int i = 0; i < len; i++)
    {
        char c = key[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            continue;
        }
        else
        {
            return 1;
        }
    }
    // Check if chars are repeated
    for (int j = 0; j < len; j++)
    {
        char c = key[j];
        int index = get_index(c);
        printf("Index: %i\n", index);
        if (indexes_seen[index] == 0)
        {
            indexes_seen[index] = 1;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

void make_cipher_text(string s, string key)
{
    int len = strlen(s);
    char output[len];
    for (int i = 0; i < len; i++)
    {
        char original_char = s[i];
        if (original_char >= 'a' && original_char <= 'z')
        {
            int index = get_index(original_char);
            char lowercase_key_char = key[index] + 32;
            output[i] = lowercase_key_char;
        }
        else if (original_char >= 'A' && original_char <= 'Z')
        {
            int index = get_index(original_char);
            output[i] = key[index];
        }
        else
        {
            output[i] = original_char;
        }
    }
    printf("ciphertext: %s\n", output);
}

int get_index(char c)
{
    char alph[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < 26; i++)
    {
        if (alph[i] == c || alph[i] + 32 == c)
        {
            return i;
        }
    }
    return -1;
}

void convert_key_to_uppercase(string key)
{
    for (int i = 0; i < 26; i++)
    {
        if (key[i] >= 'a' && key[i] <= 'z')
        {
            key[i] = key[i] - 32;
        }
    }
}