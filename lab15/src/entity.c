#include "entity.h"

/**
 * @brief Функція пошуку всіх повідомлень від конкретної людини
 *
 * @param msgs об'єкт структури "Пошта"
 * @param count_mails кількість рядків (= кількості повідомлень)
 * @param sender ім'я відправника
 * @param sender_mail адреса поштової скриньки відправника
 * @param msg_line_res результуюча строка з усіма повідомленнями, кожне
 * повідомлення з нового рядку
 */

void printer_scanner(struct mail *array, int k, int count) {
  for (int i = k; i < count; i++) {
    printf("Сообщение черновик? (0 - да, 1 - нет):\n");
    scanf("%d", &((array + i)->is_mail_note));

    printf("Тема сообщения:\n");
    scanf("%s", ((array + i)->msg_theme));

    printf("Текст сообщения (в данной версии программы пробелы запрещенны)\n");
    scanf("%s", ((array + i)->msg_text));

    printf("Имя отправителя:\n");
    scanf("%s", ((array + i)->sender.name));
    
    printf("Адрес почты отправителя:\n");
    scanf("%s", ((array + i)->sender.mail_name));
    
    printf("Имя получателя:\n");
    scanf("%s", ((array + i)->reciever.name));
    
    printf("Адрес почты получателя:\n");
    scanf("%s", ((array + i)->reciever.mail_name));
    
    printf("Формат текста:\n");
    scanf("%s", ((array + i)->format));

    printf("\n");
  }

}

void msg_find(struct mail *msgs, int count_mails, char *sender,
              char *sender_mail, char *msg_line_res) {
  int res, res2;
  char space[] = "\n";

  for (int i = 0; i < count_mails; i++) {

    res2 = strcmp((msgs + i)->sender.name, sender);
    res = strcmp((msgs + i)->sender.mail_name, sender_mail);
    if (res == 0 && res2 == 0) {
      strcat(msg_line_res, (msgs + i)->msg_text);
      strcat(msg_line_res, space);
    }
  }
  printf("All messages from specific user '%s' '%s': \n%s\n\n", sender,
         sender_mail, msg_line_res);
}

// void add_elem_in_array(struct mail *array, struct mail *array2, int count, int pos) {

