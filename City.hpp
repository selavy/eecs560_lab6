#ifndef _CITY_HPP_
#define _CITY_HPP_

#include <string>

struct City {
  std::string name;
  int x;
  int y;

  bool operator<(const City& rhs) const {
    return (name < rhs.name);
  }
  bool operator>(const City& rhs) const {
    return (name > rhs.name);
  }
};

#endif
