//
// Created by Abdullah Akçam on 17.04.2022.
//

#include <stdlib.h>
#include "../include/Dosya.h"
#include "../include/Kisi.h"
#include "../include/Oyun.h"

#define SLEEP_DURATION 10

int main() {
    int numbers_line_count = 0,
        players_line_count = 0;

    File numbers_text = new_content("Sayilar.txt", &numbers_line_count);
    File players_text = new_content("Kisiler.txt", &players_line_count);

    Player players[players_line_count];
    int lucky_numbers[numbers_line_count];

    for (int i = 0; i < numbers_line_count; i ++) {
        int num = (int) strtol(numbers_text->content[i], NULL, 0);
        lucky_numbers[i] = num;
    }

    for (int i = 0; i < players_line_count; i ++) {
        players[i] = player_from_string(players_text->content[i]);
    }

    // yeni oyun oluşturur
    Game game = new_game(lucky_numbers, sizeof(lucky_numbers));

    for (size_t i = 0; i < numbers_line_count; i ++) {
        if (game->play_round(game, players, players_line_count)) {
        }
        else {
            break;
        }
        usleep(1000 * SLEEP_DURATION); // mikrosaniye cinsinden duraklama
    }

    // bellek iadesi
    numbers_text->delete(numbers_text);
    players_text->delete(players_text);


    for (int p = 0; p < players_line_count; p ++) {
        players[p]->delete(players[p]);
    }
    game->delete(game);
    return 0;
}