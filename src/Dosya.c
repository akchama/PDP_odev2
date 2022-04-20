//
// Created by Abdullah Akçam on 17.04.2022.
//

#include "../include/Dosya.h"

File new_content(const char *filename, int *p_count) {
    File this;
    this = malloc(sizeof (struct FILE*));
    char **content = read_file(this, filename, p_count);

    // fonksiyon bağlantıları
    this->content = malloc(sizeof (char *) * *p_count);
    this->content = content;
    this->read_file = &read_file;
    this->delete = &delete_file;
    return this;
}

char **read_file(struct FILE* f, const char *filename, int *p_count) {
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

void yazdir(
        int sansli_sayi,
        const int *tur,
        const double *masa_bakiye,
        char en_zengin_kisi[],
        double en_zengin_kisi_bakiye,
        bool is_game_over) {

    if (!is_game_over) {
        system("cls");
        printf("\n\n");
        printf("                              #############################################\n");
        printf("                              ##             SANSLI SAYI: %-6d         ##\n", sansli_sayi);
        printf("                              #############################################\n");
        printf("                              #############################################\n");
        printf("                              ##             TUR: %-6d                 ##\n", *tur + 1);
        printf("                              ##     MASA BAKIYE: %-12.2f           ##\n", *masa_bakiye);
        printf("                              ##                                         ##\n");
        printf("                              ##-----------------------------------------##\n");
        printf("                              ##             EN ZENGIN KISI:             ##\n");
        printf("                              ##             %-16s            ##\n", en_zengin_kisi);
        printf("                              ##     BAKIYESI: %-12.2f              ##\n", en_zengin_kisi_bakiye);
        printf("                              ##                                         ##\n");
        printf("                              #############################################\n");
    }
    else {
        system("cls");
        printf("\n\n");
        printf("                              #############################################\n");
        printf("                              ##             TUR: %-6d                 ##\n", *tur + 1);
        printf("                              ##     MASA BAKIYE: %-12.2f           ##\n", *masa_bakiye);
        printf("                              ##                                         ##\n");
        printf("                              ##-----------------------------------------##\n");
        printf("                              ##             OYUN BITTI                  ##\n");
        printf("                              ##                                         ##\n");
        printf("                              ##                                         ##\n");
        printf("                              ##                                         ##\n");
        printf("                              #############################################\n");
        system("pause");
    }
}

void delete_file(File file) {
    if (file != NULL)
        free(file);
}