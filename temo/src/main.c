// #include "lib.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct people {
  int index;
  char *name;
};

struct list {
  struct people x;
  struct list *next;
};




int main () {
  struct list *sub = (struct list *)malloc(1 * sizeof (struct list));
  sub->x.name = (char *)malloc(50 * sizeof (char));

  struct list *ptr = (struct list *)malloc(1 * sizeof (struct list));

  ptr = sub;


  sub->x.index = 0;

  printf ("Первый элемент: %d\n", sub->x.index);

  int temp = 0;


  //Алгоритм добавления элемента (в конец списка)
  for (int i = 0; i < 10; i++){
    temp++;
    ptr->next = (struct list *)malloc(1 * sizeof (struct list)); //сейчас он указывает на предидущий элемент списка

    ptr = ptr->next; //теперь он указывает на текущий элемент списка

    ptr->x.name = (struct people *)malloc(50 * sizeof (struct people));
    strcpy (ptr->x.name, "Name");
    ptr->x.index = temp;
    printf ("Текущий индекс: %d\nString is: %s\n", ptr->x.index, ptr->x.name);

  }



//   ptr = sub->next; //Возврат на второй элемент
//   ptr = sub; //Возврат на первый элемент
//   for (int i = 0; i < 10; i++){
//     //   printf ("Текущий х.name в другом цикле: %d\n", ptr->x.name);

//     if (i == 1){
//       printf ("х.name #2: %d\n", ptr->x.name);
//     }
//     printf ("Index: %d\n", ptr->x.index);

//     ptr = ptr->next;
    
//   }

 
  //Хочу удалить 8 элемент
  ptr = sub;
//   int *temp_temp = ptr;
  struct list *temp_ptr = (struct list *)malloc(1 * sizeof (struct list));
  for (int i = 0; i < 10; i++){
    temp_ptr = ptr; //Равен предидущему объекту от того который нужно удалить
    ptr = ptr->next; //Переход на следующий оюъект
    if (i == 7){ //Нашли 8 элемент
        ptr = ptr->next; //Перешли на след элемент
        temp_ptr->next = ptr; //Записали в 7 элемент адресс 9-го
        printf ("Current object is: %d\n", ptr->x.index);
        break;
    }
  }

  ptr = sub;
  for (int i = 0; i < 9; i++){
      printf("List of indexes: %d\n", ptr->x.index);
      ptr = ptr->next;
  }


//   ptr->next = (struct list *)malloc(1 * sizeof (struct list));
//   ptr = ptr->next;




}

