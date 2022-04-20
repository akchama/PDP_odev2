//
// Created by Abdullah Akçam on 17.04.2022.
//

#ifndef ODEV2_KISI_H
#define ODEV2_KISI_H

#include <stdlib.h>
#include "Yardimci.h"

struct PLAYER {
    char *name;
    double balance;
    double rate;
    int player_number;
    bool disqualified;
};

// Pointer kullanmak yerine bu şekilde tanımlama yapıyorum
typedef struct PLAYER *Player;

// Kurucu method
Player new_Player(char*, double, double, int);
Player player_from_string(char*);
void delete_Player(const Player this);

#endif //ODEV2_KISI_H
