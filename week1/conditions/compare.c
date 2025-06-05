#include <cs50.h>
#include<stdio.h>

int main(void)
{
     int x = get_int("Value x: ");
     int y = get_int("Value y: ");

        if (x > y)

            //(x>y) is a boolean expression which is true and false(yes/no)
            // a question that you're trying to ask in order to decide whether or not to do something.

         {
            printf("x is greater than y\n");
         }

         else if (y > x)
         {
            printf("y is greater than x\n");
         }

         else
         {
            printf("x is equal to y\n");
         }
}