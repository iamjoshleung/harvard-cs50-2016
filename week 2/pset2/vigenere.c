/*
**************************************************************
* Created by Joshau Leung on 6 September 2016
*
* a program that encrypts messages using Vigenère’s cipher.
*
*
**************************************************************/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> // isalpha, isupper, islower
#define MAX 26 // max num of alphebet 

/*
**************************************************************
*
* Using Vigenère’s cipher to encrypt messages
*
*
* @params: plainText, string, original message
*          keyword, string, Vigenère keyword
*
* @return: encryptedMsg, string, encrypted message
*
**************************************************************/
string encryptMsg(const string plainText, const string keyword);

/*
**************************************************************
*
* Using Caesar’s cipher to encrypt a letter
*
*
* @params: plainText, string, original message
*          key, int, the key
*
* @return: encryptedLetter, char, encrypted letter
*
**************************************************************/
char encryptLetter(const char letter, const int key);

/*
**************************************************************
*
* Get alphabet position of a letter, starting from 0 to 25
*
*
* @params: letter, char, letter to calculate the position
*          
*
* @return: pos, int, position of the letter
*
**************************************************************/
int getAlphaPos(const char letter);

/*
**************************************************************
*
* Check if a string consists of only alphebetic characters
*
*
* @params: str, string, string to check
*          
*
* @return: bool
*
**************************************************************/
bool isAlphaStr(const string str);

int main(int argc, string argv[])
{
    if (argc != 2) 
    {
        printf("Usage: ./vigenere <key>\n");
        return 1;    
    } else if (!isAlphaStr(argv[1])) {
        printf("The keyword must only consist entirely of alphabetical characters.\n");
        return 1;
    }
    
    string keyword = argv[1];
    
    string plainText = GetString();
    
    string encryptedMsg = encryptMsg(plainText, keyword);
    
    printf("%s\n", encryptedMsg);
    free(encryptedMsg);
    
    // Testing
    // printf("%i\n", getAlphaPos('a')); // 0
    // printf("%i\n", getAlphaPos('A')); // 0
    // printf("%i\n", getAlphaPos('z')); // 25
    // printf("%i\n", getAlphaPos('Z')); // 25
    // printf("%c\n", encryptLetter('A', 0)); // A
    // printf("%c\n", encryptLetter('a', 0)); // a
    // printf("%c\n", encryptLetter('A', 3)); // D
    // printf("%c\n", encryptLetter('a', 3)); // d
    // printf("%c\n", encryptLetter('Z', 3)); // C
    // printf("%c\n", encryptLetter('z', 3)); // c
}

string encryptMsg(const string plainText, const string keyword)
{
    char* encryptedMsg = malloc(strlen(plainText) + 1);
    int keywordLen = strlen(keyword);
    int pointer = 0;
    int keyPos = 0;
    
    for (int i = 0, len = strlen(plainText); i < len; i++)
    {
        encryptedMsg[pointer] = encryptLetter(plainText[i], getAlphaPos(keyword[keyPos % keywordLen]));
        pointer++;
        if (isalpha(plainText[i])) keyPos++;
    }
    
    encryptedMsg[pointer] = '\0';
    return encryptedMsg;
}

int getAlphaPos(const char letter)
{
    if ( isupper(letter) )
    {
        return letter % 'A';
    } else {
        return letter % 'a';
    }
}

char encryptLetter(const char letter, const int key)
{
    if (isalpha(letter))
    {
        int addedPos = letter + (key % MAX);
        if (isupper(letter))
        {
            int pos = (addedPos > 'Z') ? 'A' + (addedPos - 'Z') - 1 : letter + (key % MAX);
            return pos;
        } else {
            int pos = (addedPos > 'z') ? 'a' + (addedPos - 'z') - 1 : letter + (key % MAX);
            return pos;
        }
    } else {
        return letter;
    }
}

bool isAlphaStr(const string str)
{
    for (int i = 0, len = strlen(str); i < len; i++)
    {
        if( !isalpha(str[i]) ) return false;
    }
    return true;
}