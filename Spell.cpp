//
//  Spell.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//
#include "Spell.h"

Spell::Spell(int player) : Card(player) {}

void Spell::notify(Subject<Card*, Effect> &whoFrom) {
    
}
