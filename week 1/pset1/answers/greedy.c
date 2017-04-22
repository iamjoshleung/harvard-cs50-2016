/*
**************************************************************
* Created by Joshau Leung on 1 September 2016
*
* Asks the user how much change is owed and then spits out the 
* minimum number of coins with which said change can be made.
*
*
**************************************************************/

#include <cs50.h>
#include <stdio.h>
#include <math.h> // for round function
#define QUARTER 25
#define DIME 10
#define NICKLE 5
#define PENNIE 1

int getNumCoins(float change);

int main(void) 
{
    float change;
    
    do
    {
        printf("O hai! How much change is owed?\n");
        change = GetFloat();
    } while (change < 0);
    
    printf("%d\n", getNumCoins(change));
    return 0;
}

int getNumCoins(float change)
{
    // convert to cents
    int changeInInt = roundf(change * 100); // round the number to avoid imprecision issues (issues presented in float point number)
    int coins = 0;
    
    if (changeInInt >= QUARTER) 
    {
        coins += changeInInt / QUARTER;
        changeInInt %= QUARTER;
    }
    
    if(changeInInt >= DIME)
    {
        coins += changeInInt / DIME;
        changeInInt %= DIME;
    }
    
    if(changeInInt >= NICKLE)
    {
        coins += changeInInt / NICKLE;
        changeInInt %= NICKLE;
    }
    
    if(changeInInt >= PENNIE)
    {
        coins += changeInInt / PENNIE;
        changeInInt %= PENNIE;
    } 
    
    return coins;
}