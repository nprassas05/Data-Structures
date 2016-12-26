#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <string>
using namespace std;

struct ListNode {
	int data;
	ListNode* next;
	
	// constructor for an individual node
	ListNode(int d = 0, ListNode* n = NULL) {
		data = d;
		next = n;
	}
};

class LinkedList {
public:
	LinkedList();
	~LinkedList();
	
	void add(int value);
	void clear();
	int get(int index) const;
	void insert(int index, int value);
	bool isEmpty() const;
	void remove(int index);
	void set(int index, int value);
	int size() const;

	//friend ostream& operator <<(ostream& out, LinkedList& list);
private:
	ListNode* front;
};

#endif
