#include <iostream>
#include <vector>
#include "Vector.hpp"

#define NAMESPACE ft

int main() {
     NAMESPACE::vector<char> myVector;
    std::cout << myVector.capacity() << std::endl; 
    myVector.push_back('a');
     myVector.push_back('c');
     myVector.push_back('v');
     myVector.push_back('b');
     myVector.push_back('x');
     std::cout << myVector.max_size() << std::endl;
     std::cout << myVector.get_allocator().max_size() << std::endl;
     std::cout << "Vector size: " << myVector.size() << std::endl;
     std::cout << "Vector capacity: " << myVector.capacity() << std::endl;

    NAMESPACE::vector<char>::const_reverse_iterator it = myVector.rbegin();   
    NAMESPACE::vector<char>::const_reverse_iterator it1 = myVector.rend();   



    while(it != myVector.rend())
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
//invalid operands to binary expression ('ft::vector<char>::const_iterator' (aka 'iterator<const char>') and 'ft::vector<char, std::__1::allocator<char> >::iterator' (aka 'iterator<char>'))