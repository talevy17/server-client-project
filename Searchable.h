//
// Created by tal on 1/10/19.
//

#ifndef SERVER_CLIENT_PROJECT_SEARCHABLE_H
#define SERVER_CLIENT_PROJECT_SEARCHABLE_H

#include "CoreState.h"
#include <vector>
#include <string>
#include <map>

template<class T>
class Searchable {
public:

    virtual bool wasVisited(State<T>* node) = 0;

    virtual void visit(State<T>* node) = 0;

    virtual State<T>* getInitialState() = 0;

    virtual State<T>* getGoalState() = 0;

    virtual std::vector<State<T>*> getAllPossibleStates(State<T> *state) = 0;

    virtual std::string to_string() = 0;
};


#endif //SERVER_CLIENT_PROJECT_SEARCHABLE_H
