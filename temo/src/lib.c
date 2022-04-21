#include "lib.h"

int get_count(int *b, int len) {
    int count = 0;
    
    

    //Перебор массива
    for (int i = 0; i < len - 1; i++) {
        if (*(b + i) < *(b + i + 1) && i + 1 < len) {
            count++;
        }
        
    }
    return (count);
}