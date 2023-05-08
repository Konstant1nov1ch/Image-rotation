#include "../include/bmp.h"
#include <stdlib.h>
const uint32_t colors= 3;
const uint32_t Header_size= 54;

#pragma pack(push, 1)
struct bmp_header {
    uint16_t bfType;
    uint32_t bfileSize;
    uint32_t bfReserved;
    uint32_t bOffBits;
    uint32_t biSize;
    uint32_t biWidth;
    uint32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    uint32_t biXPelsPerMeter;
    uint32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
};
#pragma pack(pop)
static uint32_t set_padding (uint32_t size_width, size_t color_pix){
    if (size_width % 4 == 0){
        return 0;
    }
    return 4-(size_width*color_pix) % 4;
}
enum read_status from_bmp(FILE* in, struct image* image) {
    size_t i = 0;
    if (in == ((void *) 0)) {
        return READ_ERROR;
    }
    struct bmp_header info_header = {0};
    if (fread(&info_header, Header_size, 1, in) != 1)
    {
        return READ_INVALID_HEADER;
    }
    image->width = info_header.biWidth;
    image->height = info_header.biHeight;
    image->data = (struct pixel *) malloc(info_header.biWidth * info_header.biHeight * 3);

    void *nul;
    while(i<image->height){
        if(image->data == ((void *) 0)){
            return INIT_FAIL;
        }
        nul=&image->data[image->width*i];
        fread(nul, colors, image->width, in);
        fseek(in, set_padding(image->width, colors), 1);
        i++;
    }
    return READ_OK;
}
enum write_status to_bmp(FILE* out, struct image const* image) {
    size_t i = 0;
    if(!out) {
        return WRITE_ERROR;
    }
    struct bmp_header newHeader = {
            .bfType = 0x4D42,
            .bfileSize = image->width * image->height * colors + image->height * (image->width % 4) + Header_size,
            .bfReserved = 0,
            .bOffBits = Header_size,
            .biSize = 40,
            .biWidth = image->width,
            .biHeight = image->height,
            .biPlanes = 1,
            .biBitCount = 24,
            .biCompression = 0,
            .biSizeImage = image->width * image->height * colors + (image->width % 4) * image->height,
            .biXPelsPerMeter = 0,
            .biYPelsPerMeter = 0,
            .biClrUsed = 0,
            .biClrImportant = 0
    };
    if (fwrite(&newHeader, Header_size, 1, out) != 1){
        return WRITE_INVALID_HEADER;
    }
    while(i < (image->height)) {
        if ((fwrite(&(image->data[i*image->width]), colors, image->width, out)) != image->width) {
            return WRITE_ERROR;
        }
        if(fseek(out, set_padding(image->width, colors), 1)){
            return EROR_PADDING;
        }
        i++;
    }
    return WRITE_OK;
}
