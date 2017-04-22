/*
**************************************************************
* Created by Joshau Leung on 6 September 2016
*
* a program that encrypts messages using Caesar’s cipher.
*
*
**************************************************************/

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h> // atoi
#include <string.h>
#include <ctype.h> // isalpha, isupper, islower
#define MAX 26 // max num of alphebet 

/*
**************************************************************
*
* Using Caesar Cipher to encrypt messages
*
*
* @params: plainText, string, original message
*          key, int, key
*
* @return: encryptedMsg, string, encrypted message
*
**************************************************************/
string encryptMsg(const string plainText, int key);

int main(int argc, string argv[])
{
    if (argc != 2) 
    {
        printf("Usage: ./caesar <key>\n");
        return 1;    
    } else if (atoi(argv[1]) < 0) {
        printf("Key must be a non-negative integer.\n");
        return 2;
    }
    
    int key = atoi(argv[1]);
    
    string plainText = GetString();
    
    string encryptedMsg = encryptMsg(plainText, key);
    
    printf("%s\n", encryptedMsg);
    free(encryptedMsg);
}

string encryptMsg(const string plainText, int key)
{
    char* encryptedMsg = malloc(strlen(plainText) + 1);
    int pointer = 0;
    
    for (int i = 0, len = strlen(plainText); i < len; i++)
    {
        int addedPos = plainText[i] + (key % MAX);
        if (isupper(plainText[i]))
        {
            int pos = (addedPos > 'Z') ? 'A' + (addedPos - 'Z') - 1 : plainText[i] + (key % MAX);
            encryptedMsg[pointer] = pos;
        } else if (islower(plainText[i])) {
            int pos = (addedPos > 'z') ? 'a' + (addedPos - 'z') - 1 : plainText[i] + (key % MAX);
            encryptedMsg[pointer] = pos;
        } else {
            encryptedMsg[pointer] = plainText[i];
        }
        pointer++;
    }
    
    encryptedMsg[pointer] = '\0';
    return encryptedMsg;
}
