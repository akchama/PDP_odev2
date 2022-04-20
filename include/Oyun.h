//
// Created by Abdullah Akçam on 17.04.2022.
//

#ifndef ODEV2_OYUN_H
#define ODEV2_OYUN_H

#include <malloc.h>
#include "Kisi.h"
#include "Yardimci.h"

struct GAME {
    int round;
    double game_balance;
    int *lucky_numbers;
    bool game_over;
};

typedef struct GAME *Game;

Game new_game(const int *lucky_numbers, size_t size);
bool play_round(Game game, Player player[], size_t length);
void delete_game(Game this);

#endif //ODEV2_OYUN_H
