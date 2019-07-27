//
//  Grave.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-26.
//  Copyright © 2019 An Zhang. All rights reserved.
//
#include "Grave.h"

Graveyard::Graveyard () {
}

void Graveyard::push_card(int player, Card *in) {
    cardlist[player - 1].emplace_back(in);
}

void Graveyard::pop_card(Card* out) {
}
