//
// Created by Abdullah Akçam on 17.04.2022.
//

#include <stdlib.h>
#include "../include/Yardimci.h"
#include "../include/Dosya.h"
#include "../include/Kisi.h"
#include "../include/Oyun.h"

#define SLEEP_DURATION 10

int main() {
    int sayilar_satir_sayisi = 0,
        kisiler_satir_sayisi = 0;
    char** sayilar_text = read_file("Sayilar.txt", &sayilar_satir_sayisi);
    char** kisiler_text = read_file("Kisiler.txt", &kisiler_satir_sayisi);

    Player players[kisiler_satir_sayisi];
    int lucky_numbers[sayilar_satir_sayisi];

    for (int i = 0; i < sayilar_satir_sayisi; i ++) {
        int num = (int) strtol(sayilar_text[i], NULL, 0);
        lucky_numbers[i] = num;
    }

    for (int i = 0; i < kisiler_satir_sayisi; i ++) {
        players[i] = player_from_string(kisiler_text[i]);
    }

    printf("Numbers length: %d\n", sayilar_satir_sayisi);
    printf("Players length: %d\n", kisiler_satir_sayisi);

    Game game = new_game(lucky_numbers, sizeof(lucky_numbers));

    for (size_t i = 0; i < sayilar_satir_sayisi; i ++) {
        if (play_round(game, players, kisiler_satir_sayisi)) {
        }
        else {
            break;
        }
        usleep(1000 * SLEEP_DURATION); //pass in microseconds
    }
    return 0;
}