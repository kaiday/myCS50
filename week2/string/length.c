#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string name = get_string("Name:");

    /*
    --> This is the manual way to calculate lenght of string.

    int n = 0;
    while(name[n] != '\0')
    {
            n++;
    }
    printf("Length of string: %i\n",n);

    */




   // --> Other way is use strlen() in <string.h> library

   int n = strlen(name);     //  -> how many character in string

   printf("Length of string: %i\n",n);

}