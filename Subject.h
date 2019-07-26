//
// Created by Tim Liu on 2019-07-22.
//
#include <vector>
#include <iostream>

#ifndef SORCERY_SUBJECT_H
#define SORCERY_SUBJECT_H

template <typename InfoType, typename StateType> class Observer;

template <typename InfoType, typename StateType> class Subject {
    std::vector<Observer<InfoType, StateType>*> observers;
    StateType state;
protected:
    void setState(StateType newS);
public:
    void attach(Observer<InfoType, StateType> *o);
    void detach(Observer<InfoType, StateType> *o);
    void notifyObservers();
    virtual InfoType getInfo() const = 0;
    StateType getState() const;
};

#endif //SORCERY_SUBJECT_H
