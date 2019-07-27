//
// Created by kevinwen on 7/26/19.
//

#include "Board.h"
#include "State.h"

Board::Board() {
}

Board::~Board() {
    for (int i = 0; i < 2; i++) {
        while (!cardlist[i].empty()) {
            delete cardlist[i].back();
            cardlist[i].pop_back();
        }
        while (!ritual[i].empty()) {
            delete ritual[i].back();
            ritual[i].pop_back();
        }
    }
}

void Board::push_card(int player, Card *in) {
    if (in->get_type() == "Ritual") {
        if (!ritual[player].empty()) {
            detach(ritual[player][0]);
            ritual[player].pop_back();
        }
        ritual[player].push_back(in);
    } else {
        cardlist[player].emplace_back(in);
        int new_size = (int) cardlist[player].size();
        cardlist[player][cardlist[player].size() - 1]->attach(this);
        if (in->get_type() == "Minion") {
            setState(Effect(EffectType::MEC, player, new_size - 1, CollectionType::BOARD));
            notify_APNAP();
        }
    }
}

void Board::pop_card(Card *out) {
    for (int player = 0; player < 2; player ++) {
        int i = 0;
        for (auto it = cardlist[player].begin(); it != cardlist[player].end(); it++, i++) {
            if (*it != out) continue;
            setState(Effect(EffectType::MLC, player, i, CollectionType::GRAVE));
            notify_APNAP();
            detach(*it);
            cardlist[player].erase(it);
            return;
        }
        for (auto it = ritual[player].begin(); it != cardlist[player].end(); it++) {
            if (*it != out) continue;
            detach(*it);
            cardlist[player].erase(it);
            return;
        }
    }
}

void Board::notify_APNAP() {
    setState(Effect(getState().type, cur_player, getState().target, getState().destination, getState().value, 0));
    notifyObservers();
    setState(Effect(getState().type, cur_player, getState().target, getState().destination, getState().value, 1));
    notifyObservers();
    setState(Effect(getState().type, 1 - cur_player, getState().target, getState().destination, getState().value, 0));
    notifyObservers();
    setState(Effect(getState().type, 1 - cur_player, getState().target, getState().destination, getState().value, 1));
    notifyObservers();
    setState(Effect(getState().type, cur_player, getState().target, getState().destination, getState().value, 2));
    notifyObservers();
}

void Board::notify(Subject<Card *, Effect> &whoFrom) {
    if (whoFrom.getState().type == EffectType::SOT) {
        setState(whoFrom.getState());
        notify_APNAP();
    } else if (whoFrom.getState().type == EffectType::EOT) {
        setState(whoFrom.getState());
        notify_APNAP();
    } else if (whoFrom.getState().type == EffectType::MLC) {
        pop_card(whoFrom.getInfo());
    } else if (whoFrom.getState().type == EffectType::DMG) {
        setState(whoFrom.getState());
        notify_APNAP();
    } else if (whoFrom.getState().type == EffectType::BUF) {
        setState(whoFrom.getState());
        notify_APNAP();
    } else if (whoFrom.getState().type == EffectType::MEC) {
        push_card(whoFrom.getInfo()->get_player(), whoFrom.getInfo());
    } else if (whoFrom.getState().type == EffectType::DEC) {

    }
}
