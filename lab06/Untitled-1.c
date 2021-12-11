#include <stdio.h>

int main (){
    int x = 0;
    int a = 5;
    int c = 1;
    int m = 256;

    for (int i = 0; i < 100; i++){
        x = (a * x + c) % m;
        printf ("%d\n", x);
    }

    return (0);
}