#include "lib.h"

#define BUFFER_SIZE 1000

int main() {
  FILE *fPtr;

  char *path = (char *)malloc(100 * sizeof(char));
  char *buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));

  int number_of_words = 0;

  printf("Enter path of source file: ");
  scanf("%s", path);

  //Открытие файла
  fPtr = fopen(path, "r");

  //Если файл не удалось открыть
  if (fPtr == NULL) {
    printf("\nUnable to open file.\n");
    free(path);
    free(buffer);
    return (0);
  }

  //Перебор файла построчно
  while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL) {
    number_of_words += find_count_words_in_line(buffer);
  }

  printf("\nNumber of words in file '%s': \n%d\n", path, number_of_words);

  free(path);
  free(buffer);

  return (0);
}