//
// Created by Abdullah Akçam on 17.04.2022.
//

#include "../include/Kisi.h"
#include "../include/Dosya.h"

enum player { Name, Balance, Rate, Number };

Player new_Player(char *name, double balance, double rate, int player_number) {
    // this isminde bir Player oluşturuyoruz
    Player this;
    this = (Player) malloc(sizeof (struct PLAYER));
    this->name = name;
    this->balance = balance;
    this->rate = rate;
    this->player_number = player_number;
    this->disqualified = false;

    this->delete = &delete_Player;
    return this;
}

Player player_from_string(char* player_string) {
    char *split[4];
    int i = 0;
    char *token = strtok(player_string, "#");
    while (token != NULL) {
        split[i++] = token;
        token = strtok(NULL, "#");
    }
    char *name = split[Name];
    double balance = strtod(split[Balance], NULL);
    double rate = strtod(split[Rate], NULL);
    int player_number = strtol(split[Number], NULL, 0);
    Player player;
    player = new_Player(name, balance, rate, player_number);
    return player;
}

void delete_Player(Player this) {
    if (this == NULL) return;
    free(this);
}