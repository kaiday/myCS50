#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i,n,j,a;
    do
    {
    n = get_int("Height: ");
    }while(n<1 || n>8);

    for(i=0;i<n;i++)
    {
        j=i;
        a=n-i;

        for(a=n;a>i+1;a--)
        {
            printf(" ");
        }
        for(j=0;j<=i;j++)
        {
            printf("#");
        }
        printf("\n");
    }
}