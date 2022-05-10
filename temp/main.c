/**
 * C program to delete a word from file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

// void find_duplicates(char *str);
void removeAll(char * str, const char * toRemove);


int main()
{
    FILE * fPtr;
    FILE * fTemp;

    

    char path[100];
    
    char toRemove[100];
    char buffer[1000];


    /* Input source file path path */
    printf("Enter path of source file: ");
    scanf("%s", path);

    printf("Enter word to remove: ");
    scanf("%s", toRemove);


    /*  Open files */
    fPtr  = fopen(path, "r");
    // fseek(fPtr, 0, SEEK_END);
    // int ssize = (int)ftell(fPtr);
    // fseek(fPtr, 0, SEEK_SET);
    // printf("%d", ssize);
    fTemp = fopen("delete.tmp", "w"); 

    /* fopen() return NULL if unable to open file in given mode. */
    if (fPtr == NULL || fTemp == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }


    /*
     * Read line from source file and write to destination 
     * file after removing given word.
     */
    while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
    {
        // find_duplicates(buffer);

        // Remove all occurrence of word from current line
        removeAll(buffer, toRemove);

        // Write to temp file
        fputs(buffer, fTemp);
    }


    /* Close all files to release resource */
    fclose(fPtr);
    fclose(fTemp);


    /* Delete original source file */
    remove(path);

    /* Rename temp file as original file */
    rename("delete.tmp", path);


    printf("\nAll occurrence of '%s' removed successfully.", toRemove);

    return 0;
}


// void find_duplicates(char *str){
//     unsigned long i, j;
//     unsigned long stringLen;
    
//     // char toRemove[100];
//     char *toRemove = (char *)malloc(100 * sizeof(char));
//     int found;

//     stringLen = strlen(str);


    
//     for (i = 0; i < 100; i++){
//         if (str[i] != ',' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\0'){
//             *(toRemove + i) = str[i];
//         }
//     }
//     *(toRemove + i) = '\0';
//     removeAll (str, toRemove);

// }


/**
 * Remove all occurrences of a given word in string.
 */
void removeAll(char * str, const char * toRemove)
{
    unsigned long i, j;
    unsigned long stringLen, toRemoveLen;
    int found;

    stringLen   = strlen(str);      // Length of string
    toRemoveLen = strlen(toRemove); // Length of word to remove


    for(i=0; i <= stringLen - toRemoveLen; i++)
    {
        /* Match word with string */
        found = 1;
        for(j=0; j < toRemoveLen; j++)
        {
            if(str[i + j] != toRemove[j])
            {
                found = 0;
                break;
            }
        }

        /* If it is not a word */
        if(str[i + j] != ',' && str[i + j] != ' ' && str[i + j] != '\t' && str[i + j] != '\n' && str[i + j] != '\0') 
        {
            found = 0;
        }

        if(i != 0 && str[i - 1] != ',' && str[i - 1] != ' ' && str[i - 1] != '\t' && str[i - 1] != '\n'){
            found = 0;
        }



        /*
         * If word is found then shift all characters to left
         * and decrement the string length
         */
        if(found == 1)
        {
            if (str[j] == ',') {
                for(j=i; j <= stringLen - toRemoveLen + 1; j++)
                {
                    str[j] = str[j + toRemoveLen + 1];
                }    
            } else {
                for(j=i; j <= stringLen - toRemoveLen; j++)
                {
                    str[j] = str[j + toRemoveLen];
                }
            }
            
            stringLen = stringLen - toRemoveLen;

            // We will match next occurrence of word from current index.
            i--;
        }
    }
}