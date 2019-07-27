//
// Created by Tim Liu on 2019-07-22.
//

#ifndef SORCERY_MINION_H
#define SORCERY_MINION_H


#include "Card.h"
#include "State.h"

class Minion : public Card {
protected:
    int attack = 0;
    int defence = 0;
    int action_number = 0;
    int action_performed = 0;
    bool has_active = 0;
    int activated_cost = 0;
    virtual int get_attack();
    virtual int get_defence();
    virtual bool has_activated();
    virtual bool get_activated_cost();
    virtual bool get_action_left();
    virtual bool check_death();
public:
    Minion();
    ~Minion();
    void notify(Subject<Card *, Effect> &whoFrom) override;
};


#endif //SORCERY_MINION_H
