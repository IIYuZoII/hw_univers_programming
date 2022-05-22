#include "entity.h"


void create_objects (struct Container *ptr, int count_of_objects){
    for (int i = 0; i < count_of_objects; i++){
        ptr->next = (struct Container *)malloc(1 * sizeof (struct Container));
        ptr = ptr->next;

        ptr->x.msg_theme = (char *)malloc(50 * sizeof (char));
        ptr->x.msg_text = (char *)malloc(50 * sizeof (char));
        ptr->x.reciever.name = (char *)malloc(50 * sizeof (char));
        ptr->x.reciever.mail_name = (char *)malloc(50 * sizeof (char));
        ptr->x.sender.name = (char *)malloc(50 * sizeof (char));
        ptr->x.sender.mail_name = (char *)malloc(50 * sizeof (char));
        ptr->x.format = (char *)malloc(50 * sizeof (char));

    }
    ptr->next = NULL;
}


// void create_objects (struct Container **ptr, int count){
//     struct List *node = (struct Container *)malloc(sizeof(struct Container));
//     if(node == NULL) {
//         exit(1);
//     }

//     if(ptr == NULL) {
//         ptr = node;
//         return;
//     }

//     struct List *sub = *ptr;
//     while (sub->next != NULL) {
//         sub = sub->next;
//     }
//     sub->next = node;

// }



void add_element_in_the_end (struct Container *ptr, struct Container *container, int count_of_objects, int count_of_added_objects){
    // for (int i = 0; i <= count_of_objects; i++){
    //     ptr = ptr->next;
    // }
    
    // for (ptr = container; ptr != NULL; ptr = ptr->next){
        // printf ("Current object is: %s", ptr->x.format);
    // }
    ptr = container;
    for (int i = 0; i < count_of_objects - 1; i++, ptr = ptr->next){
        printf ("Current object is: %s", ptr->x.format);
    }

    for (int i = 0; i < count_of_added_objects; i++){
        
        ptr->next = (struct Container *)malloc(1 * sizeof (struct Container));
        ptr = ptr->next;

        ptr->x.msg_theme = (char *)malloc(50 * sizeof (char));
        ptr->x.msg_text = (char *)malloc(50 * sizeof (char));
        ptr->x.reciever.name = (char *)malloc(50 * sizeof (char));
        ptr->x.reciever.mail_name = (char *)malloc(50 * sizeof (char));
        ptr->x.sender.name = (char *)malloc(50 * sizeof (char));
        ptr->x.sender.mail_name = (char *)malloc(50 * sizeof (char));
        ptr->x.format = (char *)malloc(50 * sizeof (char));
    }
}

