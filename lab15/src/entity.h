// Back-end work with structs

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/**
 * @brief Структура "Людина"
 *
 */
struct people {
  char *name;
  char *mail_name;
};

/**
 * @brief Структура "Пошта"
 *
 */
struct mail {
  int is_mail_note; // 0 - True; 1 - False
  char *msg_theme;
  char *msg_text;

  struct people sender;
  struct people reciever;

  char *format;
};

void printer_scanner(struct mail *array, int k, int count);

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
void msg_find(struct mail *msgs, int count_mails, char *sender,
              char *sender_mail, char *msg_line_res);


void add_elem_in_array(struct mail *array, int count, int pos);


//void add_elem_in_array(struct mail *array, struct mail *array2, int count, int pos);

