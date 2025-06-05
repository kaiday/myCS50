#include<stdio.h>
#include<cs50.h>
#include<math.h>

int number_of_digit(long int n);
void Card_Type(long int n);
int Luhn_Algorithm(int count,long int n);
int calculate_sum1(int count,long int n);
int calculate_sum2(int count,long int n);

int main(void)
{
    long int n;
    int count,status;
    do
    {
        n = get_long("Number: ");
    }while(n<0);

    count = number_of_digit(n);

    if(count>=13 && count <=16)
    {
        status = Luhn_Algorithm(count,n);
        if(status == 1) Card_Type(n);
        else printf("INVALID\n");
    }
    else printf("INVALID\n");
}


int number_of_digit(long int n)
{
    int count=0;
    do
    {
        n/=10;
        ++count;
    }while(n!=0);
    return count;
}


int Luhn_Algorithm(int count,long int n)
{
    int sum1,sum2;

    sum1 = calculate_sum1(count,n);
    sum2 = calculate_sum2(count,n);
    printf("%d",sum1+sum2);
    if( (sum1+sum2)%10 == 0 ) return 1;

    else return 0;
}


int calculate_sum1(int count,long int n)
{
    int i,sum=0;
    long m=100,x=10,r;
    for(i=0;i<count/2;i++)
    {
        r=n%m;
        n=n-r;
        r = r/x;
        x*=100;
        m*=100;
        if(r*2>=10) sum = sum + r*2 - 9;
        else sum = sum + r*2;
    }
    return sum;
}


int calculate_sum2(int count,long int n)
{
    int i,sum=0;
    long m=1,x=10,r;

    if(count%2 != 0) count+=1;

    for(i=0;i<count/2;i++)
    {
        r=n%x;
        n=n-r;
        r = r/m;
        x*=100;
        m*=100;
        sum +=r;
    }
    return sum;

}


void Card_Type(long int n)
{
      //-> the VISA card have 13 or 16 digit and all Visa numbers start with 4
      // so i divided input number by 13 digit number to check the first number
      if(n/1000000000000 == 4 || n/1000000000000000 == 4) printf("VISA\n");

      //-> American Express have 15 digit and always start with 34 or 37
      // so i divided input number by a 14 digit number to check the first two numbers
      else if(n/10000000000000 == 34 || n/10000000000000 == 37) printf("AMEX\n");

      //-> MasterCard have 16 digit and always start with 51, 52, 53, 54, or 55
      // so i divided input number by a 15 digit number to check the first two numbers
      else if(n/100000000000000 == 51 || n/100000000000000 == 52
      || n/100000000000000 == 53 || n/100000000000000 == 54
      || n/100000000000000 == 55 || n/100000000000000 == 22)
      printf("MASTERCARD\n");

      else printf("INVALID\n");

}