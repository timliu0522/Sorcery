//
//  Hand.h
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//

#ifndef SORCERY_HAND_H
#define SORCERY_HAND_H
#include "Collection.h"

class Hand : public Collection {
    
public:
    Hand();
    ~Hand();
    void push_card(int player, Card *in) override;
    void pop_card(Card *out) override;
};


#endif /* Hand_h */
