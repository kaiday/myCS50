#include <cs50.h>
#include <stdio.h>

/* int main(void) // -> void inside the parentheses () means this take no command line arguments.
{
    string name = get_string("Name:");
    printf("Hello, %s\n",name);
}
*/
/*
    previous code in order to run it,
    you need to fisrt compile it and then run it and wait for it to finish running
    and then you can type in input (which is "name")
*/

int main(int argc, string argv[])    // --> argc stands for argument count and contains the number of arguments passed to the program
                                     //     argv stands for argument vector and is a one-dimensional array of strings that store the arguments

//-> int in the start of the main is to return an int for an exit status. This is for advanced programmer to check if the exit status is expected.
{
    if(argc == 2)
    {
    printf("Hello, %s\n",argv[1]);
    return 1; // you can run echo $? to check the return value (or exit status) is as expected, which is 1 in this case
    }

    else
    {
    printf("Hey! Just your first name.\n");
    return 0; // you can run echo $? to check, which is 0 in this case
    }
}