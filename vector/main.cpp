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



// template <typename T, typename = std::enable_if_t<std::is_integral<T>::value,
//                                                   float>









#include <iostream>
#include <vector>

int main ()
{
  NAMESPACE::vector<int> foo (3,100);   // three ints with a value of 100
  NAMESPACE::vector<int> bar (5,200);   // five ints with a value of 200

  NAME::swap(foo, bar);

  std::cout << "foo contains:";
  for (unsigned i=0; i<foo.size(); i++)
    std::cout << ' ' << foo[i];
  std::cout << '\n';

  std::cout << "bar contains:";
  for (unsigned i=0; i<bar.size(); i++)
    std::cout << ' ' << bar[i];
  std::cout << '\n';

  return 0;
}