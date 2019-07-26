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
    std::vector<Card *> ritual[2];
    int cur_player;

public:
    Board();
    ~Board();
    virtual void push_card(int player, Card *in) override;
    virtual void pop_card(Card *out) override;
    void notify_APNAP();
    virtual void notify(Subject<Effect> &whoFrom) override;
};

#endif /* Board_h */
