    //
// Created by Tim Liu on 2019-07-26.
//

#include "game.h"
#include "ascii_graphics.h"
#include <vector>

using namespace std;

int Game::getCurrPlayer() {
    return CurrPlayer;
}

int Game::getOtherPlayer() {
    return OtherPlayer;
}

void Game::move(std::shared_ptr<Collection> source, std::shared_ptr<Collection> dest, Card *the_card) {
    source->pop_card(this->getCurrPlayer(), the_card);
    dest->push_card(this->getCurrPlayer(), the_card);
}

void Game::prettyprint() {
    // wait for implementation
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
