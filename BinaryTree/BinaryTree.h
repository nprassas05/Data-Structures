#ifndef BINARYTREE_H
#define BINARYTREE_H

struct Node
{
	int data;
	Node *left;
	Node *right;
};

class BinaryTree
{
private:
	Node *root;
	void destroy(Node *tempNode);
	void insert(int value, Node *&tempNode);
	bool search(int value, Node *tempNode);
	void traverseInOrder(Node *tempNode);
	void traversePreOrder(Node *tempNode);
	void traversePostOrder(Node *tempNode);
    int minFinder(Node *tempNode);
    void remove(Node*& node, int value);
public:
	BinaryTree();
	~BinaryTree();
	void insertNode(int value);
	bool searchNode(int value);
	void displayInOrder();
	void displayPreOrder();
	void displayPostOrder();
	int countNodes(Node*);
	int nodeCount();
	int countLeaves(Node*);
	int leafCount();
    int getMin();
    void removeNode(int value);
};

#endif

