#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Include that allows to print result as an image
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

// Default size of image
#define X 1280
#define Y 720
#define MAX_ITER 100

void calc_mandelbrot(uint8_t image[Y][X]) {
    double xmin = -2.0;
    double xmax = 1.0;
    double ymin = -1.5;
    double ymax = 1.5;

    double dx = (xmax - xmin) / (X - 1);
    double dy = (ymax - ymin) / (Y - 1);

    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            double cx = xmin + x * dx;
            double cy = ymin + y * dy;

            double zx = 0;
            double zy = 0;
            int iter = 0;

            while (zx * zx + zy * zy < 4 && iter < MAX_ITER) {
                double temp = zx * zx - zy * zy + cx;
                zy = 2 * zx * zy + cy;
                zx = temp;
                iter++;
            }

            // Map to grayscale & set color
            uint8_t color = (iter == MAX_ITER) ? 0 : (255 * iter) / MAX_ITER;
            image[y][x] = color;
        }
    }
}

int main() {
	uint8_t image[Y][X];

	calc_mandelbrot(image);

	const int channel_nr = 1, stride_bytes = 0;
	stbi_write_png("mandelbrot.png", X, Y, channel_nr, image, stride_bytes);
	return EXIT_SUCCESS;
}