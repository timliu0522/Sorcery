//
// Created by Tim Liu on 2019-07-22.
//

#ifndef SORCERY_CARD_H
#define SORCERY_CARD_H


#include "Subject.h"
#include "State.h"
#include <string>

class Card : public Subject<Effect, Effect>, public Observer<Effect, Effect> {
protected:
    std::string name;
    std::string description;
    std::string type;
    int cost;
};


#endif //SORCERY_CARD_H
