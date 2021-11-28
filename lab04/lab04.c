#include <stdio.h>



int main()
{
    float rad;
    char t;
    float res;
    float pi = 3.14;
    

    printf ("Введите радиус:\n");
    scanf ("%f", &rad);
 
    printf ("Выберите что нужно рассчитать:\nВведите 'l' чтобы рассчитать длину окружности\nВведите 's' чтобы рассчитать площадь круга\nВведите 'v' чтобы рассчитать объём шара\n");
    scanf ("%s", &t);
 
    if (t == 'l'){
    	res = 2 * pi * rad;
	//printf ("%f", res);
    } else if (t == 's'){
	res = pi * (rad * rad);
	//printf ("%f", res);
    } else if (t == 'v'){
    	res = (4/3) * pi * (rad * rad * rad);
	//printf ("%f", res);
    } else {
	//printf ("Ошибка, скорее всего Вы ввели неверную букву для выбора рассчётов");
    }

    printf ("%f", res);


    return (0);
}















