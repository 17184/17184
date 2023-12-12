#include <iostream>
#include <algorithm>
#include "bst.h"

int main()
{
	BST<int> tree;
	tree.insert(30);
	tree.insert(20);
	tree.insert(10);
	tree.insert(5);
	std::cout << "Inorder traverse - ";
	tree.inorderTraverse();
	std::cout << "\nPreorder Traverse - ";
	tree.preorderTraverse();
	std::cout << "\nPostorder Traverse - ";
	tree.postorderTraveerse();
}
