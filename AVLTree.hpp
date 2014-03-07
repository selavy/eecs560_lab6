#ifndef _AVLTREE_HPP_
#define _AVLTREE_HPP_

#include <cstdlib>
#include <string>
#include <iostream>
#include <cmath>
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
  void print() /* const */;
  void printinorder() /* const */;
  void print_close_cities( int x, int y, double dist );

private:
  void insert_helper(const City& city, Node * & t);
  void rotateWithLeftChild(Node * & t);
  void rotateWithRightChild(Node * & t);
  void doubleWithLeftChild(Node * & t);
  void doubleWithRightChild(Node * & t);
  void remove_helper(Node * & t, const std::string & name );
  void destruct_helper(Node * & t);
  void printinorder_helper(Node * t) /* const */;
  int getBalance(Node * t) /* const */;
  int height( Node * t ) /* const */;
  double distance( int x1, int y1, int x2, int y2 );

#ifdef COUNT
  int count;
#endif
  
  Node * root;
};

#endif
