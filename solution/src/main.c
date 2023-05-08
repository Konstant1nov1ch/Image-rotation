#include "../include/img_rotate.h"
int main(int argc, char **argv) {
    (void) argc;
    (void) argv;
    char const * input_path = argv[1];
    char * output_path = argv[2];
    return img_rotate(input_path, output_path);
}
