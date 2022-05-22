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


void create_objects (struct Container *ptr, int count_of_objects);


// void create_objects (struct Container **ptr, int count);

void add_element_in_the_end (struct Container *ptr, struct Container *container, int count_of_objects, int count_of_added_objects);