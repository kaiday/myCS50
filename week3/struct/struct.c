#include <stdio.h>
#include <cs50.h>
#include <string.h>

/*
    struct allow us to store different kind of data types in a party

    STRUCT IS DECLARE OUTSIDE OF MAIN

    typedef struct -> typedef in C means you allow to define your own variables;
    {
        string (____);
        int (____);
        => you can have mutiple information, make sure they have different names.
    }
    struct_name; (struct variable)

-> Examples:

    typedef struct
    {
        string name;
        string number;
    }
    person;

    person people[2];

    people[0].name = "Carter";
    people[0].number = "0123243546576";

    people[1].name = "Anvil";
    people[1].number = "0867574341234";

    string name = get_string("Name: ");

    for(int i=0; i<2; i++)
    {
        if(strcmp(people[i].name,name) == 0)
        {
            printf("Found %s! Here is the number: %s \n",people[i].name,people[i].number);
            return 0;
        }
    }
    printf("Not found! \n");
    return 1;
*/


typedef struct
{
    string name;
    int vote;
}
candidates;

candidates get_candidates(string prompt);

int main(void)
{
    candidates president = get_candidates("Enter a candidate");
    printf("President's name: %s\n",president.name);
    printf("President's votes: %d\n",president.vote);
}

candidates get_candidates(string prompt)
{
    printf("%s\n",prompt);
    candidates a;
    a.name = get_string("Name: ");
    a.vote = get_int("Votes: ");
    return a;
}

