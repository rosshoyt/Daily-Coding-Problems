#include <string>
#include <iostream>

struct Rectangle {
  int topLeftX, topLeftY, width, height;
};
int LIST_SIZE = 3;
Rectangle rectangles[] = { { 1, 4, 3, 3 }, { -1, 3, 2, 1 }, { 0, 5, 4, 3 } };

/* Rectangle Comparison Methods */
bool checkRangeOverlap(int range1Low, int range1High, int range2Low, int range2High){
  if((range2Low >= range1Low && range2Low < range1High) || range2High > range1Low)
    return true;
  return false;
}
bool checkRectangleOverlap(Rectangle r1, Rectangle r2){
  return checkRangeOverlap(r1.topLeftX, r1.topLeftX + r1.width, r2.topLeftX, r2.topLeftX + r2.width)
      && checkRangeOverlap(r1.topLeftY - r1.height, r1.topLeftY, r2.topLeftY - r2.height, r2.topLeftY);
}

/* Rectangle array checking methods */
bool rectListContainsOverlappingRects(const Rectangle rectList[], int size){
  //std::cout<<"Rect 1 and 2 Overlap: " << std::boolalpha << checkRectangleOverlap(testRect1, testRect2)<<std::endl;
  //std::cout<<"Rect 1 and 3 Overlap: " << std::boolalpha << checkRectangleOverlap(testRect1, testRect3)<<std::endl;

  bool foundOverlap = false;
  int counter = 0;
  while(!foundOverlap || counter < size - 1) {
    for(int i = counter; i < size; i++){
      int otherRectIndex = counter + 1;
      std::cout<<"Rect "<< () <<" and 3 Overlap: " << std::boolalpha << checkRectangleOverlap(testRect2, testRect3)<<std::endl;
  }
}

int main(){
  std::cout<<"DCP #187: Compute whether or not a pair of rectangles overlap each other."<<std::endl;
  rectListContainsOverlappingRects(rectangles, LIST_SIZE);
  return 0;
}
