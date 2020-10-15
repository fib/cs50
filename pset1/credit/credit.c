#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    long num = get_long("Number: ");
    long num_cpy = num; // copying the card number to use it after modifications
    long sum = 0, temp = 0, len = 0;

    // determining the amount of digits in the number
    while (num > 0)
    {
        num /= 10;
        len++;
    }
    num = num_cpy;

    // if the amount of digits in the number doesn't match it has to be invalid
    if (len != 13 && len != 15 && len != 16)
    {
        printf("INVALID\n");
    }
    else
    {
        // implementation of Luhn's algorithm
        while (num > 0)
        {
            sum += num % 10;
            num /= 10;
            temp = (num % 10) * 2;
            while (temp > 0)
            {
                sum += temp % 10;
                temp /= 10;
            }
            num /= 10;
        }
        num = num_cpy;

        // if the last digit isn't 0 the card has to be invalid
        if (sum % 10)
        {
            printf("INVALID\n");
        }
        else
        {
            // determining how much we should divide the number by to get the first two digits
            temp = num / pow(10, len - 2);

            if (temp == 34 || temp == 37)
            {
                printf("AMEX\n");
            }
            else if (temp >= 51 && temp <= 55)
            {
                printf("MASTERCARD\n");
            }
            else if (temp / 10 == 4)
            {
                printf("VISA\n");
            }
            // finally, if the card number doesn't match any of the above specs it is also considered invalid
            else
            {
                printf("INVALID\n");
            }
        }
    }
    
    return 0;
}
