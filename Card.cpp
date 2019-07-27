//
//  Card.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-26.
//  Copyright © 2019 An Zhang. All rights reserved.
//
#include "Card.h"

Card::Card(int player) {
    player = player;
}

std::string Card::get_name() {
    return name;
}
std::string Card::get_description() {
    return description;
}
std::string Card::get_type() {
    return type;
}
int Card::get_player() {
    return player;
}

