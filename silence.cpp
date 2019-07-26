//
//  silence.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//
#include "silence.h"

Silence::Silence (Minion* m) : Enchantment(m) {
    name  = "Silence";
    description = "Enchanted minion cannot use abilities";
    cost = 1;
}
