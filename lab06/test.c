#include <stdio.h>

int main (){

int x = 1234;

//Единица = 0
//Десяток = 1
//Сотня = 2
//Тысяча = 3
int x_is = 0;

int thous_num = 0;
int hun_num = 0;
int ten_num = 0;
int n_num = 0;

// for (int i = 10; i < 1001; i *= 10){
//     if (x / i < 1){
//         x_is = 0;
//         break;
//     } else if (x / i > 1 && x / i < 10){
//         x_is++;
//     }
// }

if ((x / 10) < 1000){
    if (x / 10 < 1){
        x_is = 0;
    } else if (x / 10 > 1 && x / 10 < 10) {
        x_is = 1;
    } else if (x / 10 >= 10 && x / 10 < 100){
        x_is = 2;
    } else if (x / 10 >= 100){
        x_is = 3;
    }
} else {
    printf ("Error");
}
printf ("%d", x_is);



if (x_is == 1){
    ten_num = x / 10;
    n_num = x % 10;
} else if (x_is == 2){
    hun_num = x / 100;
    ten_num = (x / 10) % 10;
    n_num = x % 10;
} else if (x_is == 3){
    thous_num = x / 1000;
    hun_num = (x / 100) % 10;
    ten_num = (x / 10) % 10;
    n_num = x % 10;
}
return (0);

}