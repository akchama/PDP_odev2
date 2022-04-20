//
// Created by Abdullah Akçam on 17.04.2022.
//

#include "../include/Oyun.h"

Game new_game(const int *lucky_numbers, size_t size) {
    Game this;
    this = (Game) malloc(sizeof (struct GAME));
    this->lucky_numbers = malloc(size); // dinamik olarak diziyi oluşturuyor
    memcpy(this->lucky_numbers, lucky_numbers, size);

    // bu değerleri dışarıdan almamıza gerek yok yeni bir örnek oluştururken
    // başlangıç değerlerini atayabiliriz
    this->round = 0;
    this->game_balance = 0;
    this->game_over = false;
    return this;
}

bool play_round(Game game, Player players[], size_t length) {
    double transaction_amount;
    int players_left = 0;

    // En zengin kişinin listenin ilk kişisi olduğunu varsay
    Player richest_player = players[0];

    for (int i = 0; i < length; i ++) {

        if (players[i]->disqualified == true) {
            continue;
        }
        else {
            players_left ++;
        }

        // Eğer oyuncu şanslı numarayı tutturursa
        if (game->lucky_numbers[game->round] == players[i]->player_number) {
            transaction_amount = players[i]->balance * players[i]->rate * 9.f;
            game->game_balance -= transaction_amount;
            players[i]->balance += transaction_amount;
        }
        else {
            transaction_amount = players[i]->balance * players[i]->rate;
            game->game_balance += transaction_amount;
            players[i]->balance -= transaction_amount;

            if (players[i]->balance < 1000) {
                players[i]->disqualified = true;
            }
        }

        if (players[i]->balance > richest_player->balance) {
            richest_player = players[i];
        }
    }

    int lucky_number = game->lucky_numbers[game->round];

    if (players_left < 1 || richest_player->balance < 1000) {
        game->game_over = true;
    }

    yazdir(
            lucky_number,
            &(game->round),
            &(game->game_balance),
            (richest_player->name),
            (double) richest_player->balance,
            game->game_over);

    game->round ++;

    if (game->game_over) return false;
    return true;
}

void delete_game(Game this) {
    if (this != NULL) {
        free(this);
    }
}