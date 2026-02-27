#pragma once

// Singly Linked List Declarations

// Let's set up a singly linked list class to create and manipulate
// the lists

class SinglyLinkedList
{
	private:
		// First, a private data structure for the node is needed
		// Here, we'll create a list whose nodes hold ints

		struct ListNode
		{
			//Set up data portion
			int info;
			//Set up pointer to next link
			struct ListNode* link;

			//Note: Since a linked list is a 'self-referential data
			//		structure', each node must point to another node
			//		of the same type; for that reason, the link's
			//		data type must be the same data type as the node
			//		itself (hence 'struct ListNode' before *link). BUT,
			//		if you leave out the * which makes it a pointer, you
			//		will get infinite recursion!

		};

		// We also need a pointer to act as the head
		ListNode *head;

	// Public functions
	public:
		SinglyLinkedList(); // Default constructor
		~SinglyLinkedList(); // Destructor
		void appendNode(int); // Function to add a node to head
		void deleteNode(int); // Function to delete a node from list
		void printList(); // Function to print list 
};

