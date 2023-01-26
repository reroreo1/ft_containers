#include <iostream>
#include <vector>

class SomeType
{
  int number;
 
public:
  SomeType(int newNumber) : number(newNumber) {}
  SomeType() : SomeType(42) {}
};

int main() {
    std::vector<int> myVector;
    std::cout << myVector.capacity() << std::endl; 
    myVector.push_back(1);
    myVector.push_back(2);
    myVector.push_back(3);
    myVector.push_back(4);
    myVector.push_back(5);

    std::cout << "Vector size: " << myVector.size() << std::endl;
    std::cout << "Vector capacity: " << myVector.capacity() << std::endl;

    myVector.reserve(80);

    std::cout << "Vector size: " << myVector.size() << std::endl;
    std::cout << "Vector size:  scsc" << myVector[70] << std::endl;
    std::cout << "Vector capacity: " << myVector.capacity() << std::endl;

    return 0;
}
