#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#import <vector>

class BinaryTree {
private:
  struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
  }
  TreeNode *root;
  std::vector<int>values;

  // Private member functions
  void insert(TreeNode *&, TreeNode *&);
  void destroySubTree(TreeNode *);
  void deleteNode(int, TreeNode *&);
  void makeDeletion(TreeNode *&);
  void displayInOrder(TreeNode *) const;
  void displayPreOrder(TreeNode *) const;
  void displayPostOrder(TreeNode *) const;



public:
  BinaryTree(std::vector<int> &vals) : values(vals) {
    root = nullptr;
  }
  ~BinaryTree() {
    destroySubTree(root);
  }
  int getSize() { return values.size(); }

  // Binary tree operations
  void insertNode(int);
  bool searchNode(int);
  void remove(int);
  void displayInOrder() const
  { displayInOrder(root); }
  void displayPreOrder() const
  { displayPreOrder(root); }
  void displayPostOrder() const
  { displayPostOrder(root); }


};




#endif
