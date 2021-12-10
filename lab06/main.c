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

	int x = 1;

	int n_in_m1 = 0;
        char array_num_words[]="one,two,three,four,five,six,seven,eight,nine\0";
        //char *m2;



	//Вывод всего массива чисел в виде слов
        printf ("%s\n", array_num_words);

	//Переменные букв и слов, переменная букв обнуляется при каждой запятой или символе конца строки
	int temp_count_letters = 0;
	int count_letters = 0;
	int count_words = 0;
	int count_symbols = 0;
	
        //char m2[count_letters+1];

	//Перебор чара, увеличение счётчика букв и его последующее обнуление при появление не буквенного символа и увеличение кол-ва слов
	for (int i = 0; i < 60; i++){

		//Перебор числа и его вывод в консоль (игнорируя запятые)
		/*if (array_num_words[i] != ','){
			printf ("%c\n", array_num_words[i]);
		} else {
			printf ("\n\n");
		}*/
		

		count_symbols++;

		//Увеличение счётчиа кол-ва букв и его обнуление при достижении запятой или конца строки (для того чтобы начать записывать кол-во букв след. слова) а так же счётчик слов
		if (array_num_words[i] != ',' && array_num_words[i] != '\0'){
			temp_count_letters++;
		} else {
			count_words++;
			count_letters = temp_count_letters;
			temp_count_letters = 0;
		}

		if (count_words == x /*&& array_num_words[i] != ','*/){
			//printf ("%c\n", array_num_words[i]);
			//m2[i] = array_num_words[i];
			count_words--;
			break;

		}	


		//Проверка конца строки и остановка цикла при её достижении
		if (array_num_words[i] == '\0'){
			break;
		}	
	}

	char m2[count_letters+1];
	//int temp = count_letters;
	int temp = 0;
	int temp_left = count_symbols - count_letters - 1;
	int temp_right = count_symbols - 1;

	for (int i = temp_left; i < temp_right; i++){
		/*if (count_words == x - 1 && array_num_words[i] != ','){ //Помойка какая-то
                        //printf ("%c\n", array_num_words[i]);
                        m2[i] = array_num_words[i];
			temp--;
                }*/

		m2[temp] = array_num_words[i];
		temp++;
		/*if (temp == 0){ //Продолжение помойки
			break;
		}*/
	}

	printf ("\nВведена цифра: ");
	printf ("%d\n", x);
	printf ("\nСлово: ");
	printf ("%s\n", m2);

	//printf ("%d", count_words);
	printf ("\n");

        return (0);


}
