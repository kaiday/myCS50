#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char c = get_char("Do you agree? \n");
    if(c == 'y'|| c == 'Y')

        // '&&' means if the 1st condition AND 2nd condition is met -> output
        // '||' means if the 1st conditions OR 2nd condition is met -> output

    {
        /* output -> */ printf("Agreed!\n");
    }
    else if (c == 'n' || c == 'N')
    {
       /* output -> */  printf("Disagreed!\n");
    }
}