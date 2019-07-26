//
// Created by An Zhang on 2019-07-25.
//

#ifndef SORCERY_RITUAL_H
#define SORCERY_RITUAL_H
#include "Card.h"
#include "State.h"

class Ritual : public Card {
protected:
    EffectType effect;
    int charge;
    int act_cost;
    
public:
    void ability();
    virtual Effect getInfo() const override;
    void notify(Subject<Effect, Effect> &whoFrom) override;
};

#endif //SORCERY_RITUAL_H
