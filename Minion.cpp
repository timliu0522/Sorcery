//
// Created by Tim Liu on 2019-07-22.
//
#include "Minion.h"

Minion::Minion(int player) : Card(player) {
    name = "Minion";
}

void Minion::notify(Subject<Card *, Effect> &whoFrom) {
    
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