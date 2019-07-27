//
// Created by Tim Liu on 2019-07-26.
//

#ifndef CODES_GAME_H
#define CODES_GAME_H

#include "Collection.h"
#include "Deck.h"
#include "Grave.h"
#include "Board.h"
#include "Hand.h"
#include "Card.h"


class Game {
    // player1
    // player2
    int now; // current player
    std::shared_ptr<Deck> deck;
    std::shared_ptr<Board> board;
    // std::shared_ptr<Hand> hand;
    // std::shared+ptr<Grave> grave;
    bool game_end;
    bool game_begin;
public:
    void prettyprint();
    void move (std::shared_ptr<Collection> source, std::shared_ptr<Collection> dest, int card);
    // getplayer1;
    // getplayer2;
    // getCurrplayer;
    // getOtherpalyer;
    //
};


#endif //CODES_GAME_H
