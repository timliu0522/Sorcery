//
//  magic_fatigue.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//
#include "magic_fatigue.h"

Magic_Fatigue::Magic_Fatigue (Minion* m) : Enchantment(m) {
    name  = "Magic Fatigue";
    description = "Enchanted minion's activated ability costs 2 more";
    cost = 0;
}