void add_elem_in_array(struct mail *array, int count, int pos) {
  
  struct mail *array2 = (struct mail *)malloc((unsigned long)pos * sizeof(struct mail));

  // for (int i = 0; i < count; i++) {
  //   (array2 + i)->msg_text = (char *)realloc((array + i)->msg_text, sizeof(char) * 50);
  //   (array2 + i)->msg_theme = (char *)realloc((array + i)->msg_theme, sizeof(char) * 50);
  //   (array2 + i)->format = (char *)realloc((array + i)->format, sizeof(char) * 50);
  //   (array2 + i)->sender.name = (char *)realloc((array + i)->sender.name, sizeof(char) * 50);
  //   (array2 + i)->sender.mail_name = (char *)realloc((array + i)->sender.mail_name, sizeof(char) * 50);
  //   (array2 + i)->reciever.name = (char *)realloc((array + i)->reciever.name, sizeof(char) * 50);
  //   (array2 + i)->reciever.mail_name = (char *)realloc((array + i)->reciever.mail_name, sizeof(char) * 50);
  // }

  for (int i = 0; i < count; i++) {
    (array2 + i)->msg_text = (char *)malloc(sizeof(char) * 50);
    (array2 + i)->msg_theme = (char *)malloc(sizeof(char) * 50);
    (array2 + i)->format = (char *)malloc(sizeof(char) * 50);
    (array2 + i)->sender.name = (char *)malloc(sizeof(char) * 50);
    (array2 + i)->sender.mail_name = (char *)malloc(sizeof(char) * 50);
    (array2 + i)->reciever.name = (char *)malloc(sizeof(char) * 50);
    (array2 + i)->reciever.mail_name = (char *)malloc(sizeof(char) * 50);
  }


  for (int i = 0; i < count - 1; i++) {
    (array2 + i)->is_mail_note = (array + i)->is_mail_note;
    strcpy((array2 + i)->msg_theme, (array + i)->msg_theme);
    strcpy((array2 + i)->msg_text, (array + i)->msg_text);
    strcpy((array2 + i)->sender.name, (array + i)->sender.name);
    strcpy((array2 + i)->sender.mail_name, (array + i)->sender.mail_name);
    strcpy((array2 + i)->reciever.name, (array + i)->reciever.name);
    strcpy((array2 + i)->reciever.mail_name, (array + i)->reciever.mail_name);
    strcpy((array2 + i)->format, (array + i)->format);
  }
  

  // memcpy(array2, array, pos * sizeof(struct mail));

 //Try to do free before allocate new memory:
  for (int i = 0; i < count - 1; i++) {
    free((array + i)->msg_theme);
    free((array + i)->msg_text);
    free((array + i)->sender.name);
    free((array + i)->sender.mail_name); //Really works (memory will be free after this)
    free((array + i)->reciever.name);
    free((array + i)->reciever.mail_name);
    free((array + i)->format);
  }
  free (array);


  array = (struct mail *)malloc((unsigned long)count * sizeof(struct mail));
  for (int i = 0; i < count; i++) {
    (array + i)->msg_text = (char *)malloc(sizeof(char) * 50);
    (array + i)->msg_theme = (char *)malloc(sizeof(char) * 50);
    (array + i)->format = (char *)malloc(sizeof(char) * 50);
    (array + i)->sender.name = (char *)malloc(sizeof(char) * 50);
    (array + i)->sender.mail_name = (char *)malloc(sizeof(char) * 50);
    (array + i)->reciever.name = (char *)malloc(sizeof(char) * 50);
    (array + i)->reciever.mail_name = (char *)malloc(sizeof(char) * 50);
    
    // (array + i)->msg_text = (char *)calloc(sizeof(char), 50);
    // (array + i)->msg_theme = (char *)calloc(sizeof(char), 50);
    // (array + i)->format = (char *)calloc(sizeof(char), 50);
    // (array + i)->sender.name = (char *)calloc(sizeof(char), 50);
    // (array + i)->sender.mail_name = (char *)calloc(sizeof(char), 50);
    // (array + i)->reciever.name = (char *)calloc(sizeof(char), 50);
    // (array + i)->reciever.mail_name = (char *)calloc(sizeof(char), 50);

  }


  for (int i = 0; i < count - 1; i++) {
    (array + i)->is_mail_note = (array2 + i)->is_mail_note;
    strcpy((array + i)->msg_theme, (array2 + i)->msg_theme);
    strcpy((array + i)->msg_text, (array2 + i)->msg_text);
    strcpy((array + i)->sender.name, (array2 + i)->sender.name);
    strcpy((array + i)->sender.mail_name, (array2 + i)->sender.mail_name);
    strcpy((array + i)->reciever.name, (array2 + i)->reciever.name);
    strcpy((array + i)->reciever.mail_name, (array2 + i)->reciever.mail_name);
    strcpy((array + i)->format, (array2 + i)->format);
  }

  // for (int i = 0; i < count; i++){
  //   assert((array + i)->msg_theme);
  //   assert((array + i)->msg_text);
  //   assert((array + i)->sender.name);
  //   assert((array + i)->sender.name);
  //   assert((array + i)->reciever.name);
  //   assert((array + i)->reciever.mail_name);
  //   assert((array + i)->format);
  // }

  // memcpy (array, array2, pos * sizeof(struct mail));

  // for (int i = 0; i < count - 1; i++){
  //   free((array2 + i)->msg_theme);
  //   free((array2 + i)->msg_text);
  //   free((array2 + i)->sender.name);
  //   free((array2 + i)->sender.mail_name);
  //   free((array2 + i)->reciever.name);
  //   free((array2 + i)->reciever.mail_name);
  //   free((array2 + i)->format);
  // }
  // free (array2);

  // for (int i = 0; i < count; i++) {
  //   (array + i)->msg_text = (char *)realloc((array + i)->msg_text, sizeof(char) * 50);
  //   (array + i)->msg_theme = (char *)realloc((array + i)->msg_theme, sizeof(char) * 50);
  //   (array + i)->format = (char *)realloc((array + i)->format, sizeof(char) * 50);
  //   (array + i)->sender.name = (char *)realloc((array + i)->sender.name, sizeof(char) * 50);
  //   (array + i)->sender.mail_name = (char *)realloc((array + i)->sender.mail_name, sizeof(char) * 50);
  //   (array + i)->reciever.name = (char *)realloc((array + i)->reciever.name, sizeof(char) * 50);
  //   (array + i)->reciever.mail_name = (char *)realloc((array + i)->reciever.mail_name, sizeof(char) * 50);
  // }

  // for (int i = pos; i < count; i++) {
  //   (array + i)->msg_text = (char *)malloc(sizeof(char) * 50);
  //   (array + i)->msg_theme = (char *)malloc(sizeof(char) * 50);
  //   (array + i)->format = (char *)malloc(sizeof(char) * 50);
  //   (array + i)->sender.name = (char *)malloc(sizeof(char) * 50);
  //   (array + i)->sender.mail_name = (char *)malloc(sizeof(char) * 50);
  //   (array + i)->reciever.name = (char *)malloc(sizeof(char) * 50);
  //   (array + i)->reciever.mail_name = (char *)malloc(sizeof(char) * 50);
  // }
  // if (pos > count) {
  //     pos = count;
  // }


//   for (int i = 0; i < count - 1; i++) {
//     (array2 + i)->is_mail_note = (array + i)->is_mail_note;
//     strcpy((array2 + i)->msg_theme, (array + i)->msg_theme);
//     strcpy((array2 + i)->msg_text, (array + i)->msg_text);
//     strcpy((array2 + i)->sender.name, (array + i)->sender.name);
//     strcpy((array2 + i)->sender.mail_name, (array + i)->sender.mail_name);
//     strcpy((array2 + i)->reciever.name, (array + i)->reciever.name);
//     strcpy((array2 + i)->reciever.mail_name, (array + i)->reciever.mail_name);
//     strcpy((array2 + i)->format, (array + i)->format);
//   }
}
