//
// Created by Tim Liu on 2019-07-22.
//

#include "Subject.h"

template <typename InfoType, typename StateType>
void Subject<InfoType, StateType>::attach(std::shared_ptr<Observer<InfoType, StateType>> o) {
    observers.emplace_back(o);
}

template <typename InfoType, typename StateType>
void Subject<InfoType, StateType>::notifyObservers() {
    for (auto &ob : observers) ob->notify(*this);
}

template <typename InfoType, typename StateType>
void Subject<InfoType, StateType>::setState(StateType newS) { state = newS; }

template <typename InfoType, typename StateType>
void Subject<InfoType, StateType>::setInfo(InfoType newI) { info = newI; }

template <typename InfoType, typename StateType>
StateType Subject<InfoType, StateType>::getState() const { return state; }

template <typename InfoType, typename StateType>
void Subject<InfoType, StateType>::detach(std::shared_ptr<Observer<InfoType, StateType>> o) {
    for (auto i = observers.begin(); i != observers.end(); i++) {
        if (i == o) {
            observers.erase(i);
        }
    }
}

template <typename InfoType, typename StateType>
InfoType Subject<InfoType, StateType>::getInfo() const { return info; }
