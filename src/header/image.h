#ifndef IMAGE_H
#define IMAGE_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH  500
#define MAX_HEIGHT 500

#define KERNEL_MAX_SIZE 5


// Structs & typedefs
typedef unsigned long long ull;
typedef unsigned char byte;

struct Pixel {
    byte r;
    byte g;
    byte b;
};

struct Image {
    struct Pixel px[MAX_WIDTH][MAX_HEIGHT];
    ull width;
    ull height;
};

struct Kernel {
    unsigned k_size;
    float k_multiplier;
    float k[KERNEL_MAX_SIZE][KERNEL_MAX_SIZE];
};

// Predefined kernel
enum KernelType {
    IDENTITY,
    RIDGE,
    SHARPEN_3,
    SHARPEN_5,
    BOX_BLUR,
    GAUSSIAN_3,
    GAUSSIAN_5
};

extern const struct Kernel k_iden;
extern const struct Kernel k_ridge;
extern const struct Kernel k_sharpen_3;
extern const struct Kernel k_sharpen_5;
extern const struct Kernel k_box_blur;
extern const struct Kernel k_gauss_3;
extern const struct Kernel k_gauss_5;

// Image I/O Operation
void read_image(FILE *fptr, struct Image *img);
void write_image(FILE *fptr, struct Image *img);

#endif
