#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct people {
      char *name;
      char *mail_name;
}; 


struct mail {
    bool is_mail_note;
    char *msg_theme;
    char *msg_text;

    struct people sender;
    struct people reciever;

    char *format;
};

void msg_format (struct mail info_for_msg_f);

void msg_lenght (struct mail info_for_msg_l);




