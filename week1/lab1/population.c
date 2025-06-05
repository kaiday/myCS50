#include <stdio.h>
#include <cs50.h>

int llamas_start_size(void);
int llamas_end_size(int a);
int calculate_year(int a, int b);

int main(void)
{
    int a,b;

    a = llamas_start_size();
    b = llamas_end_size(a);
    if(a == b)
    {
        printf("Years: 0");
        return 0;
    }
    int year = calculate_year(a,b);
    printf("Years: %d",year);

}


int llamas_start_size(void)
{
    int n;
    do
    {
        n = get_int("Start size: ");
    }
    while(n<9);
    return n;
}


int llamas_end_size(int a)
{
    int n;
    do
    {
        n = get_int("End size: ");
    }
    while( n < a);
    return n;
}


int calculate_year(int a, int b)
{
    int year=0;
    int condition;
    do
    {
        a = a + a/3 - a/4;
        year++;
        condition = b - a;
        if(condition <= 0) break;
    }
    while(condition > 0);

    return year;
}
