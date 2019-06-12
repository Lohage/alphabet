#include "functions.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*void getDataFromStdin(Words *w) {
  char buffer[SIZESTD];
  fputs("Enter words\n", stdout);
  fgets(buffer, SIZESTD - 1, stdin);
  format(buffer);

  w->word = (char **)malloc(sizeof(char *) * (w->qWords));
  if (!w->word) {
    printf("Allocation error\n");
    exit(1);
  }
  size_t q = 0;
  w->word[q] = strtok(buffer, " ");
  while (w->word[q] != NULL) {
    q++;
    if (q == w->qWords) {
      w->qWords += 10;
      w->word = (char **)realloc(w->word, sizeof(char *) * (w->qWords));
      if (!w->word) {
        printf("Allocation error\n");
        exit(1);
      }
    }
    w->word[q] = strtok(NULL, " ");
  }
  w->qWords = q;
}*/
void getDataFromFile(Words* w)
{
    // char buffer[SIZESTD];
    FILE* fp;
    fp = fopen("./bin/txt.txt", "r");
    if (fp == NULL) {
        printf("Error: can't open file\n");
        exit(2);
    }
    size_t q = 0;
    size_t bufCount = 0;
    w->word = (char**)malloc(sizeof(char*) * (w->qWords));

    while (1) {
        fgets(w->buffer[bufCount], SIZE, fp);
        if (feof(fp) != 0) {
            break;
        }
        format(w->buffer[bufCount]);

        if (!w->word) {
            printf("Allocation error\n");
            exit(1);
        }
        w->word[q] = strtok(w->buffer[bufCount], " ");
        while (w->word[q] != NULL) {
            q++;
            if (q >= w->qWords) {
                char** tmpPointer;
                tmpPointer = (char**)malloc(sizeof(char*) * (w->qWords + 10));
                if (!tmpPointer) {
                    printf("Allocation error\n");
                    exit(1);
                }
                for (size_t i = 0; i < q; i++) {
                    tmpPointer[i] = w->word[i];
                }
                w->qWords += 10;
                free(w->word);
                w->word = tmpPointer;
            }
            w->word[q] = strtok(NULL, " ");
        }
        bufCount++;
    }
    w->qWords = q;

    fclose(fp);
}
void sorting(Words* w)
{
    char* tmp;
    for (size_t i = 1; i < w->qWords; i++) {
        for (size_t j = 0; j < (w->qWords - i); j++) {
            int cmp = strcmp(w->word[j + 1], w->word[j]);
            if (cmp < 0) {
                tmp = w->word[j];
                w->word[j] = w->word[j + 1];
                w->word[j + 1] = tmp;
            }
        }
    }
}
void output(Words* w)
{
    printf("Words: \n");
    for (size_t i = 0; i < w->qWords; i++) {
        if (((i % 10) == 0) && (i != 0)) {
            printf("\n");
        }
        fputs(w->word[i], stdout);
        printf(" ");
    }
    printf("\n");

    free(w->word);
}
void format(char* buf)
{
    size_t len = strlen(buf);
    for (size_t i = 0; i < len; i++) {
        buf[i] = tolower(buf[i]);
    }
    char copy[len];
    size_t j = 0;
    for (size_t i = 0; i < len; i++) {
        if (((buf[i] >= 'a') && (buf[i] <= 'z')) || (buf[i] == ' ')) {
            copy[j] = buf[i];
            j++;
        }
    }
    copy[j] = '\0';
    strcpy(buf, copy);
}
