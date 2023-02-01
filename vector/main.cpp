#include <iostream>
#include <vector>
#include "Vector.hpp"
#include <iterator>
#define NAMESPACE ft




// int main() {
//     NAMESPACE::vector<char> myvector;
//     NAMESPACE::vector<char> myvector1;
//     myvector.push_back('a');
//     myvector.push_back('c');
//     myvector.push_back('v');
//     myvector.push_back('b');
//     myvector.push_back('x');
//     std::cout << myvector.size() << std::endl;
//     std::cout << myvector.capacity() << std::endl;
//     NAMESPACE::vector<char>::const_reverse_iterator it = myvector.rbegin();   
//     NAMESPACE::vector<char>::const_reverse_iterator it1 = myvector.rend();
//     myvector1.assign(it,it1);
//     std::cout << myvector.capacity() << std::endl;
//     myvector.pop_back();
    // std::cout << myvector.size() << std::endl;
    // std::cout << myvector.capacity() << std::endl; 
    // std::cout << myvector.max_size() << std::endl;
    // std::cout << myvector.get_allocator().max_size() << std::endl;
    // std::cout << "vector size: " << myvector.size() << std::endl;
    // std::cout << "vector capacity: " << myvector.capacity() << std::endl;


    // while(it != it1)
    // {
    //     std::cout << *it << std::endl;
    //     it++;
    // }


    // myvector.reserve(80);

    // std::cout << "vector size: " << myvector.size() << std::endl;
    // std::cout << "vector size:  scsc" << myvector[70] << std::endl;
    // std::cout << "vector capacity: " << myvector.capacity() << std::endl;

//     return 0;
// }
//invalid operands to binary expression ('ft::vector<char>::const_iterator' (aka 'iterator<const char>') and 'ft::vector<char, std::__1::allocator<char> >::iterator' (aka 'iterator<char>'))

int main ()
{
  NAMESPACE::vector<char>::iterator it;

//   it = myvector.begin();
//   it = myvector.insert ( it , '1' );
//   it = myvector.begin();
    // std::cout << *it << std::endl;
    // myvector.insert(it,6,'2');    

//   // "it" no longer valid, get a new one:
//   it = myvector.begin();

     NAMESPACE::vector<char> myvector;
    NAMESPACE::vector<char> myvector1;
    myvector.push_back('r');
    myvector.push_back('r');
    myvector.push_back('r');
    myvector.push_back('r');
    myvector.push_back('r');
    it = myvector.begin();
//   myvector.insert (myvector.begin(), &myarray[0], &myarray[0]+3);
  std::vector<char> anothervector (2,'b');
  myvector.insert (it+2,anothervector.begin(),anothervector.end());

//   char myarray [] = "Rachid";

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}