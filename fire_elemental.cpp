//
//  fire_elemental.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//
#include "fire_elemental.h"

Fire_Elemental::Fire_Elemental() {
    name = "Fire Elemental";
    description = "Whenever an opponent's minion enters play, deal 1 damage to it.";
    type = "Minion";
    cost = 2;
    attack = 2;
    defence = 2;
    action_number = 1;
    action_performed = 0;
    has_active = false;
    activated_cost = 0;
}
