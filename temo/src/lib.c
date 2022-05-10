// Текст – це перелік прізвищ студентів через кому. Видалити з тексту усі дублікати.


#include "lib.h"



int test() {

	char wrd[256], buffer[256];
	int n, m, i, j, line;
	
	FILE* fp;
	fp = fopen("../assets/input.txt", "r");	// open file

	printf("Enter the word you want to search in the file: ");
    scanf("%s", wrd);

	m = (int)strlen(wrd); // length of input word

	printf("All positions of word \"%s\" in the file\n", wrd);

	line = 0;
	// the following loop the file fp line by line
	// each line is stored in buffer
	while (fgets(buffer, 256, fp) != NULL) {

		i = 0;
		n = (int)strlen(buffer);
		// the followinf loop find position of the input word in the current line and
		// print the position of the word on the screen
		// the loop basically reads each word of the file and compare it with the input word
		while (i < n) {

			// comparing current word with input word
			j = 0;
			while (i < n && j < m && buffer[i] == wrd[j]) {
				++i, ++j;
			}

			// the following condition implies that the current word of buffer
			// is equal to input word
			if ((i == n || buffer[i] == ' ' || buffer[i] == '\n') && j == m) {
				printf("Line: %d ", line);
				printf("Column: %d\n", i - m);
			}

			// moving to next word
			while (i < n && buffer[i] != ' ') {
				++i;
			}
			++i;

		}

		++line;

	}

	fclose(fp);
    return(0);
}