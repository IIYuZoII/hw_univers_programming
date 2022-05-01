// ( ** ) Робота повинна бути присвячена взаємодії з користувачем шляхом використання
// функцій write(), read()

// Завдання:
// 4. ( * ) Визначити транспоновану матрицю.


#include "lib.h"


int printer_scanner (unsigned *rows, unsigned *columns){
    printf("Введите кол-во строк матрицы (не более 20): ");
    if (scanf("%d", &*rows) == 0){
        printf ("\nОшибка, вы ввели неверные данные, пожалуйста перезапустите программу\n");
        return (1);   
    } else if (*rows < MIN_RANGE_FOR_MATRIX) {
        printf ("\nНе существует матрицы с таким количеством строк. Пожалуйста перезапустите программу и введите верные данные\n");
        return (1);
    }
    

    printf("Введите кол-во столбцов матрицы (не более 20): ");
    if (scanf("%d", &*columns) == 0){
        printf ("\nОшибка, вы ввели неверные данные, пожалуйста перезапустите программу\n");
        return (1);
    } else if (*columns < MIN_RANGE_FOR_MATRIX) {
        printf ("\nНе существует матрицы с таким количеством столбцов. Пожалуйста перезапустите программу и введите верные данные\n");
        return (1);
    }
    
    if (*rows > MAX_RANGE_FOR_MATRIX || *columns > MAX_RANGE_FOR_MATRIX){
        printf ("\nВведённые данные выходят за рамки допустимых значений\nПожалуйста перезапустите программу и введите верные данные\n");
        return (1);
    }

    return (0);
}


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
        printf ("[");
        for (j = 0; j < columns; j++){
            printf("\t%0.2f\t", *(*(matrix + i) + j));
        }
        printf ("]");
        printf ("\n");
    }


    //Printing matrix_transparent
    printf("\n\nMatrix transparent:\n");
    for (i = 0; i < columns; i++){
        printf ("[");
        for (j = 0; j < rows; j++){
            printf("\t%0.2f\t", *(*(matrix_transparent + i) + j));
        }
        printf ("]");
        printf ("\n");
    }
}