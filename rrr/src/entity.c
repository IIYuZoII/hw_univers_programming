#include "entity.h"



void create_objects (struct Container *ptr, int count_of_objects) {
    for (int i = 0; i < count_of_objects; i++){
        ptr->next = (struct Container *)malloc(1 * sizeof (struct Container));
        ptr = ptr->next;

        // ptr->link.index = i;
        ptr->link.msg_theme = (char *)malloc(50 * sizeof (char));
        ptr->link.msg_text = (char *)malloc(50 * sizeof (char));
        ptr->link.reciever.name = (char *)malloc(50 * sizeof (char));
        ptr->link.reciever.mail_name = (char *)malloc(50 * sizeof (char));
        ptr->link.sender.name = (char *)malloc(50 * sizeof (char));
        ptr->link.sender.mail_name = (char *)malloc(50 * sizeof (char));
        ptr->link.format = (char *)malloc(50 * sizeof (char));

    }
    ptr->next = NULL;
}

void get_last_object (struct Container *ptr, int count_of_objects){

    struct Container *temp = (struct Container *)malloc(1 * sizeof (struct Container));
    // temp = ptr;


    for (int i = 0; i < count_of_objects; i++){
        ptr = ptr->next;
    }
    printf ("Последний индекс: %d\n", ptr->link.index);
    
    if (ptr->next == NULL){
        printf ("ptr->next == NULL\n");
    }
    temp = ptr;
    for (int i = 0; i < 2; i++){
        ptr->next = (struct Container *)malloc(1 * sizeof (struct Container));
        ptr = ptr->next;

        ptr->link.index = i * 2 * 10;
        ptr->link.msg_theme = (char *)malloc(50 * sizeof (char));
        ptr->link.msg_text = (char *)malloc(50 * sizeof (char));
        ptr->link.reciever.name = (char *)malloc(50 * sizeof (char));
        ptr->link.reciever.mail_name = (char *)malloc(50 * sizeof (char));
        ptr->link.sender.name = (char *)malloc(50 * sizeof (char));
        ptr->link.sender.mail_name = (char *)malloc(50 * sizeof (char));
        ptr->link.format = (char *)malloc(50 * sizeof (char));
    }


    printf ("Последний индекс: %d\n", ptr->link.index);
    ptr = temp;
    // printf ("Now current index is: %d\n", ptr->link.index);


}


void printer_scanner (struct Container *ptr, int count_of_objects, int count_of_added_elements){

    for (; ptr != NULL; ptr = ptr->next){

        printf ("Starts index in func printer_scanner is: %d\n", ptr->link.index);
        for (int i = 0; i < count_of_objects - count_of_added_elements; i++){
            ptr = ptr->next;

        }
        printf ("Index in func printer_scanner is: %d\n", ptr->link.index);

        printf("Сообщение черновик? (0 - да, 1 - нет):\n");
        scanf("%d", &(ptr->link.is_mail_note));

        printf("Тема сообщения:\n");
        scanf("%s", (ptr->link.msg_theme));

        printf("Текст сообщения (в данной версии программы пробелы запрещенны)\n");
        scanf("%s", (ptr->link.msg_text));

        printf("Имя отправителя:\n");
        scanf("%s", (ptr->link.sender.name));

        printf("Адрес почты отправителя:\n");
        scanf("%s", (ptr->link.sender.mail_name));

        printf("Имя получателя:\n");
        scanf("%s", (ptr->link.reciever.name));

        printf("Адрес почты получателя:\n");
        scanf("%s", (ptr->link.reciever.mail_name));

        printf("Формат текста:\n");
        scanf("%s", (ptr->link.format));
        
        printf("\n");

        // ptr = ptr->next;
    }
}