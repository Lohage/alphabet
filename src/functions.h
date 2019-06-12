#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stddef.h>

#define SIZE 255

typedef struct Words {
    char** word;
    char buffer[50][SIZE];
    size_t qWords;
} Words;

void getDataFromStdin(Words* w);
void getDataFromFile(Words* w);
void output(Words* w);
void sorting(Words* w);

void format(char* buf);

#endif
