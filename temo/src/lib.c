#include "lib.h"

void msg_format (struct mail info_for_msg_f){
    int buff;
    char *text = strdup(info_for_msg_f.sender.name);
    
    char *text2 = strcat(text, info_for_msg_f.sender.mail_name);
    // char *formatted_msg;



}