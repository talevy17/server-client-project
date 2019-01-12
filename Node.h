//
// Created by tal on 1/12/19.
//

#ifndef SERVER_CLIENT_PROJECT_NODE_H
#define SERVER_CLIENT_PROJECT_NODE_H


class Node {
    int row;
    int col;
public:
    Node(int i, int j);
    Node();
    int getRow() const;
    int getCol() const;
    Node goUp();
    Node goDown();
    Node goRight();
    Node goLeft();
    Node goUpRight();
    Node goUpLeft();
    Node goDownRight();
    Node goDownLeft();
    bool equals(Node other);
};


#endif //SERVER_CLIENT_PROJECT_NODE_H
