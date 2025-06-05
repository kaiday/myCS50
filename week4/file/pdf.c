#include <stdio.h>
#include <stdint.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Improper Usage\n");
        return 1;
    }

    // Open file
    string filename = argv[1]; // given filename from input
    FILE *file = fopen(filename, "r"); // open a file with given filename that user type in and open for reading "r"

    if(file == NULL) // check if such file exists
    {
        printf("No such file found.\n");
        return 1;
    }

    uint8_t buffer[4]; // unit8 means unsigned integer 8 bit (1 byte integer) _t means its very own type -> this is the special type of data
    uint8_t signature[] = {67, 65, 82, 84};

    fread(buffer, 1, 4, file); // the size of the block is 1 byte, and read 4 blocks and read from a file pointer above
    fclose(file); // since u call fopen, u should close it otherwise it would cause a memory leak which is other program would use the same data left behind
    // You can add "valgrind" before "./" to check if any possible error may occur

    // Does the buffer matches the signature in this case it should be the first 4 character/number should be 67 65 82 84
    // Otherwise, it's not a pdf/text file
    for(int i = 0; i < 4 ; i++)
    {
        if(buffer[i] != signature[i])
        {
            printf("Not likely a PDF.\n");
            return 0;
        }
    }
    printf("Likely a PDF.\n");

    return 0;
}