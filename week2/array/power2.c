#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Size of array: ");
    }
    while(n<1);



    for(int i=1,num=1; i<=n; i++)
    {
        printf("number[%d]=%d\n", i,num);
        num*=2;
    }
    printf("\n");
}