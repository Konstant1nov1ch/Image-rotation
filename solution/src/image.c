#include "../include/image.h"
#include <stdlib.h>
struct image rotate(struct image const *source ) {
    struct image newImg = {0};
    newImg.width = source->height;
    newImg.height = source->width;
    size_t nHeight = source->width;
    size_t nWidth = source->height;
    newImg.data = malloc(3 * source->height * source->width);
    for(int i=0;i<nHeight;i++){
        for(int j=0;j<nWidth;j++){
            size_t py = i;
            size_t px = nWidth-1-j;
            newImg.data[(i*nWidth)+j]=source->data[px*nHeight+py];
        }
    }
    return newImg;
}

