/*
This ia Binary Tree cpp file 
*/

#include <iostream>
#include <string>
#include <iostream>
#include <ostream>
#include <cstddef>
#include "BinaryTree.h"

using namespace std;

template <typename T>
BinaryTree<T>::BinaryTree(){ //constructor
  root = nullptr;
}
template <typename T>
BinaryTree<T>::~BinaryTree() { //destructor 
  clearTree(root);  
}

template <typename T> 
void BinaryTree<T>::clearTree(Node<T> *tree){ //cleartree
  if (tree == nullptr) {
    return;
  }
  clearTree(tree->left); //clears what is left and right of the node 
  clearTree(tree->right);

  delete tree; // delete tree
}

template <typename T>
void BinaryTree<T>::insert(T &key) { //inset key 
  insertRecursive(key, root  ); // calls are recurvise method  
}

template <typename T>
void BinaryTree<T>::insertRecursive(T item, Node<T> *&tree) { //the recursive method 
  if (tree == nullptr) { // insertion position found
      tree = new Node<T>;
      tree->right = nullptr; //makes the right and left null
	    tree->left = nullptr;
	    tree->key = item;
    }

    else {	
	if (item < tree->key) {
	    insertRecursive(item, tree->left); // left subtree
	}

	else if (item > tree->key) {
	    insertRecursive(item, tree->right); // right subtree
	}

	else {
	  cout << "Item already exists" << endl; 
	    return; 
	}
    }
}

template <typename T>
void BinaryTree<T>::deleteItem(T &key) { //delete item method 
    deleteItemRecursive(root, key);
}

template <typename T>
bool BinaryTree<T>::deleteItemRecursive(Node<T>*& node, T key) { //recurive delete item method 
    if(node == nullptr) { // item does not exist
      cout << "\nItem not in tree." << endl; //prints item is not in tree
	
	return false;
    }
	
    else if(key == node->key) {
	    deleteNode(node);

	return true;
    }

    else {
	if(key < node->key)
	    deleteItemRecursive(node->left, key);

	else if(key > node->key)
	    deleteItemRecursive(node->right, key);
    }

    return false;
}

template <typename T>
void BinaryTree<T>::deleteNode(Node<T>*& targetNode) { 
  Node<T>* temp = targetNode;

    // two children
    if(targetNode->left != nullptr && targetNode->right != nullptr) {
        T previousItem = getPrevious(targetNode->left);
	      targetNode->key = previousItem;
	      deleteItemRecursive(targetNode->left, previousItem);
    }
    
    // one child
    else if(targetNode->left != nullptr) {
	    targetNode = targetNode->left;

	delete temp;
    }

    // targetNode has one child
    else if(targetNode->right != nullptr) {
	    targetNode = targetNode->right;

	delete temp;
    }

    // targetNode has no children
    else {
	    targetNode = nullptr;
	    
	    delete temp;
    }
}

template <typename T>
T BinaryTree<T>::getPrevious(Node<T>*& node) const {
    // keep going right until we get to null
    if(node->right == nullptr)
	    return node->key;
    else
    	return getPrevious(node->right);
}

template <typename T>
void BinaryTree<T>::retrieve(T &item, bool& found) const {
    retrieveRecursive(root, item, found);
}

template <typename T>
void BinaryTree<T>::retrieveRecursive(Node<T>* node, T &item, bool& found) const {
    if (node == nullptr) { // item does not exist
	    cout << "Item not in tree.";
	    found = false;
    }
	
    else if (item == node->key) { // item found
	    cout << "Item found in tree.";
	    found = true;
    }
    else {
	if(item < node->key) 
	    retrieveRecursive(node->left, item, found);

	else if(item > node->key) 
	    retrieveRecursive(node->right, item, found);
    }
}

template <typename T>
void BinaryTree<T>::preOrder() const {
    preOrderRecursive(root);
    cout << endl;
}

template <typename T>
void BinaryTree<T>::preOrderRecursive(Node<T>* node) const {
    if (node != nullptr) {
	    cout << node->key << " ";
	    preOrderRecursive(node->left); // traverse the left subtree
	    preOrderRecursive(node->right); // traverse the right subtree
    }
}

template <typename T>
void BinaryTree<T>::inOrder() const {
    inOrderRecursive(root);
    cout << endl;
}

template <typename T>
void BinaryTree<T>::inOrderRecursive(Node<T>* node) const {
    if (node != nullptr) {
	    inOrderRecursive(node->left); // left
	    cout << node->key << " ";
	    inOrderRecursive(node->right); // right
    }
}

template <typename T>
void BinaryTree<T>::postOrder() const {
    postOrderRecursive(root);
    cout << endl;
}

template <typename T>
void BinaryTree<T>::postOrderRecursive(Node<T>* node) const {
    if(node != nullptr) {
	    postOrderRecursive(node->left); // go to left subtree
	
	    postOrderRecursive(node->right); // then the right subtree
	
	    cout << node->key << " "; // and then the node
    }
}

template <typename T>
int BinaryTree<T>::getLength() const {
    return getLengthRecursive(root);
}

template <typename T>
int BinaryTree<T>::getLengthRecursive(Node<T>* node) const {
    if(node == nullptr) {
	    return 0;
    }
    return getLengthRecursive(node->left) + getLengthRecursive(node->right) + 1;
}

template <typename T>
void BinaryTree<T>::getNumSingleParent() {  
  getNumSingleParentRecursive(root);
  cout << count;
  resetCount();
}

template <typename T>
void BinaryTree<T>::getNumSingleParentRecursive(Node<T>* node) {
  if (node == nullptr) {
    return;
  }
    if (((node->left != nullptr) && (node->right == nullptr)) || ((node->left == nullptr) && (node->right != nullptr))) {
      count++;
     }
    getNumSingleParentRecursive(node->left);
    getNumSingleParentRecursive(node->right);

  //getNumSingleParentRecursive(node->left);
  //cout <<"please work " << endl;
  //getNumSingleParentRecursive(node->right); 
}
template<typename T>
void BinaryTree<T>::resetCount() {
  count = 0;
}

template <typename T>
void BinaryTree<T>::getNumLeafNodes() const{
  cout << getNumLeafNodesRecursive(root);
}

template <typename T>
int BinaryTree<T>::getNumLeafNodesRecursive(Node<T>* node) const {
  if (node == nullptr) {
    return 0;
  }
  if (node->left == nullptr && node->right == nullptr) {
    return 1;
  }
  else {
   return  getNumLeafNodesRecursive(node->left) + getNumLeafNodesRecursive(node->right);
  }
}
//template <typename T>
//getSumOfSubtrees;                                                                                                                                                                                                                        

template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<std::string>;
