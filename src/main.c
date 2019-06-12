#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Words* w = (Words*)malloc(sizeof(*w));
    if (!w) {
        printf("Allocation error\n");
        exit(1);
    }

    w->qWords = 10;
    getDataFromFile(w);

    sorting(w);
    output(w);
    free(w);

    return 0;
}
