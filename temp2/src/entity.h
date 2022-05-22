// Back-end work with structs
#ifndef entity
// #ifdef ENTITY_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
  int index;

  int is_mail_note; // 0 - True; 1 - False
  char *msg_theme;
  char *msg_text;

  struct people sender;
  struct people reciever;

  char *format;
};

void create_first_objects (struct mail *array, int count);


void delete_object (struct mail *array, int count, int index_for_delete);


// void printer_scanner (struct mail *array, int k, int count);


void sorting (struct mail *array, int count, int choise);


void sorting_machine (struct mail *array, int j);



#define entity

#endif