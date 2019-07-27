//
//  potion_seller.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//
#include "potion_seller.h"

Potion_Seller::Potion_Seller(int player) : Minion(player) {
    name = "Potion Seller";
    description = "At the end of your turn, all your minions gain +0/+1";
    type = "Minion";
    cost = 2;
    attack = 1;
    defence = 3;
    action_number = 1;
    action_performed = 0;
    has_active = false;
    activated_cost = 0;
    effect = Effect(EffectType::EOT, get_player(), 1, CollectionType::BOARD, 0, 1);
}
