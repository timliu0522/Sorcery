//
//  Ritual.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//
#include "Ritual.h"

Ritual::Ritual(int player) : Card(player) {}

void Ritual::notify(Subject<Card *, Effect> &whoFrom) {
    
}

