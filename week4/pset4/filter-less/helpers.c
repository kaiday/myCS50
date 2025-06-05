#include "helpers.h"
#include <math.h>

#define MAX(a,b)             \
({                           \
    __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a > _b ? _a : _b;       \
})                           \

#define MIN(a,b)             \
({                           \
    __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a < _b ? _a : _b;       \
})                           \

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int convertvalue = 0;
    for(int i = 0; i < height ; i++)
    {
        for(int j = 0;  j < width ; j++)
        {
            RGBTRIPLE pixel = image[i][j];

            convertvalue = round((pixel.rgbtRed + pixel.rgbtGreen + pixel.rgbtBlue) / 3.0);

            image[i][j].rgbtGreen = image[i][j].rgbtBlue = image[i][j].rgbtRed = MIN(convertvalue,250);
            image[i][j].rgbtGreen = image[i][j].rgbtBlue = image[i][j].rgbtRed = MAX(convertvalue,0);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed = 0, sepiaGreen = 0, sepiaBlue = 0;
    for(int i = 0; i < height ; i++)
    {
        for(int j = 0;  j < width ; j++)
        {
            sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            image[i][j].rgbtRed = MAX(sepiaRed,0);
            image[i][j].rgbtRed = MIN(sepiaRed,255);

            image[i][j].rgbtGreen = MAX(sepiaGreen,0);
            image[i][j].rgbtGreen = MIN(sepiaGreen,255);

            image[i][j].rgbtBlue = MAX(sepiaBlue,0);
            image[i][j].rgbtBlue = MIN(sepiaBlue,255);

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;

    for(int i = 0; i < height ; i++)
    {
        for(int j = 0;  j < width/2 ; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width-j-1];
            image[i][width-j-1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    double average_red , average_green, average_blue;
    RGBTRIPLE copy[height][width];
    int count_number;
    int box = 1; // set 1 to have a 3x3 box

    //scanning the matriz
    for (int i = 0; i<height; ++i)
    {
        for(int j = 0; j<width;++j)
        {
            //cleaning the averages and the count number

            average_red = 0;
            average_blue = 0;
            average_green = 0;
            count_number = 0;

            //forming a 3x3 box
            for (int li = i-box; li<=i+box; ++li )
            {
                if( li < 0 )
                {
                    li = 0;
                }
                if( li == height)
                {
                    break;
                }

                for(int col = j-box; col<= j+box; col++)
                {

                    if (col == width ) break;
                    if (col < 0)
                    {
                        col = 0;
                    }

                    count_number++;

                    average_red += image[li][col].rgbtRed;
                    average_green += image[li][col].rgbtGreen;
                    average_blue += image[li][col].rgbtBlue;

                }

            }
            //set the new average to the pixel
            copy[i][j].rgbtRed = (int)round(average_red/count_number) ;
            copy[i][j].rgbtGreen = (int)round(average_green/count_number);
            copy[i][j].rgbtBlue = (int)round( average_blue/count_number );
        }
    }

    for (int i = 0; i<height; ++i)
    {
        for(int j = 0; j<width;++j)
        {
            image[i][j] = copy[i][j];
        }
    }
    return;
}
