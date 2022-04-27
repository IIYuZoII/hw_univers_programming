/*Дано масив з N цілих чисел. Визначити, чи є в масиві елементи, що повторюються;
якщо такі є, то створити масив, в якому вказати, скільки разів які елементи повторюються.
Таким чином, в результуючому масиві кожен непарний елемент - число, що повторюються;
кожен парний елемент - кількість повторювань.*/
/*
1 перебор массива и запись новых элементов в временный массив с добавлением нолика после каждого элемента
2 снова перебор массива но уже для поиска кол-ва повторок (нужно сравнивать с нечётными числами из временного)
*/
#include "/home/yuzo/programming/workTemp/hw_univers_programming/temo/src/lib.h"


void get_count (int *p, unsigned b, int *r, unsigned *c) {
    unsigned i, j;
    unsigned count_of_unique_numbers = 0;
    int temp = 0;

    int *temp_arr = NULL;
    temp_arr = (int *)malloc(128);

    //Первичный перебор массива, выписывание всех цифр без их повторов
    for (i = 0; i < b; i++){
        int my_bool = 0; //0 - True, 1 - False
        for (j = i; j >= 0; j--){
            if (*(p + i) != *(temp_arr + j)){
                my_bool = 0;
                if (j == 0){
                    break;
                }
                continue;
            } else {
                my_bool = 1;
                break;
            }
        }
        if (my_bool == 0){
            count_of_unique_numbers++;
            *(temp_arr + i) = *(p + i);
        }
    }


    //Повторный перебор массива + запись в нужном порядке
    
    for (i = 0; i < (count_of_unique_numbers * 2); i++){
        if (i % 2 == 0){
            *(r + i) = *(temp_arr + temp); //переписали двойку
            temp++;
        } else {
            int count_of_same_numbers = 0;
            for (j = 0; j < b; j++){ //тут нужно найти кол-во этих самых двоек (можно сравнивать с предыдущим числом)
                if (*(p + j) == *(r + i - 1)){
                    count_of_same_numbers++;
                }
            }
            *(r + i) = count_of_same_numbers;
        }
    }

    *c = count_of_unique_numbers * 2;


    free(temp_arr);
}