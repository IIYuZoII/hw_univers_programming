#include "entity.h"

void create_first_objects (struct mail *array, int count){
    for (int i = 0; i < count; i++) {
        (array + i)->index = i;
        (array + i)->msg_text = (char *)realloc((array + i)->msg_text, sizeof(char) * 150);
        (array + i)->msg_theme = (char *)realloc((array + i)->msg_theme, sizeof(char) * 50);
        (array + i)->format = (char *)realloc((array + i)->format, sizeof(char) * 50);
        (array + i)->sender.name = (char *)realloc((array + i)->sender.name, sizeof(char) * 50);
        (array + i)->sender.mail_name = (char *)realloc((array + i)->sender.mail_name, sizeof(char) * 50);
        (array + i)->reciever.name = (char *)realloc((array + i)->reciever.name, sizeof(char) * 50);
        (array + i)->reciever.mail_name = (char *)realloc((array + i)->reciever.mail_name, sizeof(char) * 50);
    }
}

void delete_object (struct mail *array, int count, int index_for_delete){
    int i, j;
    for (i = index_for_delete; i < count - 1; i++){
        j = i + 1;
        (array + i)->is_mail_note = (array + j)->is_mail_note;
        strcpy ((array + i)->msg_theme, (array + j)->msg_theme);
        strcpy ((array + i)->msg_text, (array + j)->msg_text);
        strcpy ((array + i)->sender.name, (array + j)->sender.name);
        strcpy ((array + i)->sender.mail_name, (array + j)->sender.mail_name);
        strcpy ((array + i)->reciever.name, (array + j)->reciever.name);
        strcpy ((array + i)->reciever.mail_name, (array + j)->reciever.mail_name);
        strcpy ((array + i)->format, (array + j)->format);
    }
}


void sorting (struct mail *array, int count, int choice) {

    switch (choice) {
    case 1:
        printf ("Case 1\n");
        for (int i = 0; i < count; i++){
            for (int j = 0; j < count - 1 - i; j++){
                if (strcmp((array + j)->sender.name, (array + j + 1)->sender.name) > 0){
                    sorting_machine (array, j);
                }
            }
        }
        break;
    case 2:
        printf ("Case 2\n");
        for (int i = 0; i < count; i++){
            for (int j = 0; j < count - 1 - i; j++){
                if (strcmp((array + j)->sender.mail_name, (array + j + 1)->sender.mail_name) > 0){
                    sorting_machine (array, j);
                }
            }
        }
        break;
    case 3:
        printf ("Case 3\n");
        for (int i = 0; i < count; i++){
            for (int j = 0; j < count - 1 - i; j++){
                if (strcmp((array + j)->reciever.name, (array + j + 1)->reciever.name) > 0){
                    sorting_machine (array, j);
                }
            }
        }
        break;
    case 4:
        printf ("Case 4\n");
        for (int i = 0; i < count; i++){
            for (int j = 0; j < count - 1 - i; j++){
                if (strcmp((array + j)->reciever.mail_name, (array + j + 1)->reciever.mail_name) > 0){
                    sorting_machine (array, j);
                }
            }
        }
    }
}

void sorting_machine (struct mail *array, int j) {
    char *temp = (char *)malloc(150 * sizeof(char));
    int t;

    strcpy (temp, (array + j)->msg_theme);
    strcpy ((array + j)->msg_theme, (array + j + 1)->msg_theme);
    strcpy ((array + j + 1)->msg_theme, temp);

    strcpy (temp, (array + j)->msg_text);
    strcpy ((array + j)->msg_text, (array + j + 1)->msg_text);
    strcpy ((array + j + 1)->msg_text, temp);

    strcpy (temp, (array + j)->sender.name);
    strcpy ((array + j)->sender.name, (array + j + 1)->sender.name);
    strcpy ((array + j + 1)->sender.name, temp);

    strcpy (temp, (array + j)->sender.mail_name);
    strcpy ((array + j)->sender.mail_name, (array + j + 1)->sender.mail_name);
    strcpy ((array + j + 1)->sender.mail_name, temp);

    strcpy (temp, (array + j)->reciever.name);
    strcpy ((array + j)->reciever.name, (array + j + 1)->reciever.name);
    strcpy ((array + j + 1)->reciever.name, temp);

    strcpy (temp, (array + j)->reciever.mail_name);
    strcpy ((array + j)->reciever.mail_name, (array + j + 1)->reciever.mail_name);
    strcpy ((array + j + 1)->reciever.mail_name, temp);

    strcpy (temp, (array + j)->format);
    strcpy ((array + j)->format, (array + j + 1)->format);
    strcpy ((array + j + 1)->format, temp);

    t = (array + j)->is_mail_note;
    (array + j)->is_mail_note = (array + j + 1)->is_mail_note;
    (array + j + 1)->is_mail_note = t;

    free (temp);
}
