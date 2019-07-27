//
// Created by Tim Liu on 2019-07-22.
//
#include "Minion.h"

Minion::Minion(int player) : Card(player) {}

int Minion::get_attack() {
    return attack;
}
int Minion::get_defence() {
    return defence;
}
bool Minion::has_activated() {
    return has_active;
}
bool Minion::get_activated_cost() {
    return activated_cost;
}
bool Minion::get_action_left() {
    return action_number - action_performed;
}
bool Minion::check_death() {
    if (get_defence() == 0) {
        setState(Effect{EffectType::MLC, 0, 0, CollectionType::GRAVE, 0});
        notifyObservers();
        return true;
    }
    else
        return false;
}

void Minion::notify(Subject<Card *, Effect> &whoFrom) {
    
}
