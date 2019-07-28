    //
// Created by Tim Liu on 2019-07-26.
//

#include "game.h"
#include "ascii_graphics.h"
#include <vector>

using namespace std;

Game::Game(string p1, string p2) {
    plyrs[0] = make_shared<Player>(p1);
    plyrs[1] = make_shared<Player>(p2);
    CurrPlayer = 0;
    OtherPlayer = 1;
    game_end = false;
    game_begin = false;
}

void Game::init_deck(int player, std::string filename) {
    deck->load_deck(filename, player);
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
    return this->plyrs[0];
}

shared_ptr<Player> Game::getPlayer2() {
    return this->plyrs[1];
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
void Game::PlayCard(int index_1, int player, int index_2){}
void Game::checkAbility(int index_1){}
void Game::UseCard(int index_1, int player, int index_2){}
void Game::InspectMinion(int index_1){}
void Game::ShowHand(){}

std::string Game::getWinner() {
    if (plyrs[0]->getHealth() <= 0) {
        return plyrs[1]->getName();
    } else if (plyrs[1]->getHealth() <= 0) {
        return plyrs[0]->getName();
    } else {
        return "None";
    }
}