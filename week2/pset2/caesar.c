#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool digit(string arg);
void encrypt(int k);

int main(int argc, string argv[])
{

    if(argc == 2 && digit(argv[1]))
    {
        encrypt(atoi(argv[1]));
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    return 0;
}
bool digit(string arg)
{
    for(int i=0; i<strlen(arg); i++)
    {
        if(isdigit(arg[i])) continue;
        else
        {
            printf("Usage: ./caesar key\n");
            return false;
        }
    }
    return true;
}

void encrypt(int k)
{
    int value, encrypt_value;
    char encrypt_char,Ciphertext[1000];
    string message = get_string("Plaintext:  ");
    strcpy(Ciphertext, message);
    for(int i=0; i<strlen(message); i++)
    {
        if(isupper(message[i]))
        {
            value = message[i] - 'A';
            encrypt_value = (value + k)%26;
            encrypt_char = encrypt_value + 'A';
            Ciphertext[i] = encrypt_char;
        }
        else if(islower(message[i]))
        {
            value = message[i] - 'a';
            encrypt_value = (value + k)%26;
            encrypt_char = encrypt_value + 'a';
            Ciphertext[i] = encrypt_char;
        }
    }
    printf("Ciphertext: %s\n",Ciphertext);
}