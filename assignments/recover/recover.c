#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// This will help us read each byte
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check if user entered a valid input
    if (argc != 2)
    {
        printf("Usage: ./recover filename.raw\n");
        return 1;
    }
    // Attempt to open a read only version of file
    FILE *file = fopen(argv[1], "r");
    // Check if it was a valid file
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    // Create a BYTE buffer array of size 512 bytes
    BYTE buffer[512];
    // Keep track of amount of jpgs
    int jpg_count = 0;
    // Create string buffer to name jpg files
    char jpeg_file[8];
    // Create a pointer to a new file
    FILE *img;
    // Start reading 512 bytes at a time from file
    while(fread(buffer, 512, 1, file))
    {
        // If new JPG found
        if (buffer[0] == 0xff && buffer[1] == 0xd8
        && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Name and open file
            sprintf(jpeg_file, "%03i.jpg", jpg_count++);
            img = fopen(jpeg_file, "w");
            while (1) // Start reading into jpg file
            {
                fwrite(buffer, 512, 1, img);
                fread(buffer, 512, 1, file);
                // Check if new jpeg is encountered
                if (buffer[0] == 0xff && buffer[1] == 0xd8
                    && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
                {
                    fclose(img);
                    sprintf(jpeg_file, "%03i.jpg", jpg_count++);
                    img = fopen(jpeg_file, "w");
                    break;
                }
            }
        }
        // This makes sure we get the lines from a new jpg file
        fwrite(buffer, 512, 1, img);
    }
    fclose(img);
    fclose(file);
}
