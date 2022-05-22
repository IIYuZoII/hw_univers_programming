// #include "lib.h"

#include "entity.h"
// #include <stdbool.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>


// struct people {
//   char *name;
//   char *mail_name;
// };


// struct mail {
//   int is_mail_note; // 0 - True; 1 - False
//   char *msg_theme;
//   char *msg_text;

//   struct people sender;
//   struct people reciever;

//   char *format;
// };

// struct Container {
//     struct mail x;
//     struct Container *next;
// };

int main () {
    int count_of_objects, count_of_added_objects;


    //Правильнее будет переименовать контейнер на хед
    struct Container *container = (struct Container *)malloc(1 * sizeof (struct Container)); //Выделяем память для УКАЗАТЕЛЯ на объект
    
    //Выделяем память для ПАРАМЕТРОВ объекта
    container->x.msg_theme = (char *)malloc(50 * sizeof (char));
    container->x.msg_text = (char *)malloc(50 * sizeof (char));
    container->x.reciever.name = (char *)malloc(50 * sizeof (char));
    container->x.reciever.mail_name = (char *)malloc(50 * sizeof (char));
    container->x.sender.name = (char *)malloc(50 * sizeof (char));
    container->x.sender.mail_name = (char *)malloc(50 * sizeof (char));
    container->x.format = (char *)malloc(50 * sizeof (char));

    struct Container *ptr = (struct Container *)malloc(1 * sizeof (struct Container));
    ptr = container;

    printf ("\nInput your count of objects: ");
    scanf ("%d", &count_of_objects);
    count_of_objects--;


    create_objects (ptr, count_of_objects);




    // ptr = container;
    // for (int i = 0; i < 3; i++){
    //Fill objects
    for (ptr = container; ptr != NULL; ptr = ptr->next){  
        printf("Сообщение черновик? (0 - да, 1 - нет):\n");
        scanf("%d", &(ptr->x.is_mail_note));

        printf("Тема сообщения:\n");
        scanf("%s", (ptr->x.msg_theme));

        printf("Текст сообщения (в данной версии программы пробелы запрещенны)\n");
        scanf("%s", (ptr->x.msg_text));

        printf("Имя отправителя:\n");
        scanf("%s", (ptr->x.sender.name));

        printf("Адрес почты отправителя:\n");
        scanf("%s", (ptr->x.sender.mail_name));

        printf("Имя получателя:\n");
        scanf("%s", (ptr->x.reciever.name));

        printf("Адрес почты получателя:\n");
        scanf("%s", (ptr->x.reciever.mail_name));

        printf("Формат текста:\n");
        scanf("%s", (ptr->x.format));
        
        printf("\n");

        // ptr = ptr->next;
    }

    int temp = 1;
    for (ptr = container; ptr != NULL; ptr = ptr->next){

      printf ("%d object is: \n", temp);
      temp++;
      printf ("%d\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n", 
        ptr->x.is_mail_note,
        ptr->x.msg_theme,
        ptr->x.msg_text,
        ptr->x.sender.name,
        ptr->x.sender.mail_name,
        ptr->x.reciever.name,
        ptr->x.reciever.mail_name,
        ptr->x.format
      );
    }

    printf ("\nInput count for add objects: ");
    scanf ("%d", &count_of_added_objects);

    ptr = container;
    add_element_in_the_end (ptr, count_of_objects, count_of_added_objects);


    //Fill NEW objects
    ptr = container;
    for (int i = 0; i < count_of_added_objects; i++){

        for (int j = 0; j < count_of_objects; j++){
            ptr = ptr->next;
        }

        printf("Сообщение черновик? (0 - да, 1 - нет):\n");
        scanf("%d", &(ptr->x.is_mail_note));

        printf("Тема сообщения:\n");
        scanf("%s", (ptr->x.msg_theme));

        printf("Текст сообщения (в данной версии программы пробелы запрещенны)\n");
        scanf("%s", (ptr->x.msg_text));

        printf("Имя отправителя:\n");
        scanf("%s", (ptr->x.sender.name));

        printf("Адрес почты отправителя:\n");
        scanf("%s", (ptr->x.sender.mail_name));

        printf("Имя получателя:\n");
        scanf("%s", (ptr->x.reciever.name));

        printf("Адрес почты получателя:\n");
        scanf("%s", (ptr->x.reciever.mail_name));

        printf("Формат текста:\n");
        scanf("%s", (ptr->x.format));
        
        printf("\n");
    }




    count_of_objects += count_of_added_objects;

    //Output all objects
    temp = 1;
    // for (ptr = container; ptr != NULL; ptr = ptr->next){
    for (int i = 0; i < count_of_objects; i++ ){

      printf ("%d object is: \n", temp);
      temp++;
      printf ("%d\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n", 
        ptr->x.is_mail_note,
        ptr->x.msg_theme,
        ptr->x.msg_text,
        ptr->x.sender.name,
        ptr->x.sender.mail_name,
        ptr->x.reciever.name,
        ptr->x.reciever.mail_name,
        ptr->x.format
      );
      
    }





    return (0);
}






