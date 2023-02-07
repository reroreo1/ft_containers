#include "Utils1.hpp"
#include <utility>
#include <iostream>
#define NAME ft
int main()
{
    NAME::pair<int, double> p1 = NAME::make_pair(10, 3.14);
    std::cout << "p1: " << p1.first << ", " << p1.second << '\n';

    // Construct pair using constructor
    NAME::pair<int, double> p2(20, 2.718);
    std::cout << "p2: " << p2.first << ", " << p2.second << '\n';

    // Access values
    std::cout << "p1 first: " << p1.first << '\n';
    std::cout << "p1 second: " << p1.second << '\n';
      p1.first = 30;
  p1.second = 1.414;
  std::cout << "p1: " << p1.first << ", " << p1.second << '\n';

  // Swap values of two pairs


  // Check equality of pairs
    NAME::pair<int, double> p3 =NAME::make_pair(10, 3.14);
  if (p1 == p3) {
    std::cout << "p1 and p3 are equal\n";
  } else {
    std::cout << "p1 and p3 are not equal\n";
  }

  // Check inequality of pairs
  if (p2 != p3) {
    std::cout << "p2 and p3 are not equal\n";
  } else {
    std::cout << "p2 and p3 are equal\n";
  }

  return 0;
}