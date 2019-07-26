//
// Created by Tim Liu on 2019-07-22.
//

#ifndef SORCERY_CARD_H
#define SORCERY_CARD_H


#include "Subject.h"
#include "Observer.h"
#include "State.h"
#include <string>

class Card : public Subject<Effect>, public Observer<Effect> {
protected:
    std::string name;
    std::string description;
    std::string type;
    int cost;
    int player;

public:
    Card();
    std::string get_name() {
        return name;
    }
    std::string get_description() {
        return description;
    }
    std::string get_type() {
        return type;
    }
    virtual void notify(Subject<Effect> &whoFrom) override = 0;
};


#endif //SORCERY_CARD_H
