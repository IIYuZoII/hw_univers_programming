// #include "lib.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct people {
  char *name;
  char *mail_name;
};


struct mail {
  int is_mail_note; // 0 - True; 1 - False
  char *msg_theme;
  char *msg_text;

  struct people sender;
  struct people reciever;

  char *format;
};

struct Container {
    struct mail x;
    struct Container *next;
};

int main () {
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


    for (int i = 0; i < 3; i++){
        ptr->next = (struct Container *)malloc(1 * sizeof (struct Container));

        ptr->x.msg_theme = (char *)malloc(50 * sizeof (char));
        ptr->x.msg_text = (char *)malloc(50 * sizeof (char));
        ptr->x.reciever.name = (char *)malloc(50 * sizeof (char));
        ptr->x.reciever.mail_name = (char *)malloc(50 * sizeof (char));
        ptr->x.sender.name = (char *)malloc(50 * sizeof (char));
        ptr->x.sender.mail_name = (char *)malloc(50 * sizeof (char));
        ptr->x.format = (char *)malloc(50 * sizeof (char));

        ptr = ptr->next;
    }




    ptr = container;
    for (int i = 0; i < 4; i++){
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

        ptr = ptr->next;
    }





    return (0);
}






