#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{

    if(argc > 2 || argc == 1)
    {
        printf("Usage: ./recover IMAGE");
        return 1;
    }

    // open input file
    char *infile = argv[1];

    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        fclose(inptr);
        return 4;
    }

    uint8_t buffer[BLOCK_SIZE];
    int i = 0;

    bool JPEG_header_found = false;
    bool write = false;

    FILE * file = NULL;

    char* filename = malloc(8);
    if(filename == NULL)
    {
        return 1;
    }

    while(fread(buffer, 1, BLOCK_SIZE, inptr) == BLOCK_SIZE)
    {
        write = false;

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            JPEG_header_found = true;
            if(i >= 1)
            {
                fclose(file);
            }
        }

        if(JPEG_header_found)
        {
            sprintf(filename, "%03i.jpg",i);
            file = fopen(filename, "w");
            JPEG_header_found = false;
            write = true;
            i++;
        }

        if(write)
        {
            fwrite(buffer, 1, BLOCK_SIZE, file);
        }
    }

    free(filename);
    fclose(inptr);
    fclose(file);


}