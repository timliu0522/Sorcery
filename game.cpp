    //
// Created by Tim Liu on 2019-07-26.
//

#include "game.h"
#include "ascii_graphics.h"
#include <vector>

using namespace std;

Game::Game(shared_ptr<Player> p1, shared_ptr<Player> p2, shared_ptr<Deck> d, shared_ptr<Board> b, shared_ptr<Hand> h,
        shared_ptr<Graveyard> g) : player1{p1}, player2{p2}, deck{d}, board{b}, hand{h}, grave{g} {
    CurrPlayer = 1;
    OtherPlayer = 2;
    game_end =false;
    game_begin = false;
}

int Game::getCurrPlayer() {
    return CurrPlayer;
}

int Game::getOtherPlayer() {
    return OtherPlayer;
}

void Game::Gamepush(std::shared_ptr<Collection> where, int who, Card *c) {
    where->push_card(who, c);
}

void Game::Gamepop(std::shared_ptr<Collection> where, int who, Card *c) {
    where->pop_card(who, c);
}
void Game::move(std::shared_ptr<Collection> source, std::shared_ptr<Collection> dest, Card *the_card) {
    source->pop_card(this->getCurrPlayer(), the_card);
    dest->push_card(this->getCurrPlayer(), the_card);
}



shared_ptr<Player> Game::getPlayer1() {
    return this->player1;
}

shared_ptr<Player> Game::getPlayer2() {
    return this->player2;
}

void Game::setDeck(string filename, int player) {
    this->deck->load_deck(filename, player);
}

bool Game::getEnd() {
    return game_end;
}

bool Game::getBegin() {
    return game_begin;
}

void Game::prettyprint() {
        // wait for implementation
}

void Game::endTurn(){
    // implementation
}
void Game::MinionattackPlayer(int index_1) {}
void Game::MinionattackMinion(int index_1, int index_2){}
void Game::PlayCard(int theplayer, int index_1, int index_2){}
void Game::checkAbility(int index_1){}
void Game::UseCard(int theplayer, int index_1, int index_2){}
void Game::InspectMinion(int index_1){}
void Game::ShowHand(){}