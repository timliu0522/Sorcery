//
//  banish.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//
#include "banish.h"

Banish::Banish(int player) : Spell(player) {
    name = "Banish";
    description = "Destroy target minion or ritual";
    type = "Spell";
    cost = 2;
    need_target = true;
    effect = Effect(EffectType::MOV, get_player(), 0, CollectionType::BOARD);
}

