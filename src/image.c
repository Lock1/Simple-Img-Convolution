#include <stdio.h>
#include <stdlib.h>
#include "image.h"

void read_image(FILE *fptr, struct Image *img) {
    // Header
    img->width = img->height = 0;
    byte buf[16];
    fread(buf, 16, 1, fptr);
    for (int i = 0; i < 8; i++) {
        img->width  |= buf[0+i] << (8*i);
        img->height |= buf[8+i] << (8*i);
    }

    // Content
    for (unsigned i = 0; i < img->width; i++)
        for (unsigned j = 0; j < img->height; j++)
            fread(&(img->px[i][j]), 3, 1, fptr);
}


void write_image(FILE *fptr, struct Image *img) {
    // Header
    byte buf[16];
    for (int i = 0; i < 8; i++) {
        buf[0+i] = (img->width  >> (8*i)) & 0xFF;
        buf[8+i] = (img->height >> (8*i)) & 0xFF;
    }
    fwrite(buf, 8, 2, fptr);

    // Content
    for (unsigned i = 0; i < img->width; i++)
        for (unsigned j = 0; j < img->height; j++)
            fwrite(&(img->px[i][j]), 3, 1, fptr);
}
