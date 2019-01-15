//
// Created by tal on 1/12/19.
//

#ifndef SERVER_CLIENT_PROJECT_NODE_H
#define SERVER_CLIENT_PROJECT_NODE_H

/**
 * the node class used to ease the access to the Matrix's class elements.
 */
class Node {
    int row;
    int col;
public:
    /**
     * CTOR.
     * @param i
     * @param j
     */
    Node(int i, int j);

    /**
    * default CTOR, initiates values to 0.
    */
    Node();

    /**
     * row getter
     * @return this->row
     */
    int getRow() const;

    /**
    * column getter.
    * @return this->col
    */
    int getCol() const;

    /**
    * move up the matrix.
    * @return Node(i-1,j)
    */
    Node goUp();

    /**
    * move down the matrix.
    * @return Node(i+1,j)
    */
    Node goDown();

    /**
    * move right the matrix.
    * @return Node(i,j+1)
    */
    Node goRight();

    /**
    * move left the matrix.
    * @return Node(i,j-1)
    */
    Node goLeft();

    /**
    * overriding the equals method, as part of the assumption that every elements as an equals method.
    * @param other
    * @return
    */
    bool operator==(const Node &other);
    /**
     * represent position of nodes. - left
     * @param other
     * @return
     */
    bool operator<(const Node &other);
    /**
     * represent position of nodes. - right
     * @param other
     * @return
     */
    bool operator>(const Node &other);
    /**
     * represent position of nodes. - down
     * @param other
     * @return
     */
    bool operator<=(const Node &other);
    /**
     * represent position of nodes. - up
     * @param other
     * @return
     */
    bool operator>=(const Node &other);

    bool operator<(Node& other);

    Node(const Node &other);

    Node &operator=(const Node &other);
};


#endif //SERVER_CLIENT_PROJECT_NODE_H
