#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define MAX_RANGE_FOR_MATRIX 11
#define MIN_RANGE_FOR_MATRIX 1

int printer_scanner (unsigned *rows, unsigned *columns);
float randomizer (float max, float min, int random_temp);
void get_matrix_transponent(float **matrix, float **matrix_transparent, unsigned rows, unsigned columns);
