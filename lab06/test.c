/* Перетворити число (максимальне значення якого - 9999) в рядок. (усі символи
 * нижнього регістру на виході). Наприклад,
 * • 123 – “one hundred twenty three”,
 * • 4311 – “four thousands three hundreds eleven”
 *
 *
 *
 *
 */

#include <stdio.h>


int main (){

	int testInput = 20;
	int test = testInput / 10;
	
	int x = 1;

	//Единица = 0
	//Десяток = 1
	//Сотня = 2
	//Тысяча = 3
	int x_is = 0;

	//Переменные разрядов
	int thous_num = 0;
	int hun_num = 0;
	int ten_num = 0;
	int n_num = 0;

	//Определение разрядности числа
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
	}

	//Разбивание числа на разряды
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

	int t = 19;
	int t_n; //Переменная для единицы из десятка (число 12 - единица 2)
	//int t_ten; переменная для десятка (хз зачем)

	if (t > 10 && t < 20){
		t_n = t % 10; //Записываем единицу из десятка
		//t_ten = t / 10; //Записиваем сам десяток (хз зачем)
	}


    char array_num_words[]="one,two,three,four,five,six,seven,eight,nine\0"; //Строка для цифр
	char array_irregular_ten_words[]="eleven,twelve,thirteen,fourteen,fifteen,sixteen,seventeen,eighteen,nineteen\0"; //Строка для десятков (от 11 до 19 включительно)
	char array_clean_ten_words[]="ten,twenty,thirty,forty,fifty,sixty,seventy,eighty,ninety\0"; //Строка для "чистых" чисел


	//Вывод всего массива чисел в виде слов
    printf ("%s\n", array_num_words);
	printf ("%s\n", array_irregular_ten_words);

	//Переменные для строки с цифрами
	int temp_count_letters_num_words = 0; //Временный счётчик символов внутри слова
	int count_letters_num_words = 0; //Счётчик символов внутри слова (обнуляется если цикл идёт искать нужное слово дальше)
	int count_words_num_words = 0; //Счётчик слов
	int count_symbols_num_words = 0; //Счётчик кол-ва символов в строке
	
	//Переменные для строки с десятками (11-19)
    int temp_count_letters_irregular_ten_words= 0; //Временный счётчик символов внутри слова
	int count_letters_irregular_ten_words = 0; //Счётчик символов внутри слова
	int count_words_irregular_ten_words = 0; //Счётчик слов
	int count_symbols_irregular_ten_words = 0; //Счётчик кол-ва символов в строке

	//Переменные для строки с "чистыми" десятками (10, 20, 30, ..., 90)
	int temp_count_letters_clean_ten_words = 0; //Временный счётчик символов внутри слова
	int count_letters_clean_ten_words = 0; //Счётчик символов внутри слова
	int count_words_clean_ten_words = 0; //Счётчик слов
	int count_symbols_clean_ten_words = 0; //Счётчик кол-ва символов в строке





	
	//Первый цикл для единиц
	for (int i = 0; i < 120; i++){

		//Перебор числа и его вывод в консоль (игнорируя запятые)
		/*if (array_num_words[i] != ','){
			printf ("%c\n", array_num_words[i]);
		} else {
			printf ("\n\n");
		}*/
		
		//С каждым символом счётчик увеличивается т.к. мы ищем границы слова
		count_symbols_num_words++;

		//Увеличение счётчиа кол-ва букв и его обнуление при достижении запятой или конца строки (для того чтобы начать записывать кол-во букв след. слова) а так же счётчик слов
		if (array_num_words[i] != ',' && array_num_words[i] != '\0'){
			temp_count_letters_num_words++;
		} else {
			count_words_num_words++; //При достижении запятой счётчик слов ++
			count_letters_num_words = temp_count_letters_num_words; //Счётчик букв в слове принимает значение временного счётчика букв слове чтобы освободить временную переменную
			temp_count_letters_num_words = 0; //Обнуление временного счётчика букв в слове
		}
		
		//Если счётчик слов равен числу "х", тогда ломаем цикл так как мы уже полностью прошли нужное число, и отнимаем от счётчика 1 так как он далее будет служить айди слова
		if (count_words_num_words == x){
			//count_words_num_words--; //отнимаем 1 так как счётчик будет служить айди слова ((((НЕ АКТУАЛЬНО так как я сделал решение через границы слова))))
			break;
		}

		//Проверка конца строки и остановка цикла при её достижении
		if (array_num_words[i] == '\0'){
			break;
		}	
	}

	//Второй цикл для десятков от 11 до 19 включительно
	for (int i = 0; i < 200; i++){
		count_symbols_irregular_ten_words++;

		if (array_irregular_ten_words[i] != ',' && array_irregular_ten_words[i] != '\0'){
			temp_count_letters_irregular_ten_words++;
		} else {
			count_words_irregular_ten_words++;
			count_letters_irregular_ten_words = temp_count_letters_irregular_ten_words;
			temp_count_letters_irregular_ten_words = 0;
		}

		if (count_words_irregular_ten_words == t_n){
			break;
		}
		//Перебор числа и его вывод в консоль, вместо запятых ставим пробелы
		// if (array_irregular_ten_words[i] != ','){
		// 	printf ("%c", array_irregular_ten_words[i]);
		// } else if (array_irregular_ten_words[i] == ','){
		// 	printf ("%s", " ");
		// } else {
		// 	printf ("\n\n");
		// }	

		//Проверка конца строки и остановка цикла при её достижении
		if (array_irregular_ten_words[i] == '\0'){
			break;
		}
	}

	//Третий цикл для чистых десятков
	for (int i = 0; i < 100; i++){
		count_symbols_clean_ten_words++;

		if (array_clean_ten_words[i] != ',' && array_clean_ten_words[i] != '\0'){
			temp_count_letters_clean_ten_words++;
		} else {
			count_words_clean_ten_words++;
			count_letters_clean_ten_words = temp_count_letters_clean_ten_words;
			temp_count_letters_clean_ten_words = 0;
		}

		if (count_words_clean_ten_words == test){
			//printf ("\nСлово найдено");
			break;
		}

		if (array_clean_ten_words[i] == '\0'){
			break;
		}
	}
	//Переменная которая считает кол-во пробелов 
	int space_count = 2;
	//Переменная для длинны результативного массива, с учётом кол-ва пробелов
	int len_m2 = space_count + count_letters_num_words + count_letters_irregular_ten_words + count_letters_clean_ten_words;

	//Массив с результатом превращения цифры в слово длинной равной кол-ву символов в нужном слове
	char m2[len_m2+1];

	//Переменная для индекса результативного массива 
	int temp = 0;

	//Переменные для поиска границ слова в строке единиц
	int temp_left_num_words = count_symbols_num_words - count_letters_num_words - 1;
	int temp_right_num_words = count_symbols_num_words - 1;

	//Переменные для поиска границ слова в строке неправильных десятков
	int temp_left_irregular_ten_words = count_symbols_irregular_ten_words - count_letters_irregular_ten_words - 1;
	int temp_right_irregular_ten_words = count_symbols_irregular_ten_words - 1;

	//Переменные для поиска границ слова в строке чистых десятков
	int temp_left_clean_ten_words = count_symbols_clean_ten_words - count_letters_clean_ten_words - 1;
	int temp_right_clean_ten_words = count_symbols_clean_ten_words - 1;

	char space = ' ';

	//Запись цифры в словесном виде в финальный массив
	for (int i = temp_left_num_words; i < temp_right_num_words; i++){
		m2[temp] = array_num_words[i];
		temp++;
	}
	//Добавляем пробел после первого слова
	
	m2[temp] = space;
	temp += 1; //Увеличиваем временную переменную чтобы учесть пробел
	
	//Запись десятка в тот же массив как продолжение
	for (int i = temp_left_irregular_ten_words; i < temp_right_irregular_ten_words; i++){
		m2[temp] = array_irregular_ten_words [i];
		temp++;
	}

	m2[temp] = space;
	temp += 1;

	//Запись чистого десятка как продолжение
	for (int i = temp_left_clean_ten_words; i < temp_right_clean_ten_words; i++){
		m2[temp] = array_clean_ten_words[i];
		temp++;
	}

	// printf ("\nВведена цифра: ");
	// printf ("%d\n", x);
	printf ("\nСлово: ");
	printf ("%s\n", m2);

	//printf ("%d", count_words);
	printf ("\n");
	
    return (0);


}
// https://englishexplained.ru/numerals-5-rules/