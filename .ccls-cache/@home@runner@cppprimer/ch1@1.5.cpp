#include <iostream>

int main() {
  std::cout << "Enter two numbers: " << std::endl;
  int v1, v2;
  std::cin >> v1 >> v2;
  std::cout << "The sum of ";
  std::cout << v1;
  std::cout << " and ";
  std::cout << v2;
  std::cout << " is ";
  std::cout << v1 + v2;
  std::cout << std::endl;
}