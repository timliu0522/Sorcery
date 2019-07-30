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

int Card::get_cost() {
    return cost;
}

bool Card::can_target() {
    return has_target;
}

int Card::get_player() {
    return player;
}

int Card::get_attack() {
    int ans = attack;
    for (auto i : enc) {
        if (i->get_attack() > 0) {
            ans += i->get_attack();
        } else if (i->get_attack() < 0) {
            ans = ans * (- i->get_attack());
        }
    }
    return ans;
}
int Card::get_defence() {
    int ans = defence;
    for (auto i : enc) {
        if (i->get_defence() > 0) {
            ans += i->get_defence();
        } else if (i->get_defence() < 0) {
            ans = ans * (- i->get_defence());
        }
    }
    return ans;
}
bool Card::has_activated() {
    bool ans = has_active;
    for (auto i : enc) {
        ans = ans && i->has_ability();
    }
    return ans;
}

bool Card::has_activated_r() {
    return has_active;
}

bool Card::get_activated_cost() {
    int ans = activated_cost;
    for (auto i : enc) {
        ans += i->get_activated_cost();
    }
    return ans;
}

bool Card::has_ability() {
    bool ans = can_use;
    for (auto i : enc) {
        ans = ans && i->has_ability();
    }
    return ans;
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

void Card::set_reborn() {
    defence = 1;
}

void Card::add_action() {
    action_performed += 1;
}

void Card::add_damage(int a) {
    dmg_taken += a;
}

Effect Card::get_effect() {
    return effect;
}

void Card::reset() {
    // dmg_taken = 0;
    action_performed = 0;
    action_number = 0;
    enc.clear();
}

void Card::start_turn() {}

void Card::take_buf(Subject<std::shared_ptr<Card>, Effect> &whoFrom) {
    // target:: 0 - targeted, 1 - all friendly, 2 - all enemy, 3 - all, 4 - ritual, 5 - player
    if (type == "Ritual" && whoFrom.getState().target != 4) return;
    if (type == "Minion" && whoFrom.getState().target >= 4) return;
    bool buf = (whoFrom.getState().target == 0 && shared_from_this() == whoFrom.getInfo());
    buf |= (whoFrom.getState().player == player && whoFrom.getState().target == 1);

    if (buf) {
        attack += whoFrom.getState().value1;
        defence += whoFrom.getState().value2;
    }
}

void Card::take_dmg(Subject<std::shared_ptr<Card>, Effect> &whoFrom) {
    // target:: 0 - targeted, 1 - all friendly, 2 - all enemy, 3 - all

    bool dmg = false;
    dmg |= whoFrom.getState().target == 3;
    dmg |= (whoFrom.getState().target == 2 && whoFrom.getState().player == 1 - player);
    dmg |= (whoFrom.getState().target == 0 && shared_from_this() == whoFrom.getInfo());
    if (dmg) {
        add_damage(whoFrom.getState().value1);
        if (get_defence() <= 0) {
            setInfo(shared_from_this());
            setState(Effect{EffectType::MLC, player, 0, CollectionType::GRAVE, 0, 0, 2});
            reset();
            notifyObservers();
        }
    }
}

void Card::mlb(Subject<std::shared_ptr<Card>, Effect> &whoFrom) {}
void Card::meb(Subject<std::shared_ptr<Card>, Effect> &whoFrom) {}
void Card::dec() {
    if (enc.size() > 0) {
        enc.pop_back();
    }
    if (get_defence() <= 0) {
        setInfo(shared_from_this());
        setState(Effect{EffectType::MLC, player, 0, CollectionType::GRAVE, 0, 0, 2});
        reset();
        notifyObservers();
    }
}
void Card::end_turn() {}

void Card::notify(Subject<std::shared_ptr<Card>, Effect> &whoFrom) {
    if (get_belong() != CollectionType::BOARD) return;
    if (type == "Minion" && whoFrom.getState().notified_type != 0) return;
    if (type == "Ritual" && whoFrom.getState().notified_type != 1) return;
    if (whoFrom.getState().type == EffectType::SOT) {
        start_turn();
    } else if (whoFrom.getState().type == EffectType::EOT) {
        end_turn();
    } else if (whoFrom.getState().type == EffectType::MEC) {
        meb(whoFrom);
    } else if (whoFrom.getState().type == EffectType::MLC) {
        mlb(whoFrom);
    } else if (whoFrom.getState().type == EffectType::DMG) {
        take_dmg(whoFrom);
    } else if (whoFrom.getState().type == EffectType::BUF) {
        take_buf(whoFrom);
    } else if (whoFrom.getState().type == EffectType::DEC) {
        dec();
    } else if (whoFrom.getState().type == EffectType::SUM) {

    }
}

void Card::add_enc(std::shared_ptr<Card> c) {
    enc.push_back(c);
}
