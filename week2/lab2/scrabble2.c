#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 27

int compute_value(char word[],int point[]);

int main(void)
{
    int point[MAX]={1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};

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
    int score=0;

    for(int i = 0, n = strlen(word); i<n; i++)
    {
        if(isupper(word[i]))
        {
            score += point[word[i] - 65];
        }
        else if(islower(word[i]))
        {
            score += point[word[i] - 'a'];
        }
    }
    return score;
}