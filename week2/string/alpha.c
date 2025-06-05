#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int flag=0,i,n;
    string alpha = get_string("Alphabet: ");


    for(i=0, n=strlen(alpha); i<n; i++)
    {
        if(alpha[i] > alpha[i+1])
        {
            printf("No\n");
            return 0;
        }
    }

    printf("Yes\n");

}