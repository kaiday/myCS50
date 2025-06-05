#include<stdio.h>
#include<cs50.h>

int get_cents(void);
int calculate_quarters(int n);
int calculate_dimes(int n);
int calculate_nickels(int n);
int calculate_pennies(int n);


int main(void)
{
    int n = get_cents();
    if(n == 0)
    {
        printf("0");
        return 0;
    }
    int quarter = calculate_quarters(n);                                    // a quarter = 25 cents
    int dime = calculate_dimes(n - quarter*25);                             // a dime = 10 cents
    int nickel = calculate_nickels(n - quarter*25 - dime*10);               // a nickel = 5 cents
    int penny = calculate_pennies(n - quarter*25 - dime*10 - nickel*5);     // a penny = 1 cent

    int coin = quarter + dime + nickel + penny;

    if(coin <= 1) printf("%d\n",coin);
    else printf("%d\n", coin);
}


int get_cents(void)
{
    int n;
    do
    {
       n = get_int("Change owed: ");
    }
    while(n<0);
    return n;
}


int calculate_quarters(int n)
{
    int count = 0;
    if(n == 25) return 1;
    if(n > 25)
    {
        while(n>=25)
        {
            n=n-25;
            count++;
            if(n == 0) break;
        }
        return count;
    }
    else return 0;
}


int calculate_dimes(int n)
{
    int count = 0;
    if(n == 10) return 1;
    if(n > 10)
    {
        while(n>=10)
        {
            n=n-10;
            count++;
            if(n == 0) break;
        }
        return count;
    }
    else return 0;
}


int calculate_nickels(int n)
{
    int count = 0;
    if(n == 5) return 1;
    if(n >= 5)
    {
        while(n >= 5)
        {
            n = n-5;
            count++;
            if(n == 0) break;
        }
        return count;
    }
    else return 0;
}


int calculate_pennies(int n)
{
    int count = 0;
    if(n == 1) return 1;
    while(n >= 25)
    {
        n-=25;
    }
    while(n >= 10)
    {
        n-=10;
    }
    while(n >= 5)
    {
        n-=5;
    }
    if(n >= 1)
    {
        while(n >= 1)
        {
            n-=1;
            count++;
            if(n == 0) break;
        }
        return count;
    }
    else return 0;
}