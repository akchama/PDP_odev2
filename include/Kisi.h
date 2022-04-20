//
// Created by Abdullah Akçam on 17.04.2022.
//

#ifndef ODEV2_KISI_H
#define ODEV2_KISI_H

#include <stdlib.h>
#include "Dosya.h"

// not: player_from_string fonksiyonu new_Player fonksiyonu tarafından çağrıldığı için
// fonksiyonları struct içerisine bağlayamıyorum
struct PLAYER {
    char *name;
    double balance;
    double rate;
    int player_number;
    bool disqualified;

    void (*delete)(struct PLAYER* player);
};

// Pointer kullanmak yerine bu şekilde tanımlama yapıyorum
typedef struct PLAYER *Player;

// Kurucu method
Player new_Player(char*, double, double, int);
Player player_from_string(char*);
void delete_Player(Player this);

#endif //ODEV2_KISI_H
