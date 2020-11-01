#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>

// function prototypes
void shift(int key, string s);
int check_key(string k);

int main(int argc, char *argv[])
{
    int key = 0;
    string text = "";

    // checking if the correct amount of command line arguments was provided
    // and that the key only contains numerical digits
    if (argc == 2 && check_key(argv[1]))
    {
        key = atoi(argv[1]) % 26; // finding value of key between 0 and 26
        text = get_string("plaintext: ");
        
        printf("ciphertext: ");
        shift(key, text);
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    return 0;
}

// shifting each letter of the string accordingly and printing it out
void shift(int key, string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i])) // if it is a letter
        {
            if (islower(s[i])) // if the letter is lower case
            {
                printf("%c", (s[i] + key - 'a') % 26 + 'a');
            }
            else
            {
                printf("%c", (s[i] + key - 'A') % 26 + 'A');
            }
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}

// checking the key to make sure there are only numerical digits in it
// if a non digit is encountered, the function returns 0. Otherwise 1 is returned
int check_key(string k)
{
    for (int i = 0; i < strlen(k); i++)
    {
        if (!isdigit(k[i]))
        {
            return 0;
        }
    }

    return 1;
}
