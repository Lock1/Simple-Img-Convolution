#include <stdio.h>
#include <stdlib.h>
#include "header/image.h"

static struct Kernel selected_kernel;
static unsigned selected_k_half;

inline static float clamp_color(float c) {
    const float x = (c < 0.0) ? 0.0 : c;
    return (x > 255.0) ? 255.0 : x;
}

struct Pixel calculate_conv(struct Image *img, unsigned row, unsigned col) {
    float r_red = 0.0, r_green = 0.0, r_blue = 0.0;

    for (unsigned i = 0; i < selected_kernel.k_size; i++) {
        for (unsigned j = 0; j < selected_kernel.k_size; j++) {
            r_red   += ((float) img->px[row+i-selected_k_half][col+j-selected_k_half].r) * selected_kernel.k[i][j] * selected_kernel.k_multiplier;
            r_green += ((float) img->px[row+i-selected_k_half][col+j-selected_k_half].g) * selected_kernel.k[i][j] * selected_kernel.k_multiplier;
            r_blue  += ((float) img->px[row+i-selected_k_half][col+j-selected_k_half].b) * selected_kernel.k[i][j] * selected_kernel.k_multiplier;
        }
    }

    // Overflow policy : Clamp to [0, 255]
    struct Pixel res_px;
    res_px.r = (byte) clamp_color(r_red);
    res_px.g = (byte) clamp_color(r_green);
    res_px.b = (byte) clamp_color(r_blue);
    return res_px;
}

struct Image process_image(struct Image *img, enum KernelType k) {
    // Edge handling policy : Crop, resulting image will have black border
    struct Image result;
    result.width  = img->width;
    result.height = img->height;

    // Set globals
    switch (k) {
        case IDENTITY:
            selected_kernel = k_iden;
            break;
        case RIDGE:
            selected_kernel = k_ridge;
            break;
        case SHARPEN_3:
            selected_kernel = k_sharpen_3;
            break;
        case SHARPEN_5:
            selected_kernel = k_sharpen_5;
            break;
        case BOX_BLUR:
            selected_kernel = k_box_blur;
            break;
        case GAUSSIAN_3:
            selected_kernel = k_gauss_3;
            break;
        case GAUSSIAN_5:
            selected_kernel = k_gauss_5;
            break;
    }
    selected_k_half = selected_kernel.k_size / 2;

    // Process
    for (unsigned i = selected_k_half; i < img->width - selected_k_half; i++)
        for (unsigned j = selected_k_half; j < img->height - selected_k_half; j++)
            result.px[i][j] = calculate_conv(img, i, j);

    return result;
}
