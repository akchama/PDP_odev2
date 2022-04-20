//
// Created by AA on 17.04.2022.
//

#ifndef ODEV2_YARDIMCI_H
#define ODEV2_YARDIMCI_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef enum { false, true } bool;

void yazdir(
        int sansli_sayi,
        const int *tur,
        const double *masa_bakiye,
        char en_zengin_kisi[],
        double en_zengin_kisi_bakiye,
        bool is_game_over);

#endif //ODEV2_YARDIMCI_H
