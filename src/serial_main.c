#include <stdio.h>
#include <stdlib.h>
#include "header/image.h"

struct Image process_image(struct Image *img, enum KernelType k);

void conv(char const *filename, enum KernelType k, char const *appended_filename) {
    // Read source image
    struct Image img;
    FILE *fptr = fopen(filename, "rb");
    if (fptr == NULL) {
        fprintf(stderr, "serial: file not found!\n");
        exit(1);
    }
    read_image(fptr, &img);
    fclose(fptr);

    // Process image
    struct Image res = process_image(&img, k);

    // Write output image
    char out_name[256];
    sprintf(out_name, "%s_%s", appended_filename, filename);
    fptr = fopen(out_name, "wb");
    write_image(fptr, &res);
    fclose(fptr);
}



int main(int argc, char const *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "usage: s_conv <src1> <src2> ...\n");
        exit(1);
    }

    // TODO : Multiple source (?)
    // TODO : Test stack sizes & avoid malloc
    conv(argv[1], SHARPEN_3, "sharp3");
    conv(argv[1], SHARPEN_5, "sharp5");
    conv(argv[1], RIDGE,      "ridge");
    conv(argv[1], IDENTITY,    "iden");
    conv(argv[1], BOX_BLUR,     "box");
    conv(argv[1], GAUSSIAN_3, "blur3");
    conv(argv[1], GAUSSIAN_5, "blur5");

    return 0;
}
