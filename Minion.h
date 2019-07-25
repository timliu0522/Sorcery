//
// Created by Tim Liu on 2019-07-22.
//

#ifndef SORCERY_MINION_H
#define SORCERY_MINION_H


#include "Card.h"
#include "State.h"

class Minion : public Card {
    int attack;
    int defence;
    int action_number;
    int action_performed;
    bool has_active;
    int activated_cost;
protected:
    virtual int get_attack();
    virtual int get_defence();
    virtual bool has_activated();
    virtual bool get_activated_cost();
    virtual bool get_action_left();
    virtual bool check_death();
    virtual ~Minion() = 0;
};


#endif //SORCERY_MINION_H
