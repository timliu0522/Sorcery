//
// Created by Tim Liu on 2019-07-22.
//

#ifndef SORCERY_COLLECTION_H
#define SORCERY_COLLECTION_H


#include "Card.h"
#include "Subject.h"
#include "Observer.h"
#include "State.h"
#include <vector>

class Collection : public Subject<Effect, Effect>, public Observer<Effect, Effect> {
protected:
    std::vector<Card *> cardlist[2];
public:
    virtual void push_card(int player, Card *in);
    virtual Card* pop_card(int player, Card *out) = 0;
};


#endif //SORCERY_COLLECTION_H
