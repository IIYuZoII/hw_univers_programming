// ( ** ) Робота повинна бути присвячена взаємодії з користувачем шляхом використання
// функцій write(), read()

// Завдання:
// 4. ( * ) Визначити транспоновану матрицю.


#include "lib.h"


int printer_scanner (unsigned *rows, unsigned *columns){

    int fd = open ("../assets/input.txt", O_RDWR | O_CREAT);
    if (fd < 0) {
        printf ("Error, couldn't open file \n");
    }
    
    char *c = (char *)malloc(100 * sizeof(char));
    int sz = (int)read (fd, c, 100);
    *(c + sz) = '\0';

    write (1, c, strlen(c));
    write (1, "\n", 1);

    close(fd);
    free(c);

    printf("Введите кол-во строк матрицы (не более %d%s", MAX_RANGE_FOR_MATRIX ,"): ");
    if (scanf("%d", &*rows) == 0){
        printf ("\nОшибка, вы использовали недопустимый тип данных, пожалуйста перезапустите программу и введите целочисельный тип данных\n");
        return (1);   
    } else if (*rows < MIN_RANGE_FOR_MATRIX) {
        printf ("\nНе существует матрицы с таким количеством строк. Пожалуйста перезапустите программу и введите верные данные\n");
        return (1);
    }
    

    printf("Введите кол-во столбцов матрицы (не более %d%s",MAX_RANGE_FOR_MATRIX, "): ");
    if (scanf("%d", &*columns) == 0){
        printf ("\nОшибка, вы использовали недопустимый тип данных, пожалуйста перезапустите программу и введите целочисельный тип данных\n");
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

void get_matrix_transponent(float **matrix, float **matrix_transparent, unsigned rows, unsigned columns){
    unsigned i, j;

    //Запись в транспонированную матрицу значений оригинальной
    for (i = 0; i < rows; i++){
        for (j = 0; j < columns; j++){
            *(*(matrix_transparent + j) + i) = *(*(matrix + i) + j);
        }
    }


    //Printing matrix
    printf("\n\nВведённая матрица:\n");
    for (i = 0; i < rows; i++){
        printf ("[");
        for (j = 0; j < columns; j++){
            printf("\t%0.2f\t", *(*(matrix + i) + j));
        }
        printf ("]");
        printf ("\n");
    }


    //Printing matrix_transparent
    printf("\n\nТранспонированная матрица:\n");
    for (i = 0; i < columns; i++){
        printf ("[");
        for (j = 0; j < rows; j++){
            printf("\t%0.2f\t", *(*(matrix_transparent + i) + j));
        }
        printf ("]");
        printf ("\n");
    }
}