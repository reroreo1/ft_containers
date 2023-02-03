#include <iostream> 
#include "Vector.hpp"
int main()
{

    std::vector<char> *myvector = new ();
    std::cout << myvector->size() << " " << myvector->capacity() << std::endl;  // 5 default-constructed ints
    std::vector<char>::iterator it = myvector->insert(myvector->end(), 'a');
    std::cout << *it << std::endl;
  return 0;
}