//
// Created by tal on 1/12/19.
//

#include "Node.h"

Node::Node() {this->row = 0; this->col = 0;}

Node::Node(int i, int j) {this->row = i; this->col = j;}

int Node::getCol() const {return this->col;}

int Node::getRow() const {return this->row;}

Node Node::goDown() {return Node(this->row + 1, this->col);}

Node Node::goLeft() {return Node(this->row, this->col - 1);}


Node Node::goRight() {return Node(this->row, this->col + 1);}

Node Node::goUp() {return Node(this->row - 1, this->col);}

bool Node::equals(Node other) {
    return this->row == other.getRow() && this->col == other.getCol();
}