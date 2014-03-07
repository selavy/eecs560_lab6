#include "Array.hpp"

Array::Array(int size) : _size(size), _curr(0) {
  _arr = new City[size];
}

Array::~Array() {
  delete [] _arr;
}

void Array::insert(const City& coord) {
#ifdef COUNT
  int count = 0;
#endif
  // copy constructor fine?
  _arr[_curr] = coord;
  ++_curr;

  if(_curr >= _size) {
    _size *= 2;
    City * new_arr = new City[_size];
    for(int i=0; i < _curr; ++i) {
      new_arr[i] = _arr[i];
    }
    delete [] _arr;
    _arr = new_arr;
  }
#ifdef COUNT
  std::cout << "List item comparisons in insert(city): " << count << std::endl;
#endif
}

void Array::remove(const std::string& name) {
#ifdef COUNT
  int count = 0;
#endif
  for(int i=0; i < _curr; ++i) {
#ifdef COUNT
    ++count;
#endif
    if(_arr[i].name == name) {
      _arr[i] = _arr[--_curr];
    }
  }
#ifdef COUNT
  std::cout << "List item comparisons in remove(name): " << count << std::endl;
#endif
}

void Array::remove(int x, int y) {
#ifdef COUNT
  int count = 0;
#endif
  for(int i=0; i < _curr; ++i) {
#ifdef COUNT
    ++count;
#endif
    if((_arr[i].x == x) && (_arr[i].y == y)) {
      _arr[i] = _arr[--_curr];
    }
  }
#ifdef COUNT
  std::cout << "List item comparisons in remove(x,y): " << count << std::endl;
#endif
}

void Array::print() const {
  for(int i = 0; i < _curr; ++i) {
    std::cout << _arr[i].name << " ";
  }
}

void Array::print_close_cities( int x, int y, double dist ) {
#ifdef COUNT
  int count = 0;
#endif
  int found = -1;

  for( int i = 0; i < _curr; ++i ) {
#ifdef COUNT
    count += 2;
#endif
    if( (_arr[i].x == x) && (_arr[i].y == y) ) {
      found = i;
      std::cout << _arr[i].name << std::endl; break;
    }
  }
  
  for( int i = 0; i < _curr; ++i ) {
    if( i == found ) continue;
#ifdef COUNT
    count += 2; /* two accesses, arr[i].x and arr[i].y */
#endif
    if( distance( x, y, _arr[i].x, _arr[i].y ) <= dist )
      std::cout << _arr[i].name << std::endl;
  }
#ifdef COUNT
  std::cout << "List item comparisons in print_close_cities: " << count << std::endl;
#endif
}

double Array::distance( int x1, int y1, int x2, int y2 ) {
  const double x_diff = x2 - x1;
  const double y_diff = y2 - y1;
  const double rad = x_diff * x_diff + y_diff * y_diff;
  return sqrt( rad );
}

