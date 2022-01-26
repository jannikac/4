#include "numerics.hpp"
#include <iostream>
vector my_vector() {
  vector n;
  n.x = n.y = n.z = 1234;
  std::cout << n.x << " " << n.y << " " << n.z;
  return n;
}