//
// Created by Tim Liu on 2019-07-22.
//

#include "Subject.h"

template <typename StateType>
void Subject<StateType>::attach(Observer<StateType> *o) {
    observers.emplace_back(o);
}

template <typename StateType>
void Subject<StateType>::notifyObservers() {
    for (auto &ob : observers) ob->notify(*this);
}

template <typename StateType>
void Subject<StateType>::setState(StateType newS) { state = newS; }

template <typename StateType>
StateType Subject<StateType>::getState() const { return state; }

template <typename StateType>
void Subject<StateType>::detach(Observer<StateType> *o) {
    for (auto i = observers.begin(); i != observers.end(); i++) {
        if (i == o) {
            observers.erase(i);
        }
    }
}
