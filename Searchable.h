//
// Created by tal on 1/10/19.
//

#ifndef SERVER_CLIENT_PROJECT_SEARCHABLE_H
#define SERVER_CLIENT_PROJECT_SEARCHABLE_H

#include "State.h"
#include <vector>
template <class T>
class Searchable {
public:
    virtual State<T> getInitialState() = 0;
    virtual State<T> getGoalState() = 0;
    virtual std::vector<State<T>> getAllPossibleStates() = 0;
};


#endif //SERVER_CLIENT_PROJECT_SEARCHABLE_H
