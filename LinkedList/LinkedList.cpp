#include "LinkedList.h"

/* constructor */
LinkedList::LinkedList() {
	front = nullptr;
}

/* Destructor */
LinkedList::~LinkedList() {
	clear();
}

/* append the given value to end of the list */
void LinkedList::add(int value) {
	if (front == nullptr) {
		front = new ListNode(value);
	}
	else {
		ListNode* current = front;
		while (current -> next != nullptr) {
			current = current -> next;
		}
		current -> next = new ListNode(value);
	}
}

// set a new value for a node at a particular index
void LinkedList::set(int index, int value) {
	ListNode* current = front;
    for (int i = 0; i < index; i++) {
		current = current -> next;
	}
	
	current -> data = value;
}

// get a value at a particular index		
int LinkedList::get(int index) const {
	ListNode* current = front;
    for (int i = 0; i < index; i++) {
		current = current -> next;
	}
	
	return current -> data;
}

/* Insert a new node at a given index */
void LinkedList::insert(int index, int value) {
	if (index == 0) {
		ListNode* temp = front;
		front = new ListNode(value);
		front -> next = temp;
		delete temp;
	}
	else {
		ListNode* current = front;
		for (int i = 0; i < index - 1; i++) {
			current = current -> next;
		}
		// insert a new node after current node
		ListNode* newNode = new ListNode(value);
		newNode -> next = current -> next;
		current -> next = newNode;
	}
}

void LinkedList::remove(int index) {
	ListNode* temp;
	if (index == 0) {
		temp = front;
		front = front -> next;
		delete temp;
	}
	else {
		ListNode* current = front;
		for (int i = 0; i < index - 1; i++) {
			current = current -> next;
		}
		// remove the node
		temp = current -> next;
		current -> next = temp -> next;
		delete temp;
	}	
}
/* Check if the list has zero elements or not */
bool LinkedList::isEmpty() const {
	return front == nullptr;
}

void LinkedList::clear() {
	/* keep deleting first node in the list until
	   there are none left to delete
	*/
	while (!isEmpty()) {
		remove(0);
	}
}