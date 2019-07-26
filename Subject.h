//
// Created by Tim Liu on 2019-07-22.
//
#include <vector>
#include <iostream>

#ifndef SORCERY_SUBJECT_H
#define SORCERY_SUBJECT_H

template <typename StateType> class Observer;

template <typename StateType> class Subject {
    std::vector<Observer<StateType>*> observers;
    StateType state;
protected:
    void setState(StateType newS);
public:
    void attach(Observer<StateType> *o);
    void detach(Observer<StateType> *o);
    virtual void notifyObservers();
    StateType getState() const;
};

#endif //SORCERY_SUBJECT_H
