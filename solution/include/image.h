#ifndef ASSIGNMENT_IMAGE_ROTATION_IMAGE_H
#define ASSIGNMENT_IMAGE_ROTATION_IMAGE_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct pixel{
    unsigned char pixel[3];
};
struct image {
    uint64_t width, height;
    struct pixel* data;
};
struct image rotate(struct image const* source );
#endif //ASSIGNMENT_IMAGE_ROTATION_IMAGE_H

