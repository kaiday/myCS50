#include <stdio.h>
#include<cs50.h>
/*
- computers in the past are really slow -> can not give you an entire functions at once -> so you just need to include the founctions that you
really care about
- h stands for header files: contain enough information about all of the functions in what's called the Standard I/O Library.

--> this first "include" step is to tell the computer: I want to use functionality from the Standard I/O Library.
which is include "printf" in this case.
*/
int main(void){

    string first = get_string("What's your first name? ");
    string last = get_string("What's your last name? " );

    //string : a series of character

    printf("Hello %s %s!\n", first, last);

   // \n escape sequence -> move the cursor to the next line
   /*
   as you can see here the '%' is already used for coding -> if you want to literally  appear the '%" sign you have to type '%%'
   exp: printf("I got 100%"); -> not working

        printf("I got 100%%); -> work: I got 100%
   */
}
