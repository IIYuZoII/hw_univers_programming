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
    bool is_mail_note;
    char *msg_theme;
    char *msg_text;

    struct people sender;
    struct people reciever;

    char *format;
};



void msg_format (struct mail info_for_msg_f);

int main (){

    // робота з файлами
  FILE *fpInput = fopen("../assets/input.txt", "r");
  FILE *fpOutput = fopen("../assets/output.txt", "w");

  // кількість об'єктів структур
  int count = 3;

  size_t n = 3;

  // виділення пам'яті для структури
  struct mail *array = (struct mail *)malloc(sizeof(struct mail) * (unsigned long)count);

  for (int i = 0; i < count; i++) {
    (array + i)->msg_text = (char *)malloc(sizeof(char) * 50);
    (array + i)->msg_theme = (char *)malloc(sizeof(char) * 50);
    (array + i)->format = (char *)malloc(sizeof(char) * 50);

    (array + i)->sender.name = (char *)malloc(sizeof(char) * 50);
    (array + i)->sender.mail_name = (char *)malloc(sizeof(char) * 50);

    (array + i)->reciever.mail_name = (char *)malloc(sizeof(char) * 50);
    (array + i)->reciever.name = (char *)malloc(sizeof(char) * 50);
  }

    // msg_format()
}


void msg_format (struct mail info_for_msg_f){
    int buff;
    char *text = strdup(info_for_msg_f.sender.name);
    
    char *text2 = strcat(text, info_for_msg_f.sender.mail_name);
    // char *formatted_msg;



}

