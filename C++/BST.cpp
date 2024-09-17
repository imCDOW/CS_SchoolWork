#include <iostream>
using namespace std;
#include "binarySearchTree.h"
#include "binaryTree.h"

//Add a function treeLeavesCount, which returns the number of leaves in the binary tree by using a recursive algorithm, to the class binaryTreeType provided (binaryTree.h). Ask the user to enter a list of positive integers ending with -999, build a binary search tree using the positive integers, and display the tree contents after doing inorder, preorder, and postorder traversals.

int main()
{
  int num = 0;
  bSearchTreeType<int> BST;
  
  while (true)
  {
    cout << "\nPlease enter a positive integer. Please enter -999 to quit: ";
    cin >> num;
    if (num == -999) break; // Exit loop if -999
    BST.insert(num);
  }

  cout << "\nYour tree has" << BST.treeLeavesCount() << " leaves." << endl; //print total leaf count
  
  cout << "\nYour tree with in-order traversal is: " << endl;
  BST.inorderTraversal(); // Print tree w/ in-order traversal

  cout << "\nYour tree with pre-order traversal is: " << endl;
  BST.preorderTraversal(); // Print tree w/ pre-order traversal

  cout << "\nYour tree with post-order traversal is: " << endl;
  BST.postorderTraversal(); // Print tree w/ post-order traversal
};
