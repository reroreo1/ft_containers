#include <iostream>
#include <vector>
#include "Vector.hpp"

#define NAMESPACE ft

int main() {
    NAMESPACE::vector<char> myVector;
    // NAMESPACE::cout << myVector.capacity() << NAMESPACE::endl; 
    myVector.push_back('a');
     myVector.push_back('c');
     myVector.push_back('v');
     myVector.push_back('b');
     myVector.push_back('x');
     std::cout << myVector.max_size() << std::endl;
     std::cout << myVector.get_allocator().max_size() << std::endl;
     std::cout << "Vector size: " << myVector.size() << std::endl;
     std::cout << "Vector capacity: " << myVector.capacity() << std::endl;

    NAMESPACE::vector<char>::iterator it = myVector.begin();
    while(it != myVector.end())
    {
        std::cout << *it << std::endl;
        it++;
    }
    // myVector.reserve(80);

    // std::cout << "Vector size: " << myVector.size() << std::endl;
    // std::cout << "Vector size:  scsc" << myVector[70] << std::endl;
    // std::cout << "Vector capacity: " << myVector.capacity() << std::endl;

    return 0;
}
