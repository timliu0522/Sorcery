//
//  dark_ritual.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//
#include "dark_ritual.h"

Dark_Ritual::Dark_Ritual (int player) : Ritual(player) {
    name = "Dark Ritual";
    description = "At the start of your turn, gain 1 magic";
    type = "Ritual";
    cost = 0;
    defence = 5;
    activated_cost = 1;
    effect = Effect(EffectType::BUF, player, 0, CollectionType::HAND);
}

void Dark_Ritual::start_turn() {
    if (get_defence() >= activated_cost) {
        add_damage(activated_cost);
        setInfo(shared_from_this());
        setState(effect);
        notifyObservers();
    }
}
