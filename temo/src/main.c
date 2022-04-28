#include <stdlib.h>
// #include <stdio.h>
#include <time.h>
#include "lib.h"


int main (){
    int *arr = NULL;
    int *res = NULL;
    
    unsigned var_for_cut, i, size = 9;
    arr = (int *)malloc(size * sizeof(int));
    res = (int *)malloc(128);
    
    srand((unsigned)time(NULL));
    for (i = 0; i < size; i++){
        *(arr + i) = (int)rand()%100;
        // printf("%d\n", *(arr + i));
    }
    
    // printf("------------------\n");

    get_count(arr, size, res, &var_for_cut);

    res = (int *)realloc(res, var_for_cut * sizeof(int)); //Обрезка массива (не уверен работает ли)

    // for (unsigned k = 0; k < var_for_cut; k+=2){
    //     if (&(*(res + k)) != NULL && &(*(res + k + 1)) != NULL){
    //         printf("%d %d\n", *(res + k), *(res + k + 1));
    //     } else {
    //         printf("Out of array");
    //     }
    // }
    
    free (arr);
    free (res);
    
    return 0;
}