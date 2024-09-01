#include <iostream>

using namespace std;
int main() {

  //========================================
  // Creating a unique_ptr using std::make_unique (preferred)
  std::unique_ptr<int> pNum3 = std::make_unique<int>(5);

  // Accessing the value
  std::cout << "Value: " << *pNum3 << std::endl;

  // Creating a unique_ptr for an array
  std::unique_ptr<int[]> pArray = std::make_unique<int[]>(5);

  // Initialize and access elements
  for (int i = 0; i < 5; ++i) {
    pArray[i] = i * 10;
    std::cout << "pArray[" << i << "]: " << pArray[i] << std::endl;
  }

  // No need to call delete; the memory is automatically freed when pNum and
  // pArray go out of scope.
}
