//
//  Enchantment.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//
#include "Enchantment.h"

Enchantment::Enchantment (Minion* m) : Minion(m->get_player()) {
    previous = m;
}

Enchantment::~Enchantment() {
    delete previous;
}
