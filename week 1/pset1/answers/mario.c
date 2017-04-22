/*
**************************************************************
* Created by Joshau Leung on 31 August 2016
*
* Build a pyramid.
*
*
**************************************************************/

#include <cs50.h>
#include <stdio.h>
#define MAX 23

void printPyramid(int height);

int main(void)
{
    int height;
    
    do 
    {
        printf("height: ");
        height = GetInt();
    } while(height > MAX || height < 0);
    
    printPyramid(height);
    
    return 0;
}

void printPyramid(int height) 
{
    for (int i = 1; i <= height; i++) {
        // print spaces
        printf("%.*s", height - i , "                           ");
        
        // print hash
        printf("#%.*s\n", i, "####################################");
    }
}
