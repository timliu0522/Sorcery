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
    Game(std::shared_ptr<Player> p1, std::shared_ptr<Player> p2, std::shared_ptr<Deck> d, std::shared_ptr<Board> b,
            std::shared_ptr<Hand> h, std::shared_ptr<Graveyard> g); // wait for discussion, use game to add or use main
    void prettyprint();
    void move (std::shared_ptr<Collection> source, std::shared_ptr<Collection> dest, Card * the_card);
    int getCurrPlayer();
    int getOtherPlayer();
    std::shared_ptr<Player> getPlayer1();
    std::shared_ptr<Player> getPlayer2();
    void setDeck(std::string filename, int player);
    bool getEnd();
    bool getBegin();
    void Gamepush(std::shared_ptr<Collection> where, int who, Card* c);
    void Gamepop(std::shared_ptr<Collection> where, int who, Card* c);
    void endTurn();
    void MinionattackPlayer(int index_1);
    void MinionattackMinion(int index_1, int index_2);
    void PlayCard(int theplayer, int index_1, int index_2);
    void checkAbility(int index_1);
    void UseCard(int theplayer, int index_1, int index_2);
    void InspectMinion(int index_1);
    void ShowHand();
};


#endif //CODES_GAME_H
