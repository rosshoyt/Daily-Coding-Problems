#include <string>
#include <iostream>

struct Rectangle {
  int topLeftX, topLeftY, width, height;
};

Rectangle testRect1 = { 1, 4, 3, 3 }, testRect2 = { -1, 3, 2, 1 },
  testRect3 = { 0, 5, 4, 3 };

bool checkRangeOverlap(int range1Low, int range1High, int range2Low, int range2High){
  if((range2Low >= range1Low && range2Low < range1High) || (range2High > range1Low))
    return true;
  return false;
}

bool checkRectangleOverlap(Rectangle r1, Rectangle r2){
  return checkRangeOverlap(r1.topLeftX, r1.topLeftX + r1.width, r2.topLeftX, r2.topLeftX + r2.width)
      && checkRangeOverlap(r1.topLeftY - r1.height, r1.topLeftY, r2.topLeftY - r2.height, r2.topLeftY);
}

int main(){
  std::cout<<"DCP #187: Compute whether or not a pair of rectangles overlap each other."<<std::endl;
  std::cout<<"Rect 1 and 2 Overlap: " << std::boolalpha << checkRectangleOverlap(testRect1, testRect2)<<std::endl;
  std::cout<<"Rect 1 and 3 Overlap: " << std::boolalpha << checkRectangleOverlap(testRect1, testRect3)<<std::endl;
  std::cout<<"Rect 2 and 3 Overlap: " << std::boolalpha << checkRectangleOverlap(testRect2, testRect3)<<std::endl;
  return 0;
}
