//
//  dark_ritual.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//
#include "dark_ritual.h"
#include "State.h"

Dark_Ritual::Dark_Ritual (int player) : Ritual(player) {
    name = "Dark Ritual";
    description = "At the start of your turn, gain 1 magic";
    type = "Ritual";
    cost = 0;
    charge = 5;
    act_cost = 1;
    effect = Effect(EffectType::SOT, get_player(), 0, CollectionType::HAND);
}
