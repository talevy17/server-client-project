//
// Created by tal on 1/12/19.
//

#include "Node.h"

Node::Node() {this->row = 0; this->col = 0;}

Node::Node(int i, int j) {this->row = i; this->col = j;}

int Node::getCol() const {return this->col;}

int Node::getRow() const {return this->row;}

Node Node::goDown() {return Node(this->row + 1, this->col);}

Node Node::goDownLeft() {return Node(this->row + 1, this->col -1);}

Node Node::goLeft() {return Node(this->row, this->col - 1);}

Node Node::goDownRight() {return Node(this->row + 1, this->col + 1);}

Node Node::goRight() {return Node(this->row, this->col + 1);}

Node Node::goUp() {return Node(this->row - 1, this->col);}

Node Node::goUpLeft() {return Node(this->row - 1, this->col - 1);}

Node Node::goUpRight() {return Node(this->row - 1, this->col + 1);}