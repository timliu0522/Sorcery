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

Graveyard::~Graveyard() {
    for (int i = 0; i < 2; i++) {
        while (!cardlist[i].empty()) {
            // delete cardlist[i].back();
            cardlist[i].pop_back();
        }
    }
}

void Graveyard::push_card(int player, std::shared_ptr<Card> in) {
    cardlist[player].emplace_back(in);
}

void Graveyard::pop_card(int player, std::shared_ptr<Card> out) {
    for (auto it = cardlist[player].begin(); it != cardlist[player].end(); it ++) {
        if (*it != out) continue;
        cardlist[player].erase(it);
        return;
    }
}

void Graveyard::notify(Subject<std::shared_ptr<Card>, Effect> &whoFrom) {
    if (whoFrom.getState().notified_type != 2) return;
    if (whoFrom.getState().type == EffectType::MLC && whoFrom.getState().destination == CollectionType::GRAVE) {
        push_card(whoFrom.getInfo()->get_player(), whoFrom.getInfo());
    }

}