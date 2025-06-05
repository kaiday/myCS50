#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int number_of_words(string text);
float average_number_of_letters(string text,int word);
float average_number_of_sentences(string text, int word);


int main(void)
{
    string text = get_string("Sentence: ");

    int n = number_of_words(text);
    float L = average_number_of_letters(text,n); // per 100 words
    float S = average_number_of_sentences(text,n); // per 100 words

    float index = 0.0588 * L - 0.296 * S - 15.8; // Coleman-Liau index
    if(index < 0) printf("Before Grade 1\n");
    else if(index >= 16) printf("Grade 16+\n");
    else printf("Grade %.0f\n",index);
}

int number_of_words(string text)
{
    int count = 1;
    for(int i=0, n=strlen(text); i<n; i++)
    {
        if(isspace(text[i])) count++;
    }
    return count;
}

float average_number_of_letters(string text, int word)
{
    int count = 0;
    int n=strlen(text);
    for(int i=0; i<n; i++)
    {
        if(isalpha(text[i])) count++;
    }

    float L = (float) count/word * 100; // calculate how many letters per 100 words
    return L;
}

float average_number_of_sentences(string text, int word)
{
    int count = 0;
    int n=strlen(text);
    for(int i=0; i<n; i++)
    {
        if( (text[i] == '.' || text[i] == '!' || text[i] == '?') && text[i+1] == ' ') count++;
    }

    float S = (float) (count+1)/word * 100; // calculate how many sentences per 100 words
    return S;
}



