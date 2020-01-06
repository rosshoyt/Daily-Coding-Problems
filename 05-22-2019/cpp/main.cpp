#include <string>
#include <iostream>

struct Rectangle {
  int topLeftX, topLeftY, width, height;
};
Rectangle r1 = { 1, 4, 3, 3 }, r2 = { -1, 3, 2, 1 },
  r3 = { 0, 5, 4, 3 };

int main(){

  std::cout<< r1.topLeftX << "\n";

  return 0;
}
