//
//  Card.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-26.
//  Copyright © 2019 An Zhang. All rights reserved.
//
#include "Card.h"

Card::Card(int player, bool can) : player{player}, has_target{can} {}

std::string Card::get_name() {
    return name;
}
std::string Card::get_description() {
    return description;
}
std::string Card::get_type() {
    return type;
}

bool Card::can_target() {
    return has_target;
}

int Card::get_player() {
    return player;
}

int Card::get_attack() {
    return attack;
}
int Card::get_defence() {
    return defence;
}
bool Card::has_activated() {
    return has_active;
}
bool Card::get_activated_cost() {
    return activated_cost;
}
bool Card::get_action_left() {
    return action_number - action_performed;
}

CollectionType Card::get_belong() {
    return belonging;
}

void Card::set_belong(CollectionType c) {
    belonging = c;
}

void Card::add_action() {
    action_performed += 1;
}

Effect Card::get_effect() {
    return effect;
}