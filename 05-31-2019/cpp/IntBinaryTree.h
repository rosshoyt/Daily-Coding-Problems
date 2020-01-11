#ifndef INT_BINARY_TREE_H
#define INT_BINARY_TREE_H
#import <vector>
#import <map>
/**
* Simple implementation of an unordered complete Binary Tree, backed
* by std::vector<int>
* I chose this data structure and implementation because DCP #196 does not
* specify a type of binary tree other than the provided example,
* which does not abide by the conventional ordering of smaller values to
* the left - additionally, the example is a complete tree.
*
* Compile with g++ main.cpp -o main
* Run with ./main
*/
class IntBinaryTree {
private:
  std::vector<int>values;

public:
  IntBinaryTree() : values() {}

  int getSize() { return values.size(); }

  void insertNode(int val){ values.push_back(val); }

  /*
  * DCP #196 - Solution Algorithm
  * Finds most frequently occuring subtree sum of a unordered,
  * complete binary tree
  * @return std::pair<int,int> where first is the most frequent subtree sum and
  * second is the number of occurances of that sum
  */
  std::pair<int,int> getMostFrequentSubtreeSum(){
    // create tracking data structures
    int sums[getSize()]; // dynamic array to hold calculated sums
    std::map<int,int> sumFreqs; // map to track frequency of subtree sums

    // First, calculate all subtree sums
    for(int i = getSize() - 1; i >= 0; i--){
      int subtreeSum = values[i];
      if((getSize() / 2) > i) {
        // node is not leaf, get child sum(s)
        int leftChildInd = i * 2 + 1, rightChildInd = leftChildInd + 1;
        subtreeSum += sums[leftChildInd] + (rightChildInd < getSize() ? sums[rightChildInd] : 0);
      }
      sums[i] = subtreeSum; // record subtreeSum in dynamic array
      sumFreqs[subtreeSum]++; // increment frequency tracker
    }

    // Now find largest map value (the most frequent subtree sum)
    auto it = sumFreqs.begin();
    std::pair<int,int> mostFreqSum;
    while(it != sumFreqs.end()){
      if(it->second > mostFreqSum.second){
        mostFreqSum.first = it->first;
        mostFreqSum.second = it->second;
      }
      it++;
    }
    return mostFreqSum;
  }
};

#endif
