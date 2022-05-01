// ( ** ) Робота повинна бути присвячена взаємодії з користувачем шляхом використання
// функцій write(), read()

// Завдання:
// 4. ( * ) Визначити транспоновану матрицю.


#include "lib.h"

float randomizer (float max, float min, int random_temp){
    float res;
    if (random_temp == 0) {
        return (((float)rand()/(float)(RAND_MAX)) * (max + 1));
    }
    return (((float)rand()/(float)(RAND_MAX)) * (min - 1));
}

void myFunc(float **matrix, float **matrix_transparent, unsigned rows, unsigned columns){
    unsigned i, j;

    //Запись в транспонированную матрицу значений оригинальной
    for (i = 0; i < rows; i++){
        for (j = 0; j < columns; j++){
            *(*(matrix_transparent + j) + i) = *(*(matrix + i) + j);
        }
    }


    //Printing matrix
    printf("\n\nMatrix original:\n");
    for (i = 0; i < rows; i++){
        for (j = 0; j < columns; j++){
            printf("%0.2f ", *(*(matrix + i) + j));
        }
        printf ("\n");
    }


    //Printing matrix_transparent
    printf("\n\nMatrix transparent:\n");
    for (i = 0; i < columns; i++){
        for (j = 0; j < rows; j++){
            printf("%0.2f ", *(*(matrix_transparent + i) + j));
        }
        printf ("\n");
    }
}