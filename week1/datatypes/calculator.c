#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long x = get_long("x= "); // "long" contains interger value but twice(64bit) as much as the "int"(32bit)
    long y = get_long("y= "); // "%li" is for long int
    printf("Sum is %li\n",x+y);

    double z = (double)x/ (double)y; // double is twice as much as float
    printf("Quotient is %.5lf\n",z);
}