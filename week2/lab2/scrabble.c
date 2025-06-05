#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 8

int compute_value(char word[],int point[]);

int main(void)
{
    int point[MAX]={0,1,2,3,4,5,8,10};

    string word1 = get_string("Player 1:");
    string word2 = get_string("Player 2:");

    int p1 = compute_value(word1,point);
    int p2 = compute_value(word2,point);

    if(p1>p2) printf("Player 1 wins!\n");
    else if(p1<p2) printf("Player 2 wins!\n");
    else printf("Tie!\n");

}

int compute_value(char word[],int point[])
{
    int p,sum=0;
    for(int i=0, n=strlen(word); i<n; i++)
    {
        if(isalpha(word[i]))
        {
            if(word[i] == 'D' || word[i] == 'd' || word[i] == 'G' || word[i] == 'g')
            {
                p = point[2]; // worth 2 points
                sum = sum + p;
            }

            else if(word[i] == 'B' || word[i] == 'b' || word[i] == 'C' || word[i] == 'c'
            || word[i] == 'M' || word[i] == 'm' || word[i] == 'P' || word[i] == 'p')
            {
                p = point[3]; // worth 3 points
                sum = sum + p;
            }

            else if(word[i] == 'F' || word[i] == 'f' || word[i] == 'H' || word[i] == 'h'
            || word[i] == 'V' || word[i] == 'v' || word[i] == 'W' || word[i] == 'w'
            || word[i] == 'Y' || word[i] == 'y')
            {
                p = point[4]; // worth 4 points
                sum = sum + p;
            }

            else if(word[i] == 'K' || word[i] == 'k')
            {
                p = point[5]; // worth 5 points
                sum = sum + p;
            }

            else if(word[i] == 'J' || word[i] == 'j' || word[i] == 'X' || word[i] == 'x')
            {
                p = point[6]; // worth 8 points
                sum = sum + p;
            }

            else if(word[i] == 'Q' || word[i] == 'q' || word[i] == 'Z' || word[i] == 'z')
            {
                p = point[7]; // worth 10 points
                sum = sum + p;
            }
            else
            {
                p = point[1]; // worth 1 point
                sum = sum + p;
            }
        }
    }
    return sum;
}

