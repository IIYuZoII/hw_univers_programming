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

	int x = 9;
	//Число десяток, оно не сможет найти его в массиве, нужна проверка на правильность / неправильность десятка
	//И потом подбирать слово по единице из этого десятка
	int t = 15;
	int t_n; //Переменная для единицы из десятка (число 12 - единица 2)
	//int t_ten; переменная для десятка (хз зачем)

	if (t > 9 && t < 20){
		t_n = t % 10; //Записываем единицу из десятка
		//t_ten = t / 10; //Записиваем сам десяток (хз зачем)
	}



	int n_in_m1 = 0;
    char array_num_words[]="one,two,three,four,five,six,seven,eight,nine\0"; //Строка для цифр
	char array_irregular_ten_words[]="ten,eleven,twelve,thirteen,fourteen,fifteen,sixteen,seventeen,eighteen,nineteen\0"; //Строка для десятков (от 10 до 19 включительно)



	//Вывод всего массива чисел в виде слов
    printf ("%s\n", array_num_words);
	printf ("%s\n", array_irregular_ten_words);

	//Временный счётчик символов внутри слова
	int temp_count_letters_num_words = 0;
	//Счётчик символов внутри слова (обнуляется если цикл идёт искать нужное слово дальше)
	int count_letters_num_words = 0;
	//Счётчик слов
	int count_words_num_words = 0;
	//Счётчик кол-ва символов в строке (используется для определения границ слова внутри строки при помощи переменной count_letters_num_words)
	int count_symbols_num_words = 0;
	
	//Всё тоже самое но для строки с десятками (10-19)
    int temp_count_letters_irregular_ten_words= 0;
	int count_letters_irregular_ten_words = 0;
	int count_words_irregular_ten_words = 0;
	int count_symbols_irregular_ten_words = 0;


	//Перебор чара, увеличение счётчика букв и его последующее обнуление при появление не буквенного символа и увеличение кол-ва слов
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


	//Второй цикл для десятков от 10 до 19 включительно
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
			printf ("Error. Can't find number in array_irregular_ten_words");
			break;
		}
	}
	
	
	
	//Массив с результатом превращения цифры в слово длинной равной кол-ву символов в нужном слове
	char m2[count_letters_num_words+1];
	//Переменная для индекса результативного массива 
	int temp = 0;
	//Переменные для поиска границ слова в строке
	int temp_left = count_symbols_num_words - count_letters_num_words - 1;
	int temp_right = count_symbols_num_words - 1;
	//Запись цифры в словесном виде в финальный массив
	for (int i = temp_left; i < temp_right; i++){
		m2[temp] = array_num_words[i];
		temp++;
	}

	printf ("\nВведена цифра: ");
	printf ("%d\n", x);
	printf ("\nСлово: ");
	printf ("%s\n", m2);

	//printf ("%d", count_words);
	printf ("\n");
	
    return (0);


}
