/*
**************************************************************
* Created by Joshau Leung on 31 August 2016
*
* Calculate the equivalent number of bottles of water from 
* the number of minutes in shower.
*
* Preposition: 
*    - the user will input a positive integer
*
* Postposition:
*    - the user will get a positive number representing 
*      the equivalent number of bottles of water
*
**************************************************************/

#include <cs50.h>
#include <stdio.h>

float getNumBottles(float minutes);

int main(void)
{
    printf("minutes: ");
    float minutes = GetInt();
    printf("bottles: %i\n", (int) getNumBottles( minutes ));
    return 0;
}

float getNumBottles(float minutes) 
{
    float gallonsPerMin = 1.5;
    float gallonPerOunce = 128;
    float ouncesPerBottle = 16;
    
    return gallonsPerMin * gallonPerOunce * minutes / ouncesPerBottle;
}