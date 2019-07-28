//
// Created by Tim Liu on 2019-07-26.
//

#include "Player.h"

Player::Player (std::string given) : name {given} {
    this->health = 20;
    this->magic = 0;
}

std::string Player::getName() {
    return this->name;
}

int Player::getHealth() {
    return this->health;
}

int Player::getMagic() {
    return this->magic;
}

void Player::setHealth(int n) {
    if (n > 0) {
        this->health = n;
    } else {
        this->health = 0;
    }
}

void Player::setMagic(int n) {
    if (n > 0) {
        this->magic = 0;
    } else {
        this->magic = 0;
    }
}

bool Player::check_death() {
    if (this->health > 0) {
        return false;
    } else {
        return true;
    }
}

