#ifndef SORCERY_DECK_H
#define SORCERY_DECK_H

#include "Collection.h"

class Deck : public Collection {
    int cards_left;
    
public:
    Deck();
    ~Deck();
    void load_deck(std::string filename, int num);
    void push_card(int player, Card *in) override;
    void pop_card(Card *out) override;
};



#endif /* Deck_h */
