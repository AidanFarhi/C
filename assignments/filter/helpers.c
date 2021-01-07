#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate through every cell in the matrix
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Get average of all the color values
            float avg = ((float)image[i][j].rgbtBlue + (float)image[i][j].rgbtGreen + (float)image[i][j].rgbtRed) / (float)3;
            // Set all colors to average
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = round(avg);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // reverse each row of the matrix. i = row
    for (int i = 0; i < height; i++)
    {
        int start = 0;
        int end = width - 1;
        while (start < end)
        {
            int t_red = image[i][start].rgbtRed;
            int t_blue = image[i][start].rgbtBlue;
            int t_green = image[i][start].rgbtGreen;
            image[i][start].rgbtRed = image[i][end].rgbtRed;
            image[i][start].rgbtBlue = image[i][end].rgbtBlue;
            image[i][start].rgbtGreen = image[i][end].rgbtGreen;
            image[i][end].rgbtRed = t_red;
            image[i][end].rgbtBlue = t_blue;
            image[i][end].rgbtGreen = t_green;
            // swap(i, start, end, image)
            start++;
            end--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Make a copy of the array to fill with blurred values
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //                  UL U  UR R  LR D  LL L
            int neighbors[8] = {0, 0, 0, 0, 0, 0, 0, 0};
            int row = i;
            int col = j;
            // Check Upper Left
            if (row > 0 && col > 0)
            {
                neighbors[0] = 1;
            }
            // Check Up
            if (row > 0)
            {
                neighbors[1] = 1;
            }
            // Check Upper right
            if (row > 0 && col < width - 1)
            {
                neighbors[2] = 1;
            }
            // Check Right
            if (col < width - 1)
            {
                neighbors[3] = 1;
            }
            // Check Lower Right
            if (row < height - 1 && col < width - 1)
            {
                neighbors[4] = 1;
            }
            // Check Down
            if (row < height - 1)
            {
                neighbors[5] = 1;
            }
            // Check Lower Left
            if (row < height - 1 && col > 0)
            {
                neighbors[6] = 1;
            }
            // Check Left
            if (col > 0)
            {
                neighbors[7] = 1;
            }
            // get_neighbors(i, j, height, width, neighbors);
            int valid_neighbors = 1;
            int rd_total = image[row][col].rgbtRed;
            int gr_total = image[row][col].rgbtGreen;
            int bl_total = image[row][col].rgbtBlue;
            for (int n = 0; n < 8; n++) // Iterate through neighbors, checking for valid neighbors.
            {
                if (neighbors[n] == 1) // Neighbor is valid
                {
                    // Increment valid neighbors
                    valid_neighbors++;
                    // Get the RGB from neighbor
                    int colors[3] = {0, 0, 0};
                    int neighbor = n;
                    if (neighbor == 0) // UL
                    {
                        colors[0] = image[row - 1][col - 1].rgbtRed;
                        colors[1] = image[row - 1][col - 1].rgbtGreen;
                        colors[2] = image[row - 1][col - 1].rgbtBlue;
                    }
                    if (neighbor == 1) // U
                    {
                        colors[0] = image[row - 1][col].rgbtRed;
                        colors[1] = image[row - 1][col].rgbtGreen;
                        colors[2] = image[row - 1][col].rgbtBlue;
                    }
                    if (neighbor == 2) // UR
                    {
                        colors[0] = image[row - 1][col + 1].rgbtRed;
                        colors[1] = image[row - 1][col + 1].rgbtGreen;
                        colors[2] = image[row - 1][col + 1].rgbtBlue;
                    }
                    if (neighbor == 3) // R
                    {
                        colors[0] = image[row][col + 1].rgbtRed;
                        colors[1] = image[row][col + 1].rgbtGreen;
                        colors[2] = image[row][col + 1].rgbtBlue;
                    }
                    if (neighbor == 4) // LR
                    {
                        colors[0] = image[row + 1][col + 1].rgbtRed;
                        colors[1] = image[row + 1][col + 1].rgbtGreen;
                        colors[2] = image[row + 1][col + 1].rgbtBlue;
                    }
                    if (neighbor == 5) // D
                    {
                        colors[0] = image[row + 1][col].rgbtRed;
                        colors[1] = image[row + 1][col].rgbtGreen;
                        colors[2] = image[row + 1][col].rgbtBlue;
                    }
                    if (neighbor == 6) // LL
                    {
                        colors[0] = image[row + 1][col - 1].rgbtRed;
                        colors[1] = image[row + 1][col - 1].rgbtGreen;
                        colors[2] = image[row + 1][col - 1].rgbtBlue;
                    }
                    if (neighbor == 7) // L
                    {
                        colors[0] = image[row][col - 1].rgbtRed;
                        colors[1] = image[row][col - 1].rgbtGreen;
                        colors[2] = image[row][col - 1].rgbtBlue;
                    }
                    // get_vals_from_neighbor(n, i, j, image, colors);
                    // Add colors to average
                    rd_total += colors[0];
                    gr_total += colors[1];
                    bl_total += colors[2];
                }
            }
            // Now set the colors current cell to be the average of all the neighbors
            copy[i][j].rgbtRed = round((float)rd_total / (float)valid_neighbors);
            copy[i][j].rgbtGreen = round((float)gr_total / (float)valid_neighbors);
            copy[i][j].rgbtBlue = round((float)bl_total / (float)valid_neighbors);
        }
    }
    // Copy results into original image matrix
    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            image[k][l] = copy[k][l];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Make a copy of the array to fill with blurred values
    RGBTRIPLE copy[height][width];

    int Gx[8] = {-1, 0, 1, 2, 1, 0, -1, -2};
    int Gy[8] = {-1, -2, -1, 0, 1, 2, 1, 0};
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //                  UL U  UR R  LR D  LL L
            int neighbors[8] = {0, 0, 0, 0, 0, 0, 0, 0};
            int row = i;
            int col = j;
            // Check Upper Left
            if (row > 0 && col > 0)
            {
                neighbors[0] = 1;
            }
            // Check Up
            if (row > 0)
            {
                neighbors[1] = 1;
            }
            // Check Upper right
            if (row > 0 && col < width - 1)
            {
                neighbors[2] = 1;
            }
            // Check Right
            if (col < width - 1)
            {
                neighbors[3] = 1;
            }
            // Check Lower Right
            if (row < height - 1 && col < width - 1)
            {
                neighbors[4] = 1;
            }
            // Check Down
            if (row < height - 1)
            {
                neighbors[5] = 1;
            }
            // Check Lower Left
            if (row < height - 1 && col > 0)
            {
                neighbors[6] = 1;
            }
            // Check Left
            if (col > 0)
            {
                neighbors[7] = 1;
            }
            // Get the Gx values
            int rd_sum_x = 0;
            int gr_sum_x = 0;
            int bl_sum_x = 0;
            // Get the Gy values
            int rd_sum_y = 0;
            int gr_sum_y = 0;
            int bl_sum_y = 0;
            for (int x = 0; x < 8; x++)
            {
                if (neighbors[x] == 1)
                {
                    int neighbor = x;
                    if (neighbor == 0) // UL
                    {
                        rd_sum_x += image[row - 1][col - 1].rgbtRed * Gx[x];
                        gr_sum_x += image[row - 1][col - 1].rgbtGreen * Gx[x];
                        bl_sum_x += image[row - 1][col - 1].rgbtBlue * Gx[x];
                        rd_sum_y += image[row - 1][col - 1].rgbtRed * Gy[x];
                        gr_sum_y += image[row - 1][col - 1].rgbtGreen * Gy[x];
                        bl_sum_y += image[row - 1][col - 1].rgbtBlue * Gy[x];
                    }
                    if (neighbor == 1) // U
                    {
                        rd_sum_x += image[row - 1][col].rgbtRed * Gx[x];
                        gr_sum_x += image[row - 1][col].rgbtGreen * Gx[x];
                        bl_sum_x += image[row - 1][col].rgbtBlue * Gx[x];
                        rd_sum_y += image[row - 1][col].rgbtRed * Gy[x];
                        gr_sum_y += image[row - 1][col].rgbtGreen * Gy[x];
                        bl_sum_y += image[row - 1][col].rgbtBlue * Gy[x];
                    }
                    if (neighbor == 2) // UR
                    {
                        rd_sum_x += image[row - 1][col + 1].rgbtRed * Gx[x];
                        gr_sum_x += image[row - 1][col + 1].rgbtGreen * Gx[x];
                        bl_sum_x += image[row - 1][col + 1].rgbtBlue * Gx[x];
                        rd_sum_y += image[row - 1][col + 1].rgbtRed * Gy[x];
                        gr_sum_y += image[row - 1][col + 1].rgbtGreen * Gy[x];
                        bl_sum_y += image[row - 1][col + 1].rgbtBlue * Gy[x];
                    }
                    if (neighbor == 3) // R
                    {
                        rd_sum_x += image[row][col + 1].rgbtRed * Gx[x];
                        gr_sum_x += image[row][col + 1].rgbtGreen * Gx[x];
                        bl_sum_x += image[row][col + 1].rgbtBlue * Gx[x];
                        rd_sum_y += image[row][col + 1].rgbtRed * Gy[x];
                        gr_sum_y += image[row][col + 1].rgbtGreen * Gy[x];
                        bl_sum_y += image[row][col + 1].rgbtBlue * Gy[x];
                    }
                    if (neighbor == 4) // LR
                    {
                        rd_sum_x += image[row + 1][col + 1].rgbtRed * Gx[x];
                        gr_sum_x += image[row + 1][col + 1].rgbtGreen * Gx[x];
                        bl_sum_x += image[row + 1][col + 1].rgbtBlue * Gx[x];
                        rd_sum_y += image[row + 1][col + 1].rgbtRed * Gy[x];
                        gr_sum_y += image[row + 1][col + 1].rgbtGreen * Gy[x];
                        bl_sum_y += image[row + 1][col + 1].rgbtBlue * Gy[x];
                    }
                    if (neighbor == 5) // D
                    {
                        rd_sum_x += image[row + 1][col].rgbtRed * Gx[x];
                        gr_sum_x += image[row + 1][col].rgbtGreen * Gx[x];
                        bl_sum_x += image[row + 1][col].rgbtBlue * Gx[x];
                        rd_sum_y += image[row + 1][col].rgbtRed * Gy[x];
                        gr_sum_y += image[row + 1][col].rgbtGreen * Gy[x];
                        bl_sum_y += image[row + 1][col].rgbtBlue * Gy[x];
                    }
                    if (neighbor == 6) // LL
                    {
                        rd_sum_x += image[row + 1][col - 1].rgbtRed * Gx[x];
                        gr_sum_x += image[row + 1][col - 1].rgbtGreen * Gx[x];
                        bl_sum_x += image[row + 1][col - 1].rgbtBlue * Gx[x];
                        rd_sum_y += image[row + 1][col - 1].rgbtRed * Gy[x];
                        gr_sum_y += image[row + 1][col - 1].rgbtGreen * Gy[x];
                        bl_sum_y += image[row + 1][col - 1].rgbtBlue * Gy[x];
                    }
                    if (neighbor == 7) // L
                    {
                        rd_sum_x += image[row][col - 1].rgbtRed * Gx[x];
                        gr_sum_x += image[row][col - 1].rgbtGreen * Gx[x];
                        bl_sum_x += image[row][col - 1].rgbtBlue * Gx[x];
                        rd_sum_y += image[row][col - 1].rgbtRed * Gy[x];
                        gr_sum_y += image[row][col - 1].rgbtGreen * Gy[x];
                        bl_sum_y += image[row][col - 1].rgbtBlue * Gy[x];
                    }
                }
            }
            // Now calculate sqrt(Gx^2 + Gy^2)
            int rd_result = round(sqrt(pow((double)(rd_sum_x), 2) + pow((double)(rd_sum_y), 2)));
            int gr_result = round(sqrt(pow((double)(gr_sum_x), 2) + pow((double)(gr_sum_y), 2)));
            int bl_result = round(sqrt(pow((double)(bl_sum_x), 2) + pow((double)(bl_sum_y), 2)));
            // Cap values at 255
            if (rd_result > 255)
            {
                rd_result = 255;
            }
            if (gr_result > 255)
            {
                gr_result = 255;
            }
            if (bl_result > 255)
            {
                bl_result = 255;
            }
            copy[i][j].rgbtRed = rd_result;
            copy[i][j].rgbtGreen = gr_result;
            copy[i][j].rgbtBlue = bl_result;
        }
    }
    // Copy results into original image matrix
    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            image[k][l] = copy[k][l];
        }
    }
    return;
}