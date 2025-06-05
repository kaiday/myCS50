#include <cs50.h>
#include <stdio.h>

void draw(int n);
int frac(int n);
void fib(int n);
void printFib(int n);
// first two values
int prev1 = 1;
int prev2 = 0;

int main(void)
{
    int height = get_int("Size of triagle:");
    int n = get_int("Fractorial of ");
    int f = get_int("Fibonacci sequence to the element of ");
    draw(height);
    printf("Fractorial of %d is %d.\n",n,frac(n));
    printf("Fibonacci sequence to the %d element:  ",f);
    printFib(f);
    printf("\n");
}

void draw(int n)
{
    if(n<=0)
    {
        return;
    }
    draw(n-1);

    for(int i=0; i<n; i++)
    {
        printf("#");
    }
    printf("\n");

}

int frac(int n)
{
    if(n==1) return 1;

    return n* frac(n-1);
}



// recusive function to print the fibonacci series
void fib(int n)
{
	if (n < 3) {
		return;
	}
	int fn = prev1 + prev2;
	prev2 = prev1;
	prev1 = fn;
	printf("%d ", fn);
	return fib(n - 1);
}

void printFib(int n)
{
	// when the number of terms is less than 1
	if (n < 1) {
		printf("Invalid number of terms\n");
	}
	// when the number of terms is 1
	else if (n == 1) {
		printf("%d ", 0);
	}
	// when the number of terms is 2
	else if (n == 2) {
		printf("%d %d", 0, 1);
	}
	// number of terms greater than 2
	else {
		printf("%d %d ", 0, 1);
		fib(n);
	}
	return;
}
