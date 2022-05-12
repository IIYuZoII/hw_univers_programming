#include "lib.h"

int find_count_words_in_line(char *str) {

  int checker_words = 0;
  int count_words = 0;
  unsigned long i = 0, stringLen;

  stringLen = strlen(str);

  //Перебираем строку до её конца
  while (i < stringLen + 1) {
    if (isalpha(*(str + i)) != 0) {
      checker_words = 1;
    }
    if (checker_words == 1 && isdigit(*(str + i)) != 0) {
      checker_words = 0;
      continue;
    }
    if (isalpha(*(str + i)) == 0 && isdigit(*(str + i)) == 0 &&
        checker_words == 1) {
      checker_words = 0;
      count_words++;
    }

    i++;
  }

  return (count_words);
}