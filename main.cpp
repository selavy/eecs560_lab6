#include <iostream>
#include <fstream>
#ifdef AVLTree
#include "AVLTree.hpp"
#else
#include "Array.hpp"
#endif

using namespace std;

int main( int argc, char **argv ) {
  ifstream in, test_in;
  std::string city_name;
  int x, y, dist;

#ifdef AVLTREE
#else
  Array db;
#endif

  if( argc == 3 ) {
    in.open( argv[1] );
    test_in.open( argv[2] );
  } else {
    in.open( "data.txt" );
    test_in.open( "test_file.txt" );
  }

  if( !in.good() || !test_in.good() ) {
    cerr << "Unable to open file!" << endl;
  }

  while( (in >> city_name) && (in >> x) && (in >> y) ) {
    City city;
    city.name = city_name; city.x = x; city.y = y;
    db.insert(city);
  }

  while( (test_in >> x) && (test_in >> y) && (test_in >> dist) ) {
    db.print_close_cities( x, y, dist );
  }

  return 0;
}
