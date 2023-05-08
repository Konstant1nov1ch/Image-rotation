#include "../include/img_rotate.h"
#include "../include/img_rotated.h"
#include <stdio.h>
int img_rotate(const char* in, char* out){
    struct image image;
    FILE *bmp_in = fopen(in, "rb");
    if(from_bmp(bmp_in, &image) == READ_ERROR){
        return 1;
    }
    fclose(bmp_in);
    return img_rotated(image, out);
}
