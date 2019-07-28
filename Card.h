//
// Created by Tim Liu on 2019-07-22.
//

#ifndef SORCERY_CARD_H
#define SORCERY_CARD_H


#include "Subject.h"
#include "Observer.h"
#include "State.h"
#include <string>

class Card : public Subject<Card *, Effect>, public Observer<Card *, Effect> {
protected:
    std::string name;
    std::string description;
    std::string type;
    int cost;
    int player;
    bool has_target;
    Effect effect;

public:
    Card(int player, bool);
    std::string get_name();
    std::string get_description();
    std::string get_type();
    int get_player();
    bool can_target();
    virtual void notify(Subject<Card *, Effect> &whoFrom) override = 0;
};


#endif //SORCERY_CARD_H
