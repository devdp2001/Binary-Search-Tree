#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <istream>

#include "BinaryTree.h"
#include "BinaryTree.cpp"

using namespace std;

//function prototype for reading the input file
template <typename T>
void readFile(BinaryTree<T>& tree, char* filename);

//function prototype for running the main interface
template <typename T>
void runInterface(BinaryTree<T>& tree, string type);

int main(int argc, char* argv[]) {

  // while loop that asks for list type and runs the function prototypes above accordingly
  bool startLoop = true;
  string inputType = "";
  
  while (startLoop) {
    cout << "Enter list type (i - int, f - float, s - std:string): ";
    getline(cin, inputType);
	
    cout << endl;

    if (inputType.compare("i") == 0) { //int
      BinaryTree<int> tree;

      readFile(tree, argv[1]);
      runInterface(tree, "Int");
      startLoop = false;
    }

    else if(inputType.compare("f") == 0) { //float
      BinaryTree<float> tree;
		    
      readFile(tree, argv[1]);
      runInterface(tree, "Float");
      startLoop = false;
    }

    else if(inputType.compare("s") == 0) { //std::string
      BinaryTree<string> tree;

      readFile(tree, argv[1]);
      runInterface(tree, "String");
      startLoop = false;
    }

    else { //invalid command found
      cout << "Invalid command, try again!" << endl;  
      cout << endl;
    }
  }
    
  return 0;
}

//function for reading the input file
template <typename T>
void readFile(BinaryTree<T>& tree, char* filename) {
  fstream fs;
    
  fs.open(filename, fstream::in);
	
  T inputValue;
  if(fs.is_open()) {
    fs >> inputValue;
	
    while(!fs.eof()) {
      tree.insert(inputValue);
      fs >> inputValue;
    }

    fs.close();
  }
  else {
    cout << "Failed to open the input file" << endl;
    exit(1);
  }
}

//function for running the interface
template <typename T>
void runInterface(BinaryTree<T>& tree, string type) {
  //all command options available to user
  cout << "insert (i), delete (d), retrieve (r), length (l), in-order (n), pre-order (p), post-order (o), getNumSingleParent  (s), getNumLeafNodes (f), getSumOfSubtrees (t), quit (q)" << endl;
  cout << endl;
    
  bool loop = true;
  char command;

  //while loop for main prgram
  while(loop) {
    cout << "Enter a command: ";
    cin >> command;
 
    switch(command) {
    case 'i': { //insert item
      T item;

      cout << "Item to insert: ";
      cin >> item;

      tree.insert(item);
      
      cout << "In-Order: ";
      tree.inOrder();
      cout << endl;
	    
      break;
    }	    
    case 'd': { //delete item
      T item;

      cout << "Item to delete: ";
      cin >> item;

      tree.deleteItem(item);

      cout << endl;
      cout << "In-Order: ";
      tree.inOrder();
      cout << endl;
	    
      break;
    }
    case 'r': { //retrieve item
      T item;
      bool found = false;
      
      cout << "Item to be retrieved: ";
      cin >> item;

      tree.retrieve(item, found);
      cout << endl;
      
      break;
    }
    case 'l': { //length
      cout << "Tree Length: " << tree.getLength() << endl;
      cout << endl;
	    
      break;
    }
    case 'n': { //In-Order
      cout << "In-Order: ";
      tree.inOrder();
      cout << "\n" << endl;
	    
      break;
    }
    case 'p': { //Pre-Order
      cout << "Pre-Order: ";
      tree.preOrder();
      cout << "\n" <<  endl;

      break;
    }
    case 'o': { //Post-Order
      cout << "Post-Order: ";
      tree.postOrder();
      cout << "\n"  << endl;

      break;
    }
    case 's': { //getNumSingleParent
      cout << "Number of Single Parents: ";
      tree.getNumSingleParent();
      cout << endl;      

      break;
    }
    case 'f': { //getNumLeafNodes
      cout << "Number of leaf nodes: ";
      tree.getNumLeafNodes();
      cout << endl;
      
      break;
    }
    case 't': { //getSumOfSubtrees
      break;
    }
    case 'q': { //quit
      cout << "Quitting program..." << endl;
      cout << endl;
      loop = false;
      
      break;
    }
    default: //inavlid command
      cout << "Invalid command, try again!" << endl;	  
      cout << endl;
	    
      break;
    }
  }
}
