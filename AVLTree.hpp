#ifndef _AVLTREE_HPP_
#define _AVLTREE_HPP_

#include <cstdlib>
#include <string>
#include <iostream>
#include "City.hpp"

class AVLTree {
public:
  struct Node {
    Node(const City& c, Node *l, Node *r, int h = 0) :
      city(c), left(l), right(r), height(h)
    {
    }
    City city;
    Node * left;
    Node * right;
    int height;
  };

#define MAX(a,b) (((a) > (b)) ? (a) : (b))

public:
  AVLTree();
  virtual ~AVLTree();

  void insert(const City& city);
  void remove(const std::string& name);
  void remove(int x, int y);
  void print() const;
  void printinorder() const;

private:
  void insert_helper(const City& city, Node * & t);
  void rotateWithLeftChild(Node * & t);
  void rotateWithRightChild(Node * & t);
  void doubleWithLeftChild(Node * & t);
  void doubleWithRightChild(Node * & t);
  void remove_helper(Node * & t, const std::string & name );
  void destruct_helper(Node * & t);
  void printinorder_helper(Node * t) const;
  int getBalance(Node * t) const;
  int height( Node * t ) const;
  
  Node * root;
};

#endif
