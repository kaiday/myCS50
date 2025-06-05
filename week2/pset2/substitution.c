#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool condition(string arg);
void encrypt(string key);
bool valid_key(string input);

int main(int argc, string argv[])
{

    if(argc == 2 && condition(argv[1]))
    {
        encrypt(argv[1]);
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    return 0;
}

bool condition(string arg)
{
    if(strlen(arg) != 26)
    {
        printf("Key must contain 26 characters.\n");
        exit(1);
    }
    else if(!valid_key(arg))
    {
        printf("Key must contain 26 characters.\n");
        exit(1);
    }

    for(int i=0; i<strlen(arg); i++)
    {
        if(!isalpha(arg[i]))
        {
            printf("Key must contain 26 characters.\n");
            exit(1);
        }
    }
    return true;
}

bool valid_key(string input)
{
    int arr[27];

    for(int i = 0; i < strlen(input); i++)
    {
        if(isupper(input[i]))
        {
            arr[input[i] - 'A'] = arr[input[i] - 'A'] + 1;
        }
        else if(islower(input[i]))
        {
            arr[input[i] - 'a'] = arr[input[i] - 'a'] + 1;
        }
    }

    for(int i = 0; i < 27; i++)
    {
        if(arr[i] > 1)
        {
            return false;
        }
    }
    return true;
}

void encrypt(string key)
{
    char encrypt_char, encrypt_text[1000];
    string text = get_string("plaintext:  ");
    strcpy(encrypt_text,text);
    for(int i=0; i<strlen(text); i++)
    {
        if(isupper(text[i]))
        {
          encrypt_char = toupper(key[text[i] - 'A']);
          encrypt_text[i] = encrypt_char;
        }
        else if(islower(text[i]))
        {
          encrypt_char = tolower(key[text[i] - 'a']);
          encrypt_text[i] = encrypt_char;
        }
    }
    printf("ciphertext: %s\n",encrypt_text);
}
