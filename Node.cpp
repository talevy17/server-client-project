

#include "Node.h"

/**
 * default CTOR, initiates values to 0.
 */
Node::Node() {
    this->row = 0;
    this->col = 0;
}

/**
* CTOR.
* @param i
* @param j
*/
Node::Node(int i, int j) {
    this->row = i;
    this->col = j;
}

/**
 * column getter.
 * @return this->col
 */
int Node::getCol() const { return this->col; }

/**
* row getter
* @return this->row
*/
int Node::getRow() const { return this->row; }

/**
 * move down the matrix.
 * @return Node(i+1,j)
 */
Node Node::goDown() { return Node(this->row + 1, this->col); }

/**
 * move left the matrix.
 * @return Node(i,j-1)
 */
Node Node::goLeft() { return Node(this->row, this->col - 1); }

/**
 * move right the matrix.
 * @return Node(i,j+1)
 */
Node Node::goRight() { return Node(this->row, this->col + 1); }

/**
 * move up the matrix.
 * @return Node(i - 1,j)
 */
Node Node::goUp() { return Node(this->row - 1, this->col); }

/**
 * overriding the equals method, as part of the assumption that every elements as an equals method.
 * @param other
 * @return
 */
bool Node::operator==(const Node &other) {
    return this->row == other.getRow() && this->col == other.getCol();
}

/**
 * this node position is from right to the other
 * @param other node
 * @return true - if from right, false - else
 */
bool Node::operator>(const Node &other) {
    return (this->row==other.row)&&(this->col>other.col);
}

/**
 * this node position is down to the other
 * @param other node
 * @return true - if down, false - else
 */
bool Node::operator<=(const Node &other) {
    return (this->row<other.row)&&(this->col==other.col);
}

/**
 * this node position is up to the other
 * @param other node
 * @return true - if up, false - else
 */
bool Node::operator>=(const Node &other) {
    return (this->row>other.row)&&(this->col==other.col);
}

Node::Node(const Node &other) {
    this->col = other.getCol();
    this->row = other.getRow();
}

Node &Node::operator=(const Node &other) {
    this->col = other.getCol();
    this->row = other.getRow();
    return *this;
}

bool Node::operator<(const Node &other) {
    if (this->row != other.getRow())
        return (this->row < other.getRow());
    return (this->col < other.getCol());
}