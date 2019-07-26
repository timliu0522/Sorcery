//
//  enrage.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//
#include "enrage.h"

Enrage::Enrage (Minion* m) : Enchantment(m) { // *2 *2 enchantment
    name  = "Enrage";
    description = "";
    cost = 2;
}

