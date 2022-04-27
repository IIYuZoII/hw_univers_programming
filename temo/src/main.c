#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <malloc.h>


#include "/home/yuzo/programming/workTemp/hw_univers_programming/temo/src/lib.h"


int main (){
    int *p = NULL;
    int *res = NULL;
    unsigned var_for_cut;
    
    unsigned size = 1231;
    unsigned i;

    p = (int *)malloc(size * sizeof(int));
    res = (int *)malloc(128);
    
    
    // srand((unsigned)time(NULL));
    // for (i = 0; i < size; i++){
    //     *(p + i) = rand()%100;
    //     printf("%d\n", *(p + i));
    // }
    
    for (i = 0; i < size; i++){
        if (i % 2 == 0){
            *(p + i) = 2;
        } else {
            *(p + i) = 3;
        }
    }
    get_count(p, size, res, &var_for_cut);
    res = (int *)realloc(res, var_for_cut); //Обрезка массива нужно доделать

    printf("Size: %u", _msize (res) );

    for (int k = 0; k < 4; k++){
        printf("%d\n", *(res + k));
    }
    
    free (p);
    free (res);
    
    return 0;
}