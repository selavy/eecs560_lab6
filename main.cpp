#include <iostream>
#include <fstream>
#ifdef AVLTREE
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
  AVLTree db;
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

#ifdef COUNT
  City russellville;
  russellville.name = "Russellville"; russellville.x = 8; russellville.y = 27;
  db.remove("Russellville");
  db.insert(russellville);
  db.remove(8, 27);
  db.insert(russellville);
  
#endif

  while( (test_in >> x) && (test_in >> y) && (test_in >> dist) ) {
    db.print_close_cities( x, y, dist );
#ifdef EASY_PRINT_COMPARE
    cout << endl;
#endif
  }

  return 0;
}
