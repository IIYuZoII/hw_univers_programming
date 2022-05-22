#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


struct Container {
    struct mail link;

    struct Container *next;
};




void create_objects (struct Container *ptr, int count_of_objects);



void get_last_object (struct Container *ptr, int count_of_objects);




void printer_scanner (struct Container *ptr, int count_of_objects, int count_of_added_elements);

