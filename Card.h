//
// Created by Tim Liu on 2019-07-22.
//

#ifndef SORCERY_CARD_H
#define SORCERY_CARD_H


#include "Subject.h"
#include "Observer.h"
#include "State.h"
#include <string>

class Card : public Subject<Effect, Effect>, public Observer<Effect, Effect> {
protected:
    std::string name;
    std::string description;
    std::string type;
    int cost;
    
public:
    Card();
    virtual void notify(Subject<Effect, Effect> &whoFrom) override = 0;
};


#endif //SORCERY_CARD_H
