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

	int x = 2;

	int n_in_m1 = 0;
        char array_num_words[]="one,two,three,four,five,six,seven,eight,nine\0";
        //char *m2;



	//Вывод всего массива чисел в виде слов
        printf ("%s\n", array_num_words);

	//Переменные букв и слов, переменная букв обнуляется при каждой запятой или символе конца строки
	int temp_count_letters = 0;
	int count_letters = 0;
	int count_words = 0;

	
        char m2[count_letters];

	//Перебор чара, увеличение счётчика букв и его последующее обнуление при появление не буквенного символа и увеличение кол-ва слов
	for (int i = 0; i < 60; i++){

		//Перебор числа и его вывод в консоль (игнорируя запятые)
		/*if (array_num_words[i] != ','){
			printf ("%c\n", array_num_words[i]);
		} else {
			printf ("\n\n");
		}*/
		

		//Увеличение счётчиа кол-ва букв и его обнуление при достижении запятой или конца строки (для того чтобы начать записывать кол-во букв след. слова) а так же счётчик слов
		if (array_num_words[i] != ',' && array_num_words[i] != '\0'){
			temp_count_letters++;
		} else {
			count_words++;
			count_letters = temp_count_letters;
			temp_count_letters = 0;
		}

		if (count_words == x - 1 && array_num_words[i] != ','){
			printf ("%c\n", array_num_words[i]);
			m2[i] = array_num_words[i];

		}		


		//Проверка конца строки и остановка цикла при её достижении
		if (array_num_words[i] == '\0'){
			break;
		}	

	
	
	}



	printf ("%s\n", m2);
	printf ("%d", count_words);
	printf ("\n");

        return (0);


}
