#include "image.h"
// Kernel matrices, symmetric kernel only
// Kernel samples : en.wikipedia.org/wiki/Kernel_(image_processing)

const struct Kernel k_iden = {
    .k_size       = 3,
    .k_multiplier = 1.0,
    .k = {
        { 0.0, 0.0, 0.0 },
        { 0.0, 1.0, 0.0 },
        { 0.0, 0.0, 0.0 },
    }
};

const struct Kernel k_ridge = { // FIXME : ??
    .k_size       = 3,
    .k_multiplier = 1.0,
    .k = {
        { -1.0, -1.0, -1.0 },
        { -1.0,  8.0, -1.0 },
        { -1.0, -1.0, -1.0 },
    }
};

const struct Kernel k_sharpen_3 = {
    .k_size       = 3,
    .k_multiplier = 1.0,
    .k = {
        {  0.0, -1.0,  0.0 },
        { -1.0,  5.0, -1.0 },
        {  0.0, -1.0,  0.0 },
    }
};

const struct Kernel k_sharpen_5 = {
    .k_size       = 5,
    .k_multiplier = 1.0,
    .k = {
        {  0.0,  0.0, -1.0,  0.0,  0.0 },
        {  0.0, -1.0, -1.0, -1.0,  0.0 },
        { -1.0, -1.0, 13.0, -1.0, -1.0 },
        {  0.0, -1.0, -1.0, -1.0,  0.0 },
        {  0.0,  0.0, -1.0,  0.0,  0.0 }
    }
};

const struct Kernel k_box_blur = {
    .k_size       = 3,
    .k_multiplier = 1.0 / 9.0,
    .k = {
        { 1.0, 1.0, 1.0 },
        { 1.0, 1.0, 1.0 },
        { 1.0, 1.0, 1.0 },
    }
};

const struct Kernel k_gauss_3 = {
    .k_size       = 3,
    .k_multiplier = 1.0 / 16.0,
    .k = {
        { 1.0, 2.0, 1.0 },
        { 2.0, 4.0, 2.0 },
        { 1.0, 2.0, 1.0 },
    }
};

const struct Kernel k_gauss_5 = {
    .k_size       = 5,
    .k_multiplier = 1.0 / 256.0,
    .k = {
        { 1.0,  4.0,  6.0,  4.0, 1.0 },
        { 4.0, 16.0, 24.0, 16.0, 1.0 },
        { 6.0, 24.0, 36.0, 24.0, 1.0 },
        { 4.0, 16.0, 24.0, 16.0, 1.0 },
        { 1.0,  4.0,  6.0,  4.0, 1.0 }
    }
};
