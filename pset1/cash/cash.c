#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // initializing variables for total change as well as coin counting
    int change = 0;
    int q = 0, d = 0, n = 0, p = 0;

    // validating that user input is >= 0
    do
    {
        change = round(get_float("Change owed: ") * 100);
    }
    while (change < 0);

    // checking how many coins fit and subtracting their sum from the total change
    q = change / 25 >= 1 ? change / 25 : 0;
    change -= q * 25;

    d = change / 10 >= 1 ? change / 10 : 0;
    change -= d * 10;

    n = change / 5 >= 1 ? change / 5 : 0;
    change -= n * 5;

    p = change / 1 >= 1 ? change / 1 : 0;
    change -= p * 1;

    printf("%d\n", q + d + n + p);
}
