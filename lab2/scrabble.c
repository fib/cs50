#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 == score2)
    {
        printf("Tie!\n");
    }
    else
    {
        // simple inline if-statement to avoid redundancy 
        printf("Player %d wins!\n", score1 > score2 ? 1 : 2);
    }
}

int compute_score(string word)
{
    int total = 0;

    // iterating over each character in the word
    for (int i = 0; i < strlen(word); i++)
    {
        // if it is an alphabetical character...
        if (isalpha(word[i]))
        {
            // adding the value of the letter to the total score
            total += POINTS[tolower(word[i]) - 'a'];
        }
    }

    return total;
}

