// Implements a dictionary's functionality
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 676;

// Hash table
node *table[N];

// Number of word in dictionary
int number_of_word = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    node *cursor = table[hash(word)] -> next;
    while(cursor != NULL)
    {
        if(strcasecmp(cursor -> word,word) == 0) return true;
        cursor = cursor -> next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int first_char_value = toupper(word[0]) - 'A';

    if(strlen(word) >= 2)
    {
        if(first_char_value  == 0) return (toupper(word[1]) - 'A');

        return (first_char_value *10 + toupper(word[1]) - 'A');
    }
    return first_char_value ;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *infile = fopen(dictionary, "r");
    if(!infile)
    {
        return false;
    }

    char buffer[LENGTH+1];
    while(fscanf(infile, "%s" ,buffer) == 1)
    {
        int index = hash(buffer);
        if(table[index] == NULL)
        {
            table[index] = malloc(sizeof(node));
            table[index] -> next = NULL;
        }

        number_of_word++;

        node *new = malloc(sizeof(node));
        strcpy(new -> word,buffer);

        new -> next = table[index] -> next;

        table[index] -> next = new;

    }

    fclose(infile);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return number_of_word;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node *tmp;
    node *current;

    for(int i = 0; i < N; i++)
    {
        if(table[i] != NULL)
        {
            tmp = current = table[i] -> next;

            while(current != NULL)
            {
                tmp = current;
                current = current -> next;
                free(tmp);
            }
            free(table[i]);
        }
    }


    return true;
}
