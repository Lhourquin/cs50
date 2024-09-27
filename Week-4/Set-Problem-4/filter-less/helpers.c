#include "helpers.h"
#include <math.h>
#include <stdio.h>
/*
 *
 *
 BYTE  rgbtBlue;
 BYTE  rgbtGreen;
 BYTE  rgbtRed;
 * */
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i ++) {
        for (int j = 0; j < width; j++) {
            int average = round(round(image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen =  average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i ++) {
        for (int j = 0; j < width; j++) {
            int sepia_red = round(0.393 * image[i][j].rgbtRed + 0.769  * image[i][j].rgbtGreen+ 0.189 * image[i][j].rgbtBlue);
            int sepia_green = round(0.349 * image[i][j].rgbtRed + 0.686  * image[i][j].rgbtGreen+ 0.168 * image[i][j].rgbtBlue);
            int sepia_blue = round(0.272 * image[i][j].rgbtRed + 0.534  * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);

            image[i][j].rgbtRed = sepia_red >= 255 ? 255 : sepia_red;
            image[i][j].rgbtGreen = sepia_green >= 255 ? 255 : sepia_green;
            image[i][j].rgbtBlue = sepia_blue >= 255 ? 255 : sepia_blue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i ++) {
        int middle = round(width / 2);
        int idx = width - 1;
        for(int j = 0; j < middle; j++){
            int tmp_red = image[i][j].rgbtRed;
            int tmp_green = image[i][j].rgbtGreen;
            int tmp_blue = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = image[i][idx - j].rgbtRed;
            image[i][j].rgbtGreen = image[i][idx - j].rgbtGreen; 
            image[i][j].rgbtBlue = image[i][idx - j].rgbtBlue; 

            image[i][idx - j].rgbtRed = tmp_red;
            image[i][idx - j].rgbtGreen = tmp_green;
            image[i][idx - j].rgbtBlue = tmp_blue; 

        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i ++) {
        for(int j = 0; j < width; j++){
            copy[i][j] = image[i][j];
        }
    }


    for (int i = 0; i < height; i ++) {
        for(int j = 0; j < width; j++){
            int sum_of_red = 0;
            int sum_of_green = 0;
            int sum_of_blue = 0;
            int count = 0;

            for(int k = -1; k <= 1; k++){
                for(int l = -1; l <= 1; l++){
                    int row_idx = i + k;
                    int col_idx = j + l;

                    if(row_idx >= 0 && row_idx < height && col_idx >= 0 && col_idx < width){
                        sum_of_red = round(sum_of_red +  copy[row_idx][col_idx].rgbtRed);
                        sum_of_green = round(sum_of_green + copy[row_idx][col_idx].rgbtGreen);
                        sum_of_blue = round(sum_of_blue +  copy[row_idx][col_idx].rgbtBlue);
                        count++;
                    }

                }
            }
            

            image[i][j].rgbtRed = round(sum_of_red / count);
            image[i][j].rgbtGreen = round(sum_of_green / count);
            image[i][j].rgbtBlue = round(sum_of_blue / count);

        }
    }

    return;
} 
