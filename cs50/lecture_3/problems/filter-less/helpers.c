#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
//For a color to be in the gray scale, the value of r,g,b, have to be the same.
//To dicide to what value we need to set each color, we have to extract the values
//find their average, round it and set each color to it.
//./filter -g infile.bmp outfile.bmp
/*BYTE  rgbtBlue;
    BYTE  rgbtGreen;
    BYTE  rgbtRed;*/
{

    float average;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            average =
            (image[i][j].rgbtBlue+
            image[i][j].rgbtGreen+
            image[i][j].rgbtRed)/3;

            average = (int)(average + 0.5);

            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;

        }
    }
    return;
}

// Convert image to sepia

void sepia(int height, int width, RGBTRIPLE image[height][width])
//use sepia formula, cap at 255 if the new value is over 255
//./filter -s infile.bmp outfile.bmp
{
    int sepiaRed;
    int sepiaGreen;
    int sepiaBlue;
    float average;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){


            sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;        image[i][j].rgbtBlue = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaBlue;


        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
//swich position of every pixel
//if odd middle doesnt move
//./filter -r infile.bmp outfile.bmp
{
     int red;
     int green;
     int blue;
     for(int i = 0; i <= height; i++){
        for(int j = 0; j <= width/2; j++){

            blue = image[i][j].rgbtBlue;
            green = image[i][j].rgbtGreen;
            red = image[i][j].rgbtRed;

            image[i][j].rgbtBlue = image[i][width - j].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - j].rgbtRed;
            image[i][width - j].rgbtBlue = blue;
            image[i][width - j].rgbtGreen = green;
            image[i][width - j].rgbtRed = red;

        }
     }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])

{
    RGBTRIPLE new[height][width];
     for(int i = 0; i <= height; i++){
        for(int j = 0; j <= width; j++){

            if(i != 0 && i != height){
                if(j != 0 && j != width){
                    new[i][j].rgbtBlue =
                    (int)((image[i - 1][j].rgbtBlue +
                    image[i - 1][j+1].rgbtBlue +
                    image[i - 1][j - 1].rgbtBlue +
                    image[i + 1][j].rgbtBlue +
                    image[i + 1][j - 1].rgbtBlue +
                    image[i + 1][j + 1].rgbtBlue +
                    image[i][j - 1].rgbtBlue +
                    image[i][j + 1].rgbtBlue +
                    image[i][j].rgbtBlue
                    )/9 + 0.5);

                    new[i][j].rgbtGreen =
                    (int)((image[i - 1][j].rgbtGreen +
                    image[i - 1][j + 1].rgbtGreen +
                    image[i - 1][j - 1].rgbtGreen +
                    image[i + 1][j].rgbtGreen +
                    image[i + 1][j - 1].rgbtGreen +
                    image[i + 1][j + 1].rgbtGreen +
                    image[i][j - 1].rgbtGreen +
                    image[i][j + 1].rgbtGreen +
                    image[i][j].rgbtGreen) / 9 + 0.5);

                    new[i][j].rgbtRed =
                    (int)((image[i - 1][j].rgbtRed +
                    image[i - 1][j + 1].rgbtRed +
                    image[i - 1][j - 1].rgbtRed +
                    image[i + 1][j].rgbtRed +
                    image[i + 1][j - 1].rgbtRed +
                    image[i + 1][j + 1].rgbtRed +
                    image[i][j - 1].rgbtRed +
                    image[i][j + 1].rgbtRed +
                    image[i][j].rgbtRed) / 9 + 0.5);

             }
            }

            image[i][j].rgbtBlue = new[i][j].rgbtBlue;
            image[i][j].rgbtGreen =new[i][j].rgbtGreen;
            image[i][j].rgbtRed = new[i][j].rgbtRed;

        }
     }
    return;
}
