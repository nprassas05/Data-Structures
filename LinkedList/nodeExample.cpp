#include <iostream>
#include "ListNode.h"
using namespace std;


int main()
{
	// create listNodes and link them together
	ListNode* node1 = new ListNode();
	node1 -> data = 42;

	node1 -> next = new ListNode();
	node1 -> next -> data  = -3;
	node1 -> next -> next = new ListNode();	

	node1 -> next -> next -> data = 99;
	node1 -> next -> next -> next = NULL;

	ListNode* temp = node1;
	while (temp != NULL) {
		cout << temp -> data << endl;
		temp = temp -> next;
	}

	return 0;
}
