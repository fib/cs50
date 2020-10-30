#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <cs50.h>

// function prototypes
int cl_index(int l, int w, int s);

int main(void)
{
    string text = get_string("Text: ");
    int len = strlen(text);
    int letters = 0, words = 1, sentences = 0;
    int index = 0;

    // this loop counts the letters, words, and sentences in the input
    // this could be implemented in a separate function, but with our 
    // current knowledge of C there would have to be 3 different functions,
    // meaning that instead of just iterating over the input once we'd have
    // to loop 3 times.
    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))           // catching alphabetical characters
        {
            letters++;
        }
        else if (isspace(text[i]))      // catching spaces
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?') // catching sentence terminators
        {
            sentences++;
        }
    }

    index = cl_index(letters, words, sentences);

    // outputting according to the specified format
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
    
    return 0;
}

// implementation of the Coleman-Liau index formula
int cl_index(int l, int w, int s)
{
    float L = 0, S = 0;

    L = 100 * ((float)l / w);
    S = 100 * ((float)s / w);

    return round(0.0588 * L - 0.296 * S - 15.8);
}
