#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main()
{
	BinaryTree tree;
	tree.insertNode(31);
	tree.insertNode(7);
	tree.insertNode(59);
	tree.insertNode(19);
	tree.insertNode(43);

	tree.displayInOrder();

	int numNodes = tree.nodeCount();
	cout << "\nNumber of nodes in the tree: " << numNodes << endl;

	int numLeaves = tree.leafCount();
	cout << "Number of leaf nodes in the tree: " << numLeaves << endl;


	return 0;
}
