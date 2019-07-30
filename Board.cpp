//
// Created by kevinwen on 7/26/19.
//

#include "Board.h"
#include "State.h"
#include "all_cards.h"

Board::Board() {
}

Board::~Board() {
    for (int i = 0; i < 2; i++) {
        while (!cardlist[i].empty()) {
            // delete cardlist[i].back();
            cardlist[i].pop_back();
        }
        while (!ritual[i].empty()) {
            //delete ritual[i].back();
            ritual[i].pop_back();
        }
    }
}

void Board::push_card(int player, std::shared_ptr<Card> in) {
    if (in->get_type() == "Ritual") {
        if (!ritual[player].empty()) {
            // detach(ritual[player][0]);
            ritual[player][0]->set_belong(CollectionType::GRAVE);
            ritual[player].pop_back();
        }
        in->set_belong(CollectionType::BOARD);
        ritual[player].push_back(in);
        ritual[player][0]->attach(shared_from_this());
    } else {
        if (cardlist[player].size() == 5) {
            throw 9;
        }
        cardlist[player].emplace_back(in);
        int new_size = (int) cardlist[player].size();
        cardlist[player][cardlist[player].size() - 1]->attach(shared_from_this());
        in->set_belong(CollectionType::BOARD);
        if (in->get_type() == "Minion") {
            setState(Effect(EffectType::MEC, player, new_size - 1, CollectionType::BOARD));
            notify_APNAP();
        }
    }
}

void Board::pop_card(int place, std::shared_ptr<Card>out) {
    CollectionType where = place == 0 ? CollectionType::GRAVE : CollectionType::HAND;
    for (int player = 0; player < 2; player ++) {
        int i = 0;
        for (auto it = cardlist[player].begin(); it != cardlist[player].end(); it++, i++) {
            if (*it != out) continue;
            setState(Effect(EffectType::MLC, player, i, where));
            notify_APNAP();
            // detach(*it);
            out->set_belong(where);
            out->reset();
            cardlist[player].erase(it);
            return;
        }
        for (auto it = ritual[player].begin(); it != cardlist[player].end(); it++) {
            if (*it != out) continue;
            // detach(*it);
            out->set_belong(where);
            cardlist[player].erase(it);
            return;
        }
    }
}

void Board::attackPlayer(int player, int idx) {
    if (cardlist[player].size() < idx) {
        throw 7;
    }
    if (cardlist[player][idx - 1]->get_action_left() <= 0) {
        throw 11;
    }
    cardlist[player][idx - 1]->add_action();
    setState(Effect(EffectType::DMG, 1 - player, 0, CollectionType::BOARD, cardlist[player][idx - 1]->get_attack(), 0, 3));
    notifyObservers();
}

void Board::attackMinion(int player, int idx1, int idx2) {
    if (cardlist[player].size() < idx1) {
        throw 7;
    } else if (cardlist[1 - player].size() < idx2) {
        throw 7;
    }
    if (cardlist[player][idx1 - 1]->get_action_left() <= 0) {
        throw 11;
    }
    cardlist[player][idx1 - 1]->add_action();
    setInfo(cardlist[player][idx1 - 1]);
    setState(Effect(EffectType::DMG, player, 0, CollectionType::BOARD, cardlist[1 - player][idx2 - 1]->get_attack(), 0, 0));
    notifyObservers();
    setInfo(cardlist[1 - player][idx2 - 1]);
    setState(Effect(EffectType::DMG, 1 - player, 0, CollectionType::BOARD, cardlist[player][idx1 - 1]->get_attack(), 0, 0));
    notifyObservers();
}

void Board::notify_APNAP() {
    setState(Effect(getState().type, cur_player, getState().target, getState().destination, getState().value1, getState().value2, 0));
    notifyObservers();
    setState(Effect(getState().type, cur_player, getState().target, getState().destination, getState().value1, getState().value2, 1));
    notifyObservers();
    setState(Effect(getState().type, 1 - cur_player, getState().target, getState().destination, getState().value1, getState().value2, 0));
    notifyObservers();
    setState(Effect(getState().type, 1 - cur_player, getState().target, getState().destination, getState().value1, getState().value2, 1));
    notifyObservers();
    setState(Effect(getState().type, cur_player, getState().target, getState().destination, getState().value1, getState().value2, 2));
    notifyObservers();
    setState(Effect(getState().type, cur_player, getState().target, getState().destination, getState().value1, getState().value2, 3));
    notifyObservers();
}

