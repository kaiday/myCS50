#include<stdio.h>
#include<cs50.h>
int main(void)
{
    int i,j,n;
    do
    {
        n = get_int("Size:");
    }
    while(n<=0 || n>100);

    for(i=0; i<n; i++)
    {
        for(j=0; j<=i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
}