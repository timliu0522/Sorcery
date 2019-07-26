//
//  Board.h
//  Sorcery
//
//  Created by An Zhang on 2019-07-25.
//  Copyright © 2019 An Zhang. All rights reserved.
//

#ifndef SORCERY_BOARD_H
#define SORCERY_BOARD_H

#include "Collection.h"

class Board : public Collection {
public:
    Board();
    ~Board();
    virtual void push_card(int player, Card *in) override;
    virtual Card* pop_card(int player, Card *out) override;
};

#endif /* Board_h */