void Board::useCard(int player, int idx, int tar, int idx2) {
    if (cardlist[player].size() < idx) {
        throw 7;
    }
    if (cardlist[player][idx - 1]->get_action_left() <= 0) {
        throw 11;
    }
    if (!cardlist[player][idx - 1]->has_activated()) {
        throw 12;
    }
    if (cardlist[player][idx - 1]->can_target()) {
        if (tar == -1) {
            throw 10;
        }
        if (cardlist[tar].size() < idx2) {
            throw 7;
        }
        setState(cardlist[player][idx - 1]->get_effect());
        setInfo(cardlist[tar][idx2 - 1]);
        notifyObservers();
    } else {
        if (tar != -1) {
            throw 8;
        }
        if (cardlist[player].size() >= 5) {
            throw 9;
        }
        for (int i = 0; i < getState().target && cardlist[player].size() < 5; i++) {
            push_card(player, std::make_shared<Air_Elemental>(player));
        }
    }
}

void Board::notify(Subject<std::shared_ptr<Card>, Effect> &whoFrom) {
    if (whoFrom.getState().notified_type != 2) return;
    if (whoFrom.getState().type == EffectType::SOT) {
        setState(whoFrom.getState());
        notifyObservers();
    } else if (whoFrom.getState().type == EffectType::EOT) {
        setState(whoFrom.getState());
        notifyObservers();
        cur_player = 1 - cur_player;
    } else if (whoFrom.getState().type == EffectType::MLC) {
         pop_card(0, whoFrom.getInfo());
    } else if (whoFrom.getState().type == EffectType::DMG) {
        setInfo(whoFrom.getInfo());
        setState(whoFrom.getState());
        if (whoFrom.getState().target == 3)
            notify_APNAP();
        else
            notifyObservers();
    } else if (whoFrom.getState().type == EffectType::BUF) {
        setInfo(whoFrom.getInfo());
        setState(whoFrom.getState());
        notifyObservers();
    } else if (whoFrom.getState().type == EffectType::MEC) {
        push_card(whoFrom.getInfo()->get_player(), whoFrom.getInfo());
    } else if (whoFrom.getState().type == EffectType::MOV) {
        if (whoFrom.getState().destination == CollectionType::BOARD) {
            std::shared_ptr<Card> c = whoFrom.getInfo();
            if (c->get_type() == "Minion") {
                if (whoFrom.getState().target != -1) {
                    throw 8;
                }
                if (cardlist[whoFrom.getState().player].size() >= 5) {
                    throw 9;
                }
                push_card(whoFrom.getState().player, c);
            } else if (c->get_type() == "Ritual") {
                if (whoFrom.getState().target != -1) {
                    throw 8;
                }
                push_card(whoFrom.getState().player, c);
            } else if (c->get_type() == "Spell") {
                if (c->can_target()) {
                    if (whoFrom.getState().target == -1) {
                        throw 10;
                    }
                    if (whoFrom.getState().value1 <= 5) {
                        if (cardlist[whoFrom.getState().target].size() < whoFrom.getState().value1) {
                            throw 7;
                        }
                        setState(c->get_effect());
                        setInfo(cardlist[whoFrom.getState().target][whoFrom.getState().value1 - 1]);
                        notifyObservers();
                    } else {
                        if (ritual[whoFrom.getState().target].size() < 1) {
                            throw 7;
                        }
                        setState(c->get_effect());
                        setInfo(ritual[whoFrom.getState().target][0]);
                        notifyObservers();
                    }
                } else {
                    if (whoFrom.getState().target != -1) {
                        throw 8;
                    }
                    setState(c->get_effect());
                    if (getState().type == EffectType::DMG && getState().target == 3)
                        notify_APNAP();
                    else
                        notifyObservers();
                }
            } else if (c->get_type() == "Enchantment") {
                if (whoFrom.getState().target == -1) {
                    throw 10;
                }
                if (cardlist[whoFrom.getState().target].size() < whoFrom.getState().value1) {
                    throw 7;
                }
                cardlist[whoFrom.getState().target][whoFrom.getState().value1 - 1]->add_enc(c);
            }
        } else if (whoFrom.getState().destination == CollectionType::GRAVE) {
            pop_card(0, whoFrom.getInfo());
        } else if (whoFrom.getState().destination == CollectionType::HAND) {
            pop_card(1, whoFrom.getInfo());
        }
    } else if (whoFrom.getState().type == EffectType::DEC) {

    }
}
