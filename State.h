//
// Created by Tim Liu on 2019-07-22.
//

#ifndef SORCERY_STATE_H
#define SORCERY_STATE_H

enum class EffectType {SOT, EOT, MEC, MLC, DMG, BUF, MOV, DEC};
enum class CollectionType {DECK, BOARD, GRAVE, HAND};

struct Effect {
    EffectType type;
    int player;
    int target;
    CollectionType destination;
    int value;
};

#endif //SORCERY_STATE_H
