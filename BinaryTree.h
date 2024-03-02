#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

using namespace std;

//struct for NodeType             
template <typename T>
struct Node {
  T key;
  Node<T> *left;
  Node<T> *right;
};

//BinaryTree class                                                                                                                                                 
template <typename T>
class BinaryTree {
public:
  BinaryTree();
  ~BinaryTree();
  void clearTree(Node<T> *tree);
  void insert(T &key);
  void insertRecursive(T item, Node<T> *&tree);
  void deleteItem(T &key);
  bool deleteItemRecursive(Node<T>*& node, T key);
  void deleteNode(Node<T>*& targetNode);
  T getPrevious(Node<T>*& node) const;
  void retrieve(T &item, bool &found) const;
  void retrieveRecursive(Node<T>* node, T &item, bool& found) const;
  void preOrder() const;
  void preOrderRecursive(Node<T>* node) const;
  void inOrder() const;
  void inOrderRecursive(Node<T>* node) const;
  void postOrder() const;
  void postOrderRecursive(Node<T>* node) const;
  int getLength() const;
  int getLengthRecursive(Node<T>* node) const;
  void getNumSingleParent();
  void getNumSingleParentRecursive(Node<T>* node);
  void resetCount();
  void getNumLeafNodes() const;
  int getNumLeafNodesRecursive(Node<T>* node) const;
  int getSumOfSubtrees(T &key);

 private:
  Node<T> *root;                                                                                                                                                                                                    
  int count = 0;
};
#endif
