#include <cs50.h>
#include <stdio.h>

int get_size(void);        // -> actually to hint the program the function that we use
void print_grid(int size);

int main(void)
{
    // Get the size of the grid
    int n = get_size();
    //Print the grid
    print_grid(n);


int get_size(void) // dont have input, but output
{
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while(n<1);
    return n;
}

void print_grid(int size) // dont have output, but input
{
    int i,j;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            printf("#");
        }
        printf("\n");
    }
}