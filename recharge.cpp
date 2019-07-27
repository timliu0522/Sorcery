//
//  recharge.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//
#include "recharge.h"

Recharge::Recharge(int player) : Spell(player) {
    name = "Recharge";
    description = "Your ritual gains 3 charges.";
    type = "Spell";
    cost = 1;
    need_target = false;
    effect = Effect(EffectType::BUF, get_player(), 0, CollectionType::BOARD, 3);
}
