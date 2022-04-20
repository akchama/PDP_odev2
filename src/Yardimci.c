//
// Created by AA on 17.04.2022.
//

#include <stdio.h>
#include <stdlib.h>
#include "../include/Yardimci.h"

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
