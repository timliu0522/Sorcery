//
// Created by Tim Liu on 2019-07-22.
//

#ifndef SORCERY_MINION_H
#define SORCERY_MINION_H


#include "Card.h"
#include "State.h"

class Minion : public Card {
    virtual bool check_death();
public:
    Minion(int player);
    ~Minion();
    virtual void notify(Subject<Card *, Effect> &whoFrom) override;
};


#endif //SORCERY_MINION_H
