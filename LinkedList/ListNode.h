#ifndef LISTNODE_H
#define LISTNODE_H

/* define a list node structure */
/* each node will hold one integer of data and 
   a pointer to another node 
*/

struct ListNode {
	int data;
	ListNode* next;   
};

#endif
