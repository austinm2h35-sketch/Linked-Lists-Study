#pragma once

// Doubly Linked List Declarations

// Let's set up a doubly linked list class to create and manipulate
// the lists; here, we'll use char instead of int

class DoublyLinkedList
{
	private:
		// Just like for singly linked lists, we need to start
		//		setting up a struct for the nodes

		struct Node
		{
			//Set up data portion
			char info;
			//Set up pointer to next and previous link
			struct Node* nextLink;
			struct Node* previousLink;

			//Note: see SinglyLinkedList.h for explanation on
			//		why the data types for links are self-
			//		referential

		};

		// We need a private head pointer to the first node, but here
		//		we also need a private 'tail' pointer to the last node
		Node* head;
		Node* tail;

		// Public functions
	public:
		DoublyLinkedList(); // Default constructor
		~DoublyLinkedList(); // Destructor
		void insertNode(char); // Function to add a node 
		void delNode(char); // Function to delete a node from list
		void print(int); // Function to print list 
};
