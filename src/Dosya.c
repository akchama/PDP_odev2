//
// Created by Abdullah Akçam on 17.04.2022.
//

#include "../include/Dosya.h"

char **read_file(const char *filename, int *p_count) {
    FILE *file = fopen(filename, "r");
    int count = 0; // Count num lines in the file
    char buffer[256];

    while (fgets(buffer, sizeof buffer, file)) {
        count++;
    }

    char **myArray = malloc(count * sizeof(char *));
    if (myArray == NULL) {
        fclose(file);
        return NULL;
    }

    rewind(file);

    int ctr = 0;

    while (ctr < count && fgets(buffer, sizeof buffer, file)) {
        myArray[ctr++] = strdup(buffer);
    }
    fclose(file);
    *p_count = count;
    return myArray;
}