//
// Created by Tim Liu on 2019-07-26.
//

#ifndef CODES_PLAYER_H
#define CODES_PLAYER_H

#include <stdio.h>
#include <string>



class Player {
    std::string name;
    int health;
    int magic;
protected:
    Player (std::string);
    int getHealth();
    int getMagic();
    void setHealth(int n);
    void setMagic(int n);
    bool check_death();
};


#endif //CODES_PLAYER_H
