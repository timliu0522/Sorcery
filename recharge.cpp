//
//  recharge.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//
#include "recharge.h"

Recharge::Recharge() {
    name = "Recharge";
    description = "Your ritual gains 3 charges.";
    type = "Spell";
    cost = 1;
    need_target = false;
}
