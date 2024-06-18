#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change;
    int cents, quarter, dime, nickel, penny;

    do
    {
        change = get_float("Change owed: "); //prompts user for an amount of change owed.
    }
    while (change < 0); //forces user to input a positive number.

    //convert user input from dollars to cents & rounds to nearest integer.
    cents = round(change * 100);

    //number of quarters needed is the cents / 25. Any remainder is truncated due to properties of data type int.
    quarter = cents / 25;

    //number of dimes needed is found by taking the modulus of cents by 25 & dividing that remainder by 10.
    dime = (cents % 25) / 10;

    //number of nickels needed is found by performing the above, taking the modulus again by 10, then dividing by 5.
    nickel = ((cents % 25) % 10) / 5;

    //number of pennies needed is found by taking the modulus of cents by 5.
    penny = cents % 5;

    printf("Coins needed: %i\n", (quarter + dime + nickel + penny));
}