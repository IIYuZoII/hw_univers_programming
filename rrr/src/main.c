#include "entity.h"


int main (){
    int i;

    int count, count_of_added_elements = 2, index_for_delete;
    printf("Введите кол-во объектов: ");
    scanf("%d", &count);
    count--;


    struct Container *head = (struct Container *)malloc(1 * sizeof (struct Container)); 

    head->link.msg_theme = (char *)malloc(50 * sizeof (char));
    head->link.msg_text = (char *)malloc(50 * sizeof (char));
    head->link.reciever.name = (char *)malloc(50 * sizeof (char));
    head->link.reciever.mail_name = (char *)malloc(50 * sizeof (char));
    head->link.sender.name = (char *)malloc(50 * sizeof (char));
    head->link.sender.mail_name = (char *)malloc(50 * sizeof (char));
    head->link.format = (char *)malloc(50 * sizeof (char));

    struct Container *ptr = (struct Container *)malloc(1 * sizeof (struct Container));
    ptr = head;


    create_objects (ptr, count);


    for (ptr = head; ptr != NULL; ptr = ptr->next){  
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

    int temp = 1;
    for (ptr = head; ptr != NULL; ptr = ptr->next){
      ptr->link.index = temp - 1;
      printf ("%d object is: \n", temp);
      temp++;
      printf ("Index is: %d\n%d\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n", 
        ptr->link.index,
        ptr->link.is_mail_note,
        ptr->link.msg_theme,
        ptr->link.msg_text,
        ptr->link.sender.name,
        ptr->link.sender.mail_name,
        ptr->link.reciever.name,
        ptr->link.reciever.mail_name,
        ptr->link.format
      );
    }

    ptr = head;
    get_last_object(ptr, count); //Так же добавляет +2 объекта
    printf ("Now current index is: %d\n", ptr->link.index);

    printer_scanner (ptr, count, count_of_added_elements);



    temp = 1;
    for (ptr = head; ptr != NULL; ptr = ptr->next){
      ptr->link.index = temp - 1;
      printf ("%d object is: \n", temp);
      temp++;
      printf ("Index is: %d\n%d\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n", 
        ptr->link.index,
        ptr->link.is_mail_note,
        ptr->link.msg_theme,
        ptr->link.msg_text,
        ptr->link.sender.name,
        ptr->link.sender.mail_name,
        ptr->link.reciever.name,
        ptr->link.reciever.mail_name,
        ptr->link.format
      );
    }

    // printf("Введите кол-во новых элементов: \n");
    // scanf("%d", &count_of_added_elements);
    // count +=  count_of_added_elements;


    return (0);
}