#import <iostream>
#import "IntBinaryTree.h"
/**
* Daily Coding Problem #196 05-31-2019
* This main program tests IntBinaryTree data structure's method
* getMostFrequentSubtreeSum(), which is the solution to this DCP.
*/
int main(){
  std::cout<< "Welcome to DCP #196\nSeeding BinaryTree...\n";
  IntBinaryTree binaryTree;
  binaryTree.insertNode(5);
  binaryTree.insertNode(2);
  binaryTree.insertNode(-5);
  auto result = binaryTree.getMostFrequentSubtreeSum();
  std::cout << "Most frequent subtree sum is: " << result.first << " (should be 2)\n"
            << "Sum occured " << result.second << " times (should be 2)\n";
  return 0;
}
