//
// Created by Abdullah Akçam on 17.04.2022.
//

#ifndef ODEV2_DOSYA_H
#define ODEV2_DOSYA_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef enum { false, true } bool;

struct FILE {
    // yazıların okunduktan sonra saklandığı dinamik dizi
    char **content;

    // struct fonksiyonları
    char **(*read_file)(struct FILE* file, const char *filename, int *p_count);
    void (*delete)(struct FILE* file);
    void (*yazdir)(
            int sansli_sayi,
            const int *tur,
            const double *masa_bakiye,
            char en_zengin_kisi[],
            double en_zengin_kisi_bakiye,
            bool is_game_over);
};

typedef struct FILE* File;

File new_content(const char *filename, int *p_count);
char **read_file(struct FILE* file, const char *filename, int *p_count);
void delete_file(File file);


void yazdir(
        int sansli_sayi,
        const int *tur,
        const double *masa_bakiye,
        char en_zengin_kisi[],
        double en_zengin_kisi_bakiye,
        bool is_game_over);

#endif //ODEV2_DOSYA_H
