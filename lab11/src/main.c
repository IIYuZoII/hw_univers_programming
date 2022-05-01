#include "lib.h"
#include <stdlib.h>


int main (){
    unsigned rows = 0;
    unsigned columns = 0;
    unsigned i, j;

    float **matrix = NULL;
    float **matrix_transparent = NULL;

    float max = 1000, min = -1000;
    int random_temp = 0;


    printf("Введите кол-во строк матрицы: ");
    if (scanf("%d", &rows) == 0){
        printf ("\nОшибка, Вы ввели неверные данные, пожалуйста перезапустите программу");
        printf ("\n");
        return (0);   
    } else if ((int)rows <= 0) {
        printf ("Не существует матрицы с таким количеством строк. Пожалуйста перезапустите программу и введите верные данные");
        printf ("\n");
        return (0);
    }


    printf("Введите кол-во столбцов матрицы: ");
    if (scanf("%d", &columns) == 0){
        printf ("\nError, you wrote wrong data, please restart the program");
        printf ("\n");
        return (0);
    } else if ((int)columns <= 0) {
        printf ("Не существует матрицы с таким количеством столбцов. Пожалуйста перезапустите программу и введите верные данные");
        printf ("\n");
        return (0);
    }
    

    //Initialize matrixs
    srand((unsigned)time(NULL));

    matrix = (float **)malloc(rows * sizeof(float *));
    for (i = 0; i < rows; i++){
        *(matrix + i) = (float *)malloc(columns * sizeof(float));
        for (j = 0; j < columns; j++){
            random_temp = rand()%2;
            *(*(matrix + i) + j) = randomizer(max, min, random_temp);
        }
    }

    matrix_transparent = (float **)malloc(columns * sizeof(float *));
    for (i = 0; i < columns; i++){
        *(matrix_transparent + i) = (float *)malloc(rows * sizeof(float));
    }


    myFunc(matrix, matrix_transparent, rows, columns);


    //Free memory
    for (i = 0; i < rows; i++){
        free(*(matrix + i));
    }
    free(matrix);

    for (i = 0; i < columns; i++){
        free(*(matrix_transparent + i));
    }
    free(matrix_transparent);

    return (0);
}