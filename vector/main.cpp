#include <iostream>
#include <vector>
#include "Vector.hpp"

#define NAMESPACE ft

int main() {
     NAMESPACE::vector<char> myvector;
    myvector.push_back('a');
    myvector.push_back('c');
    myvector.push_back('v');
    myvector.push_back('b');
    myvector.push_back('x');
    std::cout << myvector.size() << std::endl;
    std::cout << myvector.capacity() << std::endl; 
    myvector.pop_back();
    std::cout << myvector.size() << std::endl;
    std::cout << myvector.capacity() << std::endl; 
    std::cout << myvector.max_size() << std::endl;
    std::cout << myvector.get_allocator().max_size() << std::endl;
    std::cout << "vector size: " << myvector.size() << std::endl;
    std::cout << "vector capacity: " << myvector.capacity() << std::endl;

    NAMESPACE::vector<char>::iterator it = myvector.begin();   
    NAMESPACE::vector<char>::iterator it1 = myvector.end();   

    while(it != it1)
    {
        std::cout << *it << std::endl;
        it++;
    }


    // myvector.reserve(80);

    // std::cout << "vector size: " << myvector.size() << std::endl;
    // std::cout << "vector size:  scsc" << myvector[70] << std::endl;
    // std::cout << "vector capacity: " << myvector.capacity() << std::endl;

    return 0;
}
//invalid operands to binary expression ('ft::vector<char>::const_iterator' (aka 'iterator<const char>') and 'ft::vector<char, std::__1::allocator<char> >::iterator' (aka 'iterator<char>'))