#include <iostream> 
#include "Vector.hpp"
// #include<vector>
int main()
{

    // std::vector<char> *myvector = new ();
    // std::cout << myvector->size() << " " << myvector->capacity() << std::endl;  // 5 default-constructed ints
    // std::vector<char>::iterator it = myvector->insert(myvector->end(), 'a');
    // std::cout << *it << std::endl;

    char *s[]= {"QExoqp0nICr0sXsHqty2", "naax9QcpJhvaL7DezsNQ" };
    ft::vector<std::string> vec;
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");
    vec.push_back("d");

           vec.erase(vec.begin() + 3, vec.begin() + 16);
    vec.assign(s, s);
    std::cout << vec.size() << std::endl;
  return 0;
}