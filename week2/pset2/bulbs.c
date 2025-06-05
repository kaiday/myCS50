#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void evaluate_message(string message);
void message_in_binary(int n);

int main(void)
{
    string message = get_string("Message: ");

    evaluate_message(message);
}

void evaluate_message(string message)
{
    int value;
    int n = strlen(message);

    for(int i=0; i<n; i++)
    {
        value = (int)message[i];
        message_in_binary(value);
        printf("\n");
    }
}


void message_in_binary(int n)
{
    int bin[8];
    int i=7;

    while(n>0)
    {
        bin[i]=n%2;
        n=n/2;
        i--;
    }

    for(i=0;i<8;i++)
    {
        if(bin[i]==1) printf("\U0001F7E1"); // yellow circle emoji

        else printf("\u26AB"); // dark circle emoji
    }

    for(i=0;i<8;i++)
    {
        bin[i]=0;
    }
}