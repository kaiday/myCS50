#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name = get_string("Name:");


    /*
    --> This is the manual way to make every lowercase in the string becomes uppercase

    int n = strlen(name);
    for(int i=0; i<n; i++)
    {
        if(name[i]>= 'a' && name[i]<= 'z')
        {
            printf("%c",name[i]-32);
        }
        else
        {
            printf("%c",name[i]);
        }
    }
    printf("\n");
    */

    // --> Other way is to use islower(name[i]) -> this will check if the character in string array is in lowercase

    //                         toupper(name[i]) -> this will turn every character in string array to uppercase.


    int n = strlen(name);
    
    for(int i=0; i<n; i++)
    {
        printf("%c",toupper(name[i]));
    }
    printf("\n");

}