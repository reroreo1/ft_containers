#include <iostream>
#include <vector>
#include "Vector.hpp"
// class SomeType
// {
//   int number;
 
// public:
//   SomeType(int newNumber) : number(newNumber) {}
//   SomeType() : SomeType(42) {}
// };

int main() {
    std::vector<std::string> myVector;
    // std::cout << myVector.capacity() << std::endl; 
    myVector.push_back("rachid");
    myVector.push_back("halala");
    myVector.push_back("hdafshfahs");
    myVector.push_back("fasfasf");
    myVector.push_back("fsdgs");
    std::cout << myVector.max_size() << std::endl;
    std::cout << myVector.get_allocator().max_size() << std::endl;
    // std::cout << "Vector size: " << myVector.size() << std::endl;
    // std::cout << "Vector capacity: " << myVector.capacity() << std::endl;

    // myVector.reserve(80);

    // std::cout << "Vector size: " << myVector.size() << std::endl;
    // std::cout << "Vector size:  scsc" << myVector[70] << std::endl;
    // std::cout << "Vector capacity: " << myVector.capacity() << std::endl;

    return 0;
}
