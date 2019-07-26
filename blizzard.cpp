//
//  blizzard.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//
#include "blizzard.h"

Blizzard::Blizzard() {
    name = "Blizzard";
    description = "Deal 2 damage to all minions";
    type = "Spell";
    cost = 3;
    need_target = false;
}
