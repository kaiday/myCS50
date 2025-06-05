#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main (void)
{
    string s = get_string("String1: ");
    string t = get_string("String2: ");

    /*
     you cannot copy a string by using "=" like string t = s;
     -> this will be understand by computer that both s and t have the same addresses
     so to copy a string -> use strcpy(string2, string1); in <string.h> header file -> copy string1 to string2
     */
    /*
    - to compare to string , we cannot use if(s == t) because the computer will compare the differences of address
    not the value inside that string
    - if u think (*s == *t) will work but it won't work correctly because it will only compare the first value of
    the string (beacuse as u know pointer always points at the first element of the string)
    -> so it will only compare the differences of the first element of two strings, not the whole string
    */

    if(strcmp(s,t) == 0)
    {
        printf("Same\n");
        return 1;
    }
    else
    {
        printf("Different\n");
        return 0;
    }

}