
//
//  standstill.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//
#include "standstill.h"
#include "State.h"

Standstill::Standstill () {
    name = "Standstill";
    description = "Whenever a minion enters play, destroy it";
    type = "Ritual";
    cost = 3;
    effect = EffectType::MEC;
    charge = 4;
    act_cost = 2;
}
