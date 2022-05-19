#include "entity.h"
#include "list.h"

int main() {
  int i;

  int count;
  printf("Введите кол-во объектов: ");
  scanf("%d", &count);

  char *msg_from_specific_user = (char *)malloc(500 * sizeof(char));
  char *specific_sender = (char *)malloc(50 * sizeof(char));
  char *specific_sender_mail = (char *)malloc(50 * sizeof(char));

  struct mail *array =
      (struct mail *)malloc((unsigned long)count * sizeof(struct mail));
  for (i = 0; i < count; i++) {
    (array + i)->msg_text = (char *)malloc(sizeof(char) * 50);
    (array + i)->msg_theme = (char *)malloc(sizeof(char) * 50);
    (array + i)->format = (char *)malloc(sizeof(char) * 50);
    (array + i)->sender.name = (char *)malloc(sizeof(char) * 50);
    (array + i)->sender.mail_name = (char *)malloc(sizeof(char) * 50);
    (array + i)->reciever.name = (char *)malloc(sizeof(char) * 50);
    (array + i)->reciever.mail_name = (char *)malloc(sizeof(char) * 50);
  }

  printf("Введите данные объектов:\n");
  int k = 0;
  printer_scanner(array, k, count);

  // i = 0;
  // while (i < count) {
  //   printf("%d\n%s\n", (array + i)->is_mail_note, (array + i)->msg_theme);
  //     printf("%s\n%s\n%s\n%s\n%s\n%s\n", (array + i)->msg_text,
  //            (array + i)->sender.name, (array + i)->sender.mail_name,
  //            (array + i)->reciever.name, (array + i)->reciever.mail_name,
  //            (array + i)->format);
  //   i++;
  // }
  // for(int i = 0; i < count; i++) {
  //     printf("Сообщение черновик? (0 - да, 1 - нет):\n");
  //     scanf("%d", &((array + i)->is_mail_note));
  //     printf("Тема сообщения:\n");
  //     scanf("%s", &((array + i)->msg_theme));
  //     printf("Текст сообщения (в данной версии программы пробелы
  //     запрещенны)\n"); scanf("%d", &((array + i)->msg_text)); printf("Имя
  //     отправителя:\n"); scanf("%s", &((array + i)->sender.name));
  //     printf("Адрес почты отправителя:\n");
  //     scanf("%s", &((array + i)->sender.mail_name));
  //     printf("Имя получателя:\n");
  //     scanf("%s", &((array + i)->reciever.name));
  //     printf("Адрес почты получателя:\n");
  //     scanf("%s", &((array + i)->reciever.mail_name));
  //     printf("Формат текста:\n");
  //     scanf("%s", &((array + i)->format));
  //     printf("\n");
  // }

  int pos = count;
  count += 1;
  // struct mail *array2 =
      // (struct mail *)malloc((unsigned long)count * sizeof(struct mail));


  // add_elem_in_array(array, array2, count, pos);
  add_elem_in_array(array, count, pos);

  i = 0;
  // while (i < count) {
  //   printf("%d\n%s\n", (array + i)->is_mail_note, (array + i)->msg_theme);
  //     printf("%s\n%s\n%s\n%s\n%s\n%s\n", (array + i)->msg_text,
  //            (array + i)->sender.name, (array + i)->sender.mail_name,
  //            (array + i)->reciever.name, (array + i)->reciever.mail_name,
  //            (array + i)->format);
  //   i++;
  // }

  printf("Введите данные для добавленного объекта:\n");
  k = count - 1;
  printer_scanner(array, k, count);

  
  return (0);
}