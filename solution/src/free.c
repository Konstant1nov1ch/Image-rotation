#include "../include/image.h"
#include "../include/free.h"
#include <stdlib.h>
void free_image(struct image *image){
    free(image->data);
    image->data = ((void *) 0);
    image->width = 0;
    image->height = 0;
}
