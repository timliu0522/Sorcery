#ifndef SORCERY_DECK_H
#define SORCERY_DECK_H

#include "Collection.h"

class Deck : public Collection {
    int cards_left;
    
public:
    Deck();
    ~Deck();
    void load_deck(std::string filename, int num);
    void push_card(int player, Card *in);
    Card* pop_card(int player, Card *out) = 0;
};



#endif /* Deck_h */
