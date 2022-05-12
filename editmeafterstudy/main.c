/**
 * C program to delete a word from file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

void find_count_words_in_line (char *str, int *k);
void find_duplicates(char *str, unsigned long *index);
void removeAll(char *str, char *buffer, char *toRemove, unsigned long *index);


int main()
{
    FILE * fPtr;
    FILE * fTemp;

    
    unsigned long index = 0; //Для индексирования основного буфера
    
    char *path = (char *)malloc(100 * sizeof(char));  
    
    // char *toRemove = (char *)malloc(100 * sizeof(char));
    
    char *buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));

    /* Input source file path path */
    printf("Enter path of source file: ");
    scanf("%s", path);


    /*  Open files */
    fPtr  = fopen(path, "r");
    fTemp = fopen("delete.tmp", "w"); 

    /* fopen() return NULL if unable to open file in given mode. */
    if (fPtr == NULL || fTemp == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }


    /*
     * Read line from source file and write to destination 
     * file after removing given word.
     */
    // int k = 0;
    while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
    {
        //Сделать доп функцию которая будет искать кол-во слов внутри строки
        //чтобы передать это значение сюда и потом в зависимости от кол-ва слов
        //вызывать функцию поиска дубликата

        //в функцию по удалению передавать не всю строку а часть после найденного слова
        //соответственно нужен ещё один буфер в функции по поиску

        int k = 0;
        // k = find_count_words_in_line (buffer, &k);
        find_count_words_in_line (buffer, &k);




        //нужно сделать:
        //не удалять первое слово
        //(начинать не с того же символа ибо тогда выходит простая прокрутка) (возможно не нужно будет если сделать предидущее условие)
        while (k >= 0){
            find_duplicates(buffer, &index);
            k--;
        }


        // Remove all occurrence of word from current line
        // removeAll(buffer, toRemove);

        // Write to temp file
        fputs(buffer, fTemp);
    }


    /* Close all files to release resource */
    fclose(fPtr);
    fclose(fTemp);


    /* Delete original source file */
    remove(path);

    /* Rename temp file as original file */
    rename("delete.tmp", path);


    // printf("\nAll occurrence of '%s' removed successfully.", toRemove);

    return 0;
}


void find_count_words_in_line (char *str, int *k){
    int checker_words = 0;
    int count_words = 0;
    unsigned long i = 0, stringLen;

    stringLen = strlen(str);
    // int i = 0;
    // printf ("%s", str);
    // printf ("%lu", stringLen);
    while (i < stringLen + 1){
        if (*(str + i) != ',' && *(str + i) != ' ' && *(str + i) != '\0' && *(str + i) != '\n'){
            checker_words = 1;
        }
        if (checker_words == 1 && (*(str + i) == ' ' || *(str + i) == ',' || *(str + i) == '\0' || *(str + i) == '\n')){
            checker_words = 0;
            count_words++;
        }
        i++;
    }
    
    *k = count_words;
    // printf ("Count words in func is: '%d'\n", count_words);
    // return (count_words);
}

/*
Известные проблемы:
если строка НАЧИНАЕТСЯ не с букв то ничего изменено не будет

*/

//Получает - старший буфер, индекс
//Отправляет - младший буфер, старший буфер, слово для удаления в младшем буфере, индекс


//Функция берёт первое слово с начала индексирования,
//находит его границу и всё что после слова записывает в младший буфер
//чтобы передать в функцию которая вырежет все повторы найденного слова (его тоже передаём)
void find_duplicates(char *str, unsigned long *index){
    //str - bigger buffer (main)
    
    unsigned long i;
    unsigned long stringLen;

    // char *buffer_small = (char *)malloc(100 * sizeof(char));
    char buffer_small[1000];
    
    char toRemove[100];
    // char *toRemove = (char *)malloc(100 * sizeof(char));
    int found;

    stringLen = strlen(str);


    // unsigned int temp = stringLen;
    int switch_temp = 0;
    for (i = 0; i < stringLen; i++){ //Возможно i стоит приравнивать к index
        // if (switch_temp == 0 && (str[i] == ' ' || str[i] == ',') && (str[i - 1] == ' ' || str[i - 1] == ',')){ //Problem is here
        //     // if()
        //     // temp++;                   //спасает от бесконечного цикла при первом спец символе
        //     switch_temp = 1;            //но не ищет слово после спец символа
        //     continue;
        // }
        if (str[i] != ',' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\0'){
            // *(toRemove + i) = str[i];
            toRemove[i] = str[i];
            // *index++; //Увеличиваем индекс чтобы сместить "указатель на символ в буфефере" вправо когда находим слово
        } else if (i == 0) {
            // *index++;
            continue;
        // *(toRemove + i) = '\0';
        } else {
            // *index++;
            toRemove[i] = '\0';
            break;
        }
    } //Или после цикла написать присваивание индексу значения
    *index = i;
    int j = 0;

    //Запись в младший буфер значений строки ПОСЛЕ найденного слова (с пробелом после слова)
    while (i < stringLen){
        buffer_small[j] = str[i];
        i++;
        j++;
    }

    // for (i = i; i < stringLen; i++){
        // buffer_small[]
    // }
    // toRemove = (char *)realloc(toRemove, i * sizeof(char));
    // printf ("%s", toRemove); //return 3
    removeAll (buffer_small, str, toRemove, index); //Очистка найденного остатка строки от дубликатов и перезапись старшего буфера с учётом младшего
    // free (toRemove);
}


/**
 * Remove all occurrences of a given word in string.
 */
void removeAll(char * str, char *buffer, char * toRemove, unsigned long *index)
{
    //srt - smaller buffer (work's temp)
    //buffer - bigger buffer (main)

    unsigned long i, j;
    unsigned long p = *index;
    unsigned long stringLen, toRemoveLen = 0;
    int found;

    stringLen   = strlen(str);      // Length of string
    // toRemoveLen = strlen(toRemove); // Length of word to remove
    for (i = 0; i < 100; i++){
        // if (*(toRemove + i) != '\0'){
        if (toRemove[i] != '\0'){
            toRemoveLen++;
        } else {
            break;
        }
    }


    for(i=0; i <= stringLen - toRemoveLen; i++)
    {
        /* Match word with string */
        found = 1;
        for(j=0; j < toRemoveLen; j++)
        {
            if(str[i + j] != toRemove[j])
            {
                found = 0;
                break;
            }
        }

        /* If it is not a word */ //Проверка идёт на символ ПОСЛЕ последней буквы искомого слова
        if(str[i + j] != ',' && str[i + j] != ' ' && str[i + j] != '\t' && str[i + j] != '\n' && str[i + j] != '\0') 
        {
            found = 0;
        }

        if(i != 0 && str[i - 1] != ',' && str[i - 1] != ' ' && str[i - 1] != '\t' && str[i - 1] != '\n'){
            found = 0;
        }



        /*
         * If word is found then shift all characters to left
         * and decrement the string length
         */
        if(found == 1) //Нужно переделать под маленький буфер
        {
            if (str[j] == ',') {
                for(j=i; j <= stringLen - toRemoveLen + 1; j++)
                {
                    str[j] = str[j + toRemoveLen + 1];
                }    
            } else {
                for(j=i; j <= stringLen - toRemoveLen; j++)
                {
                    // str[j] = str[j + toRemoveLen];
                    // buffer[j] = 
                }
            }
            
            stringLen = stringLen - toRemoveLen;

            // We will match next occurrence of word from current index.
            i--;
        }
    }

    //Запись маленького в большой с учётом того что было в большом
    for (i = 0; i < stringLen; i++){
        buffer[p] = str[i];
    }

}