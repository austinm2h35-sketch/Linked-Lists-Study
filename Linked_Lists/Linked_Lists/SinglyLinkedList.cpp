// Singly linked lists can only be accessed from one direction
//		~ Only pointer is the head, to the front of the list
//		~ Cannot work backwards easily
//		~ Cannot easily access last element
//

// Implementation of SinglyLinkedList.h

#include "SinglyLinkedList.h" // Include the header file
#include <iostream> // For cin, cout
using namespace std; // To abbreviate without 'std::'

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------

// Since the class itself doesn't have any nodes when the 
//		list is constructed, the only thing it has is the
//		head pointer; therefore, this is all we need to set

// For all, define with class name and scope resolution :: 
SinglyLinkedList::SinglyLinkedList()
{
	// Set head as null (not pointing to anything)
	head = nullptr;
}


//----------------------------------------------------------
// Destructor
//----------------------------------------------------------

// Since we're working with pointers, we need a way to 
//		explicitly clean up memory, so we include a destructor.
//
// Singly linked lists can only be accessed from the head, so 
//		to delete all elements, we need to loop through the
//		list and delete each node individually.


SinglyLinkedList::~SinglyLinkedList()
{
	// Start by declaring two pointers to loop through the list:
	//		one for the current node and one for the next
	ListNode *currentNode, *nextNode;

	// We want to start at the beginning of the list, so 
	//		assign currentNode to the head
	currentNode = head;

	//From here, we can loop through using 'while' to test
	//		when the current node (the head) is null 
	//		(i.e., the list is empty).
	while (currentNode != nullptr)
	{
		// Assign the nextNode to the address of the current
		//		node, so that we can safely delete the current
		//		without losing our place in the list
		nextNode = currentNode->link;
		// Delete the current node
		delete currentNode;
		// Move forward in the list by overwriting the currentNode
		//		as the next node. (Despite appearances, this is merely
		//		using the pointer variable itself, not utilizing deleted
		//		memory; because of this, we can assign currentNode a new
		//		value despite having deleted it above)
		currentNode = nextNode;

		// Loop will stop when nextNode (now current node) 
		//		is the end of the list
	}
}

//----------------------------------------------------------
// Appending Nodes
//----------------------------------------------------------

// Appending a node will add the node to the end of the list.
//
// Process is as follows:
//		~ Create a new node
//		~ Store data in the node
//		~ Add node to either beginning (if empty) or end

void SinglyLinkedList::appendNode(int nodeData)
{
	// Assign variable for the new node and a pointer to current
	ListNode *newNode, *currentNode;

	// Initialize new node and store nodeData as the
	//		info in newNode, then set its pointer to
	//		null
	newNode = new ListNode;
	newNode->info = nodeData;
	newNode->link = nullptr;

	// Check if there are any nodes in the list ('!head' means
	//		'if head is null')
	if (!head)
	{
		// If so, have head point to the new node
		head = newNode;
	}
	// Otherwise, insert at end by looping through list
	else
	{
		// Start at the beginning of the list
		currentNode = head;

		// Loop while the current node's link is not null
		while (currentNode->link)
		{
			// Reset current node to the next node
			currentNode = currentNode->link;
		}

		// Since loop stops at end of the list, use 
		//		currentNode as indicator of end and 
		//		set its link to the newNode (inserts
		//		newNode after currentNode)
		currentNode->link = newNode;
	}
}

//----------------------------------------------------------
// Deleting Nodes
//----------------------------------------------------------

// To delete a node from the list, we need to traverse
//		the list until we find the node to delete, then
//		relink the surrounding nodes so that the list
//		does not break due to the deletion.

void SinglyLinkedList::deleteNode(int infoToDelete)
{
	// Establish pointers to the current and previous nodes;
	//		initialize both to null
	ListNode *currentNode, *previousNode;
	currentNode = nullptr;
	previousNode = nullptr;

	// Check if the list is empty; if so, there's nothing to 
	//		delete, so just return
	if (!head)
	{
		return;
	}

	// If the list isn't empty, we'll check if the node
	//		to delete is the first one
	if (head->info == infoToDelete)
	{
		// If so, set the current node to the head's address
		currentNode = head->link;
		// Delete the head node
		delete head;
		// Reassign head to the current node so that it still exists
		head = currentNode;
	}

	// If not, we still need to find the node to delete
	else
	{
		// First, initialize the current node to the head so we
		//		can traverse the list
		currentNode = head;

		// Skip past all nodes that don't need to be deleted
		while (currentNode != nullptr &&
			currentNode->info != infoToDelete)
		{
			// Set previous node to the current node
			previousNode = currentNode;
			// Move the current node's address forward
			currentNode = currentNode->link;
		}

		// This leaves us with either the correct spot or the 
		//		end of the list (if item wasn't found). Check
		//		for the latter case first.
		if (currentNode == nullptr)
		{
			// Print message that node does not exist, and return
			cout << "Node to delete was not found in list" << endl;
			return;
		}
		// Otherwise, link the previous node to the node after
		//		the current, then delete the current
		previousNode->link = currentNode->link;
		delete currentNode;
	}
}

//----------------------------------------------------------
// Displaying the List
//----------------------------------------------------------

// To print the list, simply traverse it as we have before
//		and print each element to the out stream
void SinglyLinkedList::printList()
{
	// First, check if the list is empty
	if (!head)
	{
		cout << "There is nothing to print" << endl;
	}
	// If not, set up a traversal pointer and loop
	else
	{
		// Current pointer set to head
		ListNode *currentNode;
		currentNode = head;
		// Loop through while currentNode is not null
		while (currentNode)
		{
			// Print the data at current and move to next line
			cout << currentNode->info << endl;
			// Move current to the next node
			currentNode = currentNode->link;
		}
	}
}
