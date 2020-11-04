#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>

void substitute(string k, string s);
int check_key(string k);

int main(int argc, char *argv[])
{
    string key = "";
    string text = "";

    // checking if the correct amount of command line arguments was provided
    // and that the key only contains unique alphabetical characters
    if (argc == 2 && check_key(argv[1]))
    {
        key = argv[1];
        
        if (strlen(key) != 26) // checking if the length of the key isn't 26
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        
        text = get_string("plaintext: ");
        printf("ciphertext: ");
        substitute(key, text);
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    return 0;
}

// the function that takes the plaintext and the key
// and prints out the encrypted message
void substitute(string k, string s)
{
    // looping over every character in the plaintext
    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i])) // if it's alphabetical then the corresponding encrypted letter is calculated
        {
            printf("%c", islower(s[i]) ? tolower(k[s[i] - 'a']) : toupper(k[s[i] - 'A']));
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}

// checking if the key only has 26 unique alphabetical characters
int check_key(string k)
{    
    int count = 0;

    // looping over the alphabet (lower case)
    for (int i = 'a'; i < 'z'; i++)
    {
        count = 0;
        for (int j = 0; j < strlen(k); j++)
        {
            if (i == tolower(k[j]))
            {
                count++;
            }
            if (!isalpha(k[j]) || count > 1)
            {
                return 0;
            }
        }
    }
    return 1;
}
