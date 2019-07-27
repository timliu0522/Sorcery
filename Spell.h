//
// Created by An Zhang on 2019-07-25.
//

#ifndef SORCERY_SPELL_H
#define SORCERY_SPELL_H
#include "Card.h"

class Spell : public Card {
protected:
    bool need_target;
    
public:
    Spell(int player);
    void notify(Subject<Card*, Effect> &whoFrom) override;
};
#endif //SORCERY_SPELL_H
