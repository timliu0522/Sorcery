    //
//  Grave.h
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//

#ifndef SORCERY_GRAVE_H
#define SORCERY_GRAVE_H
#include"Collection.h"

class Graveyard : public Collection {
    
public:
    Graveyard();
    ~Graveyard();
    void push_card(int player, Card *in) override;
    void pop_card(Card *out) override;
};

#endif /* Grave_h */
