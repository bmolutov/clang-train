#ifndef PROJECT_C_FUNCTIONS_H
#define PROJECT_C_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

size_t read_size();
int64_t* array_int_min( int64_t* array, size_t size );
int64_t** array2d_read( size_t* rows, size_t* sizes[] );
void array2d_free( int64_t** array2d, size_t rows );
void array2d_print(int64_t** array2d, size_t* sizes, size_t rows);

#endif //PROJECT_C_FUNCTIONS_H
