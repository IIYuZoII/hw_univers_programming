#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RANGE_FOR_MATRIX 20
#define MIN_RANGE_FOR_MATRIX 1

int printer_scanner (unsigned *rows, unsigned *columns);
float randomizer (float max, float min, int random_temp);
void myFunc(float **matrix, float **matrix_transparent, unsigned rows, unsigned columns);
