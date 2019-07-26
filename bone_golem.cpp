//
//  bone_golem.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//
#include "bone_golem.h"

Bone_Golem::Bone_Golem() {
    name = "Bone Golem";
    description = "Gain +1/+1 whenever a minion leaves play.";
    type = "Minion";
    cost = 2;
    attack = 1;
    defence = 3;
    action_number = 1;
    action_performed = 0;
    has_active = false;
    activated_cost = 0;
}
