/*
**************************************************************
* Created by Joshau Leung on 5 September 2016
*
* a program that prompts a user for their name (using GetString 
* to obtain their name as a string) and then outputs their 
* initials in uppercase with no spaces or periods, 
* followed by a newline (\n) and nothing more.
*
*
**************************************************************/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> // toupper

/*
**************************************************************
*
* Extract initials from a name
*
* preposition:
*     - the user’s input will contain only letters 
*       (uppercase and/or lowercase) plus single 
*       spaces between words.
*
* postposition:
*     - The initials will be in uppercase
*
* @params: name, string, name of the user
*
* @return: initials, string, initials of the name
*
**************************************************************/
string extractInitials(const string name);

/*
**************************************************************
*
* Count the occurence of a char in a string
*
* @params: haystack, string, string to be searched
*          needle, char, char to count
*
* @return: num, int, number of occurence 
*
**************************************************************/
int countChar(string haystack, const char needle);



int main(void) 
{
    // Get user name
    string name = GetString();
    
    // Get initials
    string initials = extractInitials(name);
    
    // Output to console
    printf("%s\n", initials);
    
    free(initials);
    
    
    /* TESTING */
    //string str = "How are you!";
    //printf("%i\n", countChar(str, 'a')); // expected to be 2
    //printf("%i\n", countChar(str, ' ')); // expected to be 3
    // extractInitials("How are you");
}

string extractInitials(const string name)
{
    
    char* initials = malloc(countChar(name, ' ') + 2);
    
    initials[0] = toupper(name[0]);
    int pointer = 1;
    
    for (int i = 1, len = strlen(name); i < len; i++) 
    {
        if (name[i] == ' ') 
        {
            initials[pointer] = toupper(name[i+1]);
            pointer++;
        }
    }
    
    initials[pointer+1] = '\0';
    
    return initials;
}

int countChar(string haystack, const char needle) 
{
    int count = 0;
    
    for (int i = 0, len = strlen(haystack); i < len; i++)
    {
        if (haystack[i] == needle)
        {
            count++;
        }
    }
    
    return count;
}