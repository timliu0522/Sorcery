//
//  Hand.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-26.
//  Copyright © 2019 An Zhang. All rights reserved.
//

#include "Hand.h"

Hand::~Hand() {
    for (int i = 0; i < 2; i++) {
        while (!cardlist[i].empty()) {
            // delete cardlist[i].back();
            cardlist[i].pop_back();
        }
    }
}

void Hand::push_card(int player, std::shared_ptr<Card> in) {
    in->set_belong(CollectionType::HAND);
    cardlist[player].emplace_back(in);
}

void Hand::pop_card(int player, std::shared_ptr<Card> out) {
    for (auto it = cardlist[player].begin(); it != cardlist[player].end(); it ++) {
        if (*it != out) continue;
        cardlist[player].erase(it);
        return;
    }
}

void Hand::pop_selected(int player, int idx, int tar, int idx2) {
    if (cardlist[player].size() < idx) {
        throw 7;
    }
    setInfo(cardlist[player][idx]);
    setState(Effect(EffectType::MOV, player, tar, CollectionType::BOARD, idx2, 0, 2));
    notifyObservers();
    cardlist[player].erase(cardlist[player].begin() + (idx - 1));
}

void Hand::notify(Subject<std::shared_ptr<Card>, Effect> &whoFrom) {
    if (whoFrom.getState().notified_type != 2) return;
    if (whoFrom.getState().type == EffectType::MOV && whoFrom.getState().destination == CollectionType::HAND) {
        push_card(whoFrom.getInfo()->get_player(), whoFrom.getInfo());
    }
}
