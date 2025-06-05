#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
    char* s = get_string("String1: ");

    /*
    char* t = malloc(strlen(s) +1);
    function "malloc" and get_string return a value NULL (not NUL) is a pointer that have address 0 if something goes wrong
    */
    if(s == NULL )
    {
        return 1;  //exist now so the error stop at early
    }

    char* t = malloc(strlen(s) +1); // create a free chunk a memory for t with (strlen(s) + 1) bytes in memory the +1 is for the NUL "\0" character.

    if(t == NULL)
    {
        return 1;
    }


    /*
    string t = s; -> wrong
     you cannot copy a string by using "=" like string t = s
     -> this will be understand by computer that copy the address of s to t.
     so if u do any action on one of the string s or t, it will effect both string
     -> because they have the same address
     */

    /*
    in order to copy one string to another, not the address but each element of one string to another, we will use "malloc" and "free"*/

    /* 1st way to copy string s to string t
    for(int i=0, n = strlen(s) + 1; i < n; i++) // again +1 is for the NUL "\0" character to know the end of the string
    {
        t[i] = s[i];
    }
    */


    // an efficient way to copy string s to string t is using function "strcpy", but u are only able to use it
    // when u already allocate the memory using malloc function, otherwise strcpy will fail

    strcpy(t,s);


    if(strlen(t) > 0) // to advoid segmentation false, you need to consider if string t have any characters enable to uppercase a character
    {
        t[0] = toupper(t[0]);
    }


    printf("s: %s\n",s);
    printf("t: %s\n",t);

    free(t); // won't use string anymore, u must free it

    return 0;
}
