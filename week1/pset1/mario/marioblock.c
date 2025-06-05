#include <cs50.h>
#include <stdio.h>
int main(void)
{
    int n,i,j;
    do
    {
       n = get_int("Size= ");
    }while(n<1);

    for (i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("#");
        }
        printf("\n");
    }
}