    //
// Created by Tim Liu on 2019-07-26.
//

#include "game.h"
#include "ascii_graphics.h"
#include <vector>

using namespace std;

Game::Game(string p1, string p2) {
    players[0] = make_shared<Player>(p1, 0);
    players[1] = make_shared<Player>(p2, 1);
    CurrPlayer = 0;
    OtherPlayer = 1;
    game_end = false;
    game_begin = false;

    hand->attach(board);
    board->attach(hand);
    board->attach(players[0]);
    board->attach(players[1]);
    board->attach(grave);
    grave->attach(board);

    this->attach(board);
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

void Game::Gamepush(std::shared_ptr<Collection> where, int who, std::shared_ptr<Card> c) {
    where->push_card(who, c);
}

void Game::Gamepop(std::shared_ptr<Collection> where, int who, std::shared_ptr<Card> c) {
    where->pop_card(who, c);
}

void Game::move(std::shared_ptr<Collection> source, std::shared_ptr<Collection> dest, std::shared_ptr<Card> the_card) {
    source->pop_card(this->getCurrPlayer(), the_card);
    dest->push_card(this->getCurrPlayer(), the_card);
}

shared_ptr<Player> Game::getPlayer1() {
    return this->players[0];
}

shared_ptr<Player> Game::getPlayer2() {
    return this->players[1];
}

void Game::setDeck(string filename, int player) {
    this->deck->load_deck(filename, player);
}

void Game::draw() {
    if (hand->get_size(CurrPlayer) < 5 && deck->get_size(CurrPlayer) > 0) {
        deck->pop_top(CurrPlayer);
    }
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

void Game::startTurn() {
    draw();
    setState(Effect(EffectType::SOT, CurrPlayer, 0, CollectionType::BOARD, 2));
    notifyObservers();
    setState(Effect(EffectType::SOT, CurrPlayer, 0, CollectionType::BOARD, 3));
    notifyObservers();
}

void Game::endTurn() {
    setState(Effect(EffectType::EOT, CurrPlayer, 0, CollectionType::BOARD, 2));
    notifyObservers();
    CurrPlayer = 1 - CurrPlayer;
    OtherPlayer = 1 - OtherPlayer;
}
void Game::MinionattackPlayer(int index_1) {
    try {
        board->attackPlayer(CurrPlayer, index_1);
    } catch (int e) {
        throw e;
    }
}

void Game::MinionattackMinion(int index_1, int index_2) {
    try {
        board->attackMinion(CurrPlayer, index_1, index_2);
    } catch (int e) {
        throw e;
    }
}
void Game::PlayCard(int index_1, int player, int index_2) {
    try {
        hand->pop_selected(CurrPlayer, index_1, player, index_2);
    } catch (int e) {
        throw e;
    }
}
void Game::checkAbility(int index_1){}
void Game::UseCard(int index_1, int player, int index_2){
    try {
        board->useCard(CurrPlayer, index_1, player, index_2);
    } catch (int e) {
        throw e;
    }
}
void Game::InspectMinion(int index_1){}
void Game::ShowHand(){}

std::string Game::getWinner() {
    if (players[0]->getHealth() <= 0) {
        return players[1]->getName();
    } else if (players[1]->getHealth() <= 0) {
        return players[0]->getName();
    } else {
        return "None";
    }
}

void notify(Subject<std::shared_ptr<Card>, Effect> &whoFrom) {
    if (whoFrom.getState().type == EffectType::RES) {

    }
}