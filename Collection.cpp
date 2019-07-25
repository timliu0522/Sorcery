//
// Created by Tim Liu on 2019-07-22.
//

#include "Collection.h"

void Collection::push_card(int player, Card *in) {
    cardlist[player].push_back(in);
    setState(Effect{EffectType::MEC, 0, 0, (CollectionType)0, 0});
}