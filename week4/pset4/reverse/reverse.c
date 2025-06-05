#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"
#define HEADER_SIZE 44

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if(argc > 3 || argc < 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    char *filename = argv[1];
    FILE *inptr = fopen(filename, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", filename);
        fclose(inptr);
        return 4;
    }

    // Read header
    // TODO #3
    WAVHEADER buffer;
    fread(&buffer, HEADER_SIZE, 1, inptr);

    long header_pointer = ftell(inptr);

    // Use check_format to ensure WAV format
    // TODO #4
    if(check_format(buffer) == 0)
    {
        printf("Input is not a WAV file.\n");
        return 1;
    }

    // Open output file for writing
    // TODO #5
    char *outfile = argv[2];
    FILE *outptr = fopen(outfile, "w");
    if(outptr == NULL)
    {
        printf("Could not create %s.\n", outfile);
        fclose(outptr);
        return 4;
    }

    // Write header to file
    // TODO #6
    fwrite(&buffer, HEADER_SIZE, 1, outptr);

    // Use get_block_size to calculate size of block
    // TODO #7
    int BLOCK_SIZE = get_block_size(buffer);

    // Write reversed audio to file
    // TODO #8
    BYTE rebuffer[BLOCK_SIZE];
    long current_pointer = 0;

    fseek(inptr, - BLOCK_SIZE, SEEK_END);

    do
    {
        fread(rebuffer, 1, BLOCK_SIZE, inptr);
        fwrite(rebuffer, 1, BLOCK_SIZE, outptr);
        fseek(inptr, - BLOCK_SIZE * 2, SEEK_CUR);
        current_pointer = ftell(inptr);
    }
    while(current_pointer >= header_pointer);

    fclose(inptr);
    fclose(outptr);
}

int check_format(WAVHEADER header)
{
    // TODO #4
    if(header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
        return 1;
    }
    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return  header.numChannels * 0.125 * header.bitsPerSample;

}