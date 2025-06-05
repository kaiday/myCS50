#include <cs50.h>
#include <stdio.h>

bool square_triangle(int a, int b, int c);
bool valid_triangle(int a, int b, int c);

int main(void)
{
    int x,y,z;
    do
    {
        x = get_int("Side 1: ");
        y = get_int("Side 2: ");
        z = get_int("Side 3: ");
    }while(x<0);

    if(valid_triangle(x,y,z))
    {
        printf("Valid triangle\n");
        if(square_triangle(x*x,y*y,z*z)) printf("and square\n");
        else printf("but not square\n");
    }
    else printf("Invalid triangle\n");
}

bool square_triangle(int a, int b, int c)
{
    if(a+b==c || b+c==a || c+a==b) return 1;
    else return 0;
}

bool valid_triangle(int a, int b, int c)
{
    if(a+b>c && a+c>b && b+c>a) return 1;
    else return 0;
}