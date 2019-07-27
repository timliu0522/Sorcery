//
// Created by An Zhang on 2019-07-25.
//

#ifndef SORCERY_RITUAL_H
#define SORCERY_RITUAL_H
#include "Card.h"
#include "State.h"

class Ritual : public Card {
protected:
    int charge;
    int act_cost;
    
public:
    Ritual(int player);
    void ability();
    void notify(Subject<Card *, Effect> &whoFrom) override;
};

#endif //SORCERY_RITUAL_H
