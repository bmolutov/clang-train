#include <stdio.h>
#include "functions.h"


int64_t* int64_ptr_min(int64_t* x, int64_t* y) {
    if (x == NULL && y == NULL)
        return NULL;
    if (x == NULL)
        return y;
    if (y == NULL)
        return x;
    return (*x < *y) ? x : y;
}

int64_t* array2d_int_min( int64_t** array2d, size_t* sizes, size_t rows ) {
    int64_t * ans = NULL;
    for (size_t i = 0; i < rows; i++) {
        int64_t * res = array_int_min(array2d[i], sizes[i]);
        ans = int64_ptr_min(ans, res);
    }
    return ans;
}

void array2d_normalize( int64_t** array2d, const size_t* sizes, size_t rows, int64_t m ) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < sizes[i]; j++) {
            array2d[i][j] -= m;
        }
    }
}

// read, find min and normalize, then print result
void perform() {

    size_t row, *sizes = NULL;
    int64_t ** matrix = NULL, *min = NULL;
    matrix = array2d_read(&row, &sizes);

    if (sizes == NULL || matrix == NULL)
        return;
    min = array2d_int_min(matrix, sizes, row);

    if (min == NULL) {
        if (matrix != NULL)
            array2d_free( matrix, row );
        if (sizes != NULL)
            free(sizes); return;
    }

    array2d_normalize(matrix, sizes, row, *min);
    array2d_print(matrix, sizes,  row);

    if (matrix != NULL)
        array2d_free( matrix, row );

    if (sizes != NULL)
        free(sizes);
}

int main() {

    perform();

    return 0;
}
