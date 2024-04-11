#include <stddef.h>
#include <stdint.h>

void hadamard_product_1(int32_t** a, int32_t** b, int32_t** c, size_t n) {
    for (size_t j = 0; j < n; ++j) {
        for (size_t i = 0; i < n; ++i) {
            c[i][j] = a[i][j] * b[i][j];
        }
    }
}

void hadamard_product_2(int32_t** a, int32_t** b, int32_t** c, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            c[i][j] = a[i][j] * b[i][j];
        }
    }
}
