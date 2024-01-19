#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>


int64_t read_int64() {
    int64_t val;
    scanf("%" SCNd64, &val);
    return val;
}

size_t read_size() {
    size_t size;
    scanf("%zu", &size);
    return size;
}

void print_newline() {
    printf("\n");
}

void array_int_fill( int64_t* array, size_t size ) {
    for (size_t i = 0; i != size; ++i)
        *(array + i) = read_int64();
}

// read 1-d array
int64_t* array_int_read( size_t* size ) {
    *size = read_size();
    int64_t * array = (int64_t *)malloc(sizeof(int64_t) * (*size));
    array_int_fill(array, *size);
    return array;
}

// print 1-d array
void array_int_print(int64_t * array, size_t size) {
    for (size_t i = 0; i != size; ++i)
        printf("%" PRId64 " ", array[i]);
}

// get min from array
int64_t* array_int_min( int64_t* array, size_t size ) {
    if (size == 0)
        return NULL;

    int64_t * ans = array;
    for (size_t i = 1; i != size; ++i) {
        if (*(array + i) < *ans) {
            ans = array + i;
        }
    }

    return ans;
}

// read 2-d array
int64_t** array2d_read( size_t* rows, size_t** sizes ) {
    *rows = read_size();
    int64_t **array2d = malloc(*rows * sizeof(int64_t));
    *sizes = malloc(*rows * sizeof(size_t));
    for (size_t i = 0; i < *rows; i++)
        array2d[i] = array_int_read(*sizes + i);
    return array2d;
}


// print 2-d array
void array2d_print(int64_t** array2d, size_t* sizes, size_t rows) {
    for( size_t i = 0; i < rows; i = i + 1 ) {
        array_int_print( array2d[i], sizes[i] );
        print_newline();
    }
}

// free up 2-d array used memory
void array2d_free( int64_t** array2d, size_t rows ) {
    for (size_t i = 0; i != rows; ++i)
        free(*(array2d + i));

    free(array2d);
}
