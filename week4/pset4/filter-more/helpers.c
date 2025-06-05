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
            RGBTRIPLE pixel = image[i][j];

            sepiaRed = round(.393 * pixel.rgbtRed + .769 * pixel.rgbtGreen + .189 * pixel.rgbtBlue);
            sepiaGreen = round(.349 * pixel.rgbtRed + .686 * pixel.rgbtGreen + .168 * pixel.rgbtBlue);
            sepiaBlue = round(.272 * pixel.rgbtRed + .534 * pixel.rgbtGreen + .131 * pixel.rgbtBlue);

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
    double average_red, average_green, average_blue;
    RGBTRIPLE copy[height][width];
    int count_number;
    int box = 1; // set 1 to have a 3x3 box

    //scanning the matrix
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int Gx[3][3] = {{-1, 0, 1},
                    {-2, 0, 2},
                    {-1, 0, 1}};

    int Gy[3][3] = {{-1,-2,-1},
                    { 0, 0, 0},
                    { 1, 2, 1}};

    RGBTRIPLE copy[height][width];

    int box = 1; // set 1 to have a 3x3 box

    BYTE sumRed_x, sumRed_y, sumGreen_x, sumGreen_y, sumBlue_x, sumBlue_y;

    for (int i = 0; i<height; ++i)
    {
        for(int j = 0; j<width;++j)
        {

            sumRed_x = 0;
            sumRed_y = 0;
            sumGreen_x = 0;
            sumGreen_y = 0;
            sumBlue_x = 0;
            sumBlue_y = 0;

            //forming a 3x3 box
            for (int li = i-box; li<=i+box; ++li )
            {
                if( li < 0 )
                {
                    continue;
                }

                for(int col = j-box; col<= j+box; col++)
                {

                    if (col < 0)
                    {
                        continue;
                    }

                    RGBTRIPLE pixel = image[li][col];

                    sumRed_x += pixel.rgbtRed * Gx[li][col];
                    sumRed_y += pixel.rgbtRed * Gy[li][col];

                    sumGreen_x += pixel.rgbtGreen * Gx[li][col];
                    sumGreen_y += pixel.rgbtGreen * Gy[li][col];

                    sumBlue_x += pixel.rgbtBlue * Gx[li][col];
                    sumBlue_y += pixel.rgbtBlue * Gy[li][col];
                }

            }

            int finalRed = round(sqrt(sumRed_x*sumRed_x + sumRed_y*sumRed_y));
            int finalGreen = round(sqrt(sumGreen_x*sumGreen_x + sumGreen_y*sumGreen_y));
            int finalBlue = round(sqrt(sumBlue_x*sumBlue_x + sumBlue_y*sumBlue_y));

            copy[i][j].rgbtRed = MAX(finalRed,0);
            copy[i][j].rgbtRed = MIN(finalRed,255);

            copy[i][j].rgbtGreen =MAX(finalGreen,0);
            copy[i][j].rgbtGreen = MIN(finalGreen,255);

            copy[i][j].rgbtBlue =MAX(finalBlue,0);
            copy[i][j].rgbtBlue= MIN(finalBlue,255);
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

