#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int size = 0;

    do
    {
        size = get_int("Height: ");
    }
    while (size < 1 || size > 8);

    // main loop, iterates for the number of times the user entered
    for (int i = 1; i <= size; i++)
    {
        // printing the spaces for padding
        for (int s = size; s > i; s--)
        {
            printf(" ");
        }

        // 2 iterations, one for each pyramid
        for (int p = 0; p < 2; p++)
        {
            // printing the hashes
            for (int j = 0; j < i; j++)
            {
                printf("#");
            }

            // printing the space between the pyramids
            if (p == 0)
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}
