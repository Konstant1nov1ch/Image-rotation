
#ifndef ASSIGNMENT_IMAGE_ROTATION_BMP_H
#define ASSIGNMENT_IMAGE_ROTATION_BMP_H

#include "../include/free.h"
#include "../include/image.h"

enum read_status{
    READ_OK = 0,
    READ_INVALID_HEADER,
    READ_ERROR,
    INIT_FAIL,

};

enum read_status from_bmp(FILE* in, struct image* image);

enum write_status {
    WRITE_OK = 0,
    WRITE_ERROR,
    WRITE_INVALID_HEADER,
    EROR_PADDING,
};

enum write_status to_bmp(FILE* out, struct image const* image);

#endif //ASSIGNMENT_IMAGE_ROTATION_BMP_H
