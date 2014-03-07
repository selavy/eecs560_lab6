#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_

#include "City.hpp"
#include <cstdlib>
#include <iostream>
#include <cmath>

#define INIT_SIZE 120

class Array {
public:
  explicit Array(int size = INIT_SIZE);
  virtual ~Array();

  void insert(const City& coord);
  void remove(const std::string& name);
  void remove(int x, int y);
  void print() const;
  void print_close_cities(int x, int y, double dist);

private:
  double distance( int x1, int y1, int x2, int y2 );

  int _size;
  int _curr;
  City * _arr;
};

#endif
