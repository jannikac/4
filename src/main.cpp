#include <iostream>
#define PRECISION float
#include "numerics.hpp"
#include "resource_id.cpp"

void b() {
  vector n(my_vector());
  std::cout << n.x << " " << n.y << " " << n.z;
}

int main() {
  resource_id r("id", "title", "txt");
  return 0;
}