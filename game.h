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
#include "Player.h"
#include <memory>



class Game {
    std::shared_ptr<Player> player1;
    std::shared_ptr<Player> player2;
    int CurrPlayer; // current player
    int OtherPlayer;
    std::shared_ptr<Deck> deck;
    std::shared_ptr<Board> board;
    std::shared_ptr<Hand> hand;
    std::shared_ptr<Graveyard> grave;
    bool game_end;
    bool game_begin;
public:
    void prettyprint();
    void move (std::shared_ptr<Collection> source, std::shared_ptr<Collection> dest, Card * the_card);
    int getCurrPlayer();
    int getOtherPlayer();
    std::shared_ptr<Player> getPlayer1();
    std::shared_ptr<Player> getPlayer2();
    void setDeck(std::string filename, int player);
};


#endif //CODES_GAME_H
