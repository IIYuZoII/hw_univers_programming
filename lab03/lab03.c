/*
Визначити число, яке отримане виписуванням у зворотному порядку цифр заданого
тризначного числа в десятковій системі числення
*/

int main ()
{
    int a = 123;

    int last_n = (a % 10) * 100; // 300
    int second_n = ((a / 10) % 10) * 10; // 20
    int first_n = a / 100; // 1

    int reverse_result = last_n + second_n + first_n; // 321
    
    return (0);
}

















