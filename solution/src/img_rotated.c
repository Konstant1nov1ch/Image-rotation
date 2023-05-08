#include "../include/img_rotate.h"
#include <stdio.h>
int img_rotated(struct image image, char* out){
    struct image rotated = rotate(&image);
    FILE *bmp_out = fopen(out, "wb");
    if(to_bmp(bmp_out, &rotated) == WRITE_ERROR){
        return 1;
    }
    free_image(&image);
    fclose(bmp_out);
    free_image(&rotated);
    return 0;
}
