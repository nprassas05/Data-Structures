#include "BinaryTree.h"
#include <iostream>
using namespace std;

BinaryTree::BinaryTree()
{
	root = NULL;
}

BinaryTree::~BinaryTree()
{
	destroy(root);
}

void BinaryTree::destroy(Node *tempNode)
{
	if (tempNode)
	{
		destroy(tempNode->left);
		destroy(tempNode->right);
		delete tempNode;
	}
}

void BinaryTree::insertNode(int value)
{
	insert(value, root);
}

void BinaryTree::insert(int value, Node *&tempNode)
{
	if (tempNode == NULL) // base case
	{
		Node *newNode = new Node;
		newNode->data = value;
		newNode->left = NULL;
		newNode->right = NULL;
		tempNode = newNode;
	}
	else if (value < tempNode->data)
		insert(value, tempNode->left);
	else
		insert(value, tempNode->right);
}

bool BinaryTree::searchNode(int value)
{
	return search(value, root);
}

bool BinaryTree::search(int value, Node *tempNode)
{
	if (tempNode == NULL)
		return false;
	if (value == tempNode->data)
		return true;
	else if (value < tempNode->data)
		return search(value, tempNode->left);
	else
		return search(value, tempNode->right);
}

void BinaryTree::displayInOrder()
{
	traverseInOrder(root);
}

void BinaryTree::traverseInOrder(Node *tempNode)
{
	if (tempNode)
	{
		traverseInOrder(tempNode->left); //left
		cout << tempNode->data << " ";
		traverseInOrder(tempNode->right); //right
	}
}

void BinaryTree::displayPreOrder()
{
	traversePreOrder(root);
}

void BinaryTree::traversePreOrder(Node *tempNode)
{
	if (tempNode)
	{
		cout << tempNode->data;
		traversePreOrder(tempNode->left); //left
		traversePreOrder(tempNode->right); //right
	}
}

void BinaryTree::displayPostOrder()
{
	traversePostOrder(root);
}

void BinaryTree::traversePostOrder(Node *tempNode)
{
	if (tempNode)
	{
		traversePostOrder(tempNode->left); //left
		traversePostOrder(tempNode->right); //right
		cout << tempNode->data;
	}
}

int BinaryTree::countNodes(Node* tempNode)
{
	if (tempNode)
	{
		return 1 + countNodes(tempNode->left) + countNodes(tempNode->right);
	}
	else
		return 0;
}

int BinaryTree::nodeCount()
{
	return countNodes(root);
}

int BinaryTree::countLeaves(Node* temp)
{
	if (!temp)
		return 0;

	if (temp->left == NULL && temp->right == NULL)
		return 1;
	else
		return 0 + countLeaves(temp->left) + countLeaves(temp->right);
}

int BinaryTree::leafCount()
{
	return countLeaves(root);
}

int BinaryTree::minFinder(Node* temp)
{
    if (temp -> left == nullptr) {
        return temp -> data;
    }
    else {
        return minFinder(temp -> left);
    }
}

int BinaryTree::getMin()
{
    if (root)
        return minFinder(root);
    else
        throw "Empty tree";
}

// remove helper function
void BinaryTree::remove(Node*& node, int value) {
    if (node == nullptr) {
        
    }
    else if (value < node -> data) {
        remove(node -> left, value);
    }
    else if (value > node -> data) {
        remove(node -> right, value);
    }
    else {
        Node* trash = nullptr;
        if (node -> left == nullptr && node -> right == nullptr) {
            trash = node;
            node = nullptr;
        }
        else if (node -> left == nullptr) {
            trash = node;
            node = node -> right;
        }
        else if (node -> right == nullptr) {
            trash = node;
            node = node -> right;
        }
        else {
            int newData = minFinder(node -> right);
            node -> data = newData;
            remove(node -> right, newData);
        }
        if (trash != nullptr) {
            delete trash;
        }
            
    }
        
}

// remove a node from the tree
void BinaryTree::removeNode(int value) {
    remove(root, value);
}