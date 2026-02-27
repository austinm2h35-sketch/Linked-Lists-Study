// Doubly linked lists can be accessed from either end
//		~ Has head and tail (front and back) pointer
//		~ Can easily access last element
//		~ Both pointers must be adjusted when editing
//		~ Includes TWO links: one to next, one to previous

// Implementation of DoublyLinkedList.h

#include "DoublyLinkedList.h" // Include the header file
#include <iostream> // For cin, cout
using namespace std; // To abbreviate without 'std::'

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------

// Since the class itself doesn't have any nodes when the 
//		list is constructed, the only thing it has is the
//		head and tail pointer; therefore, this is all we need to set

// For all, define with class name and scope resolution :: 
DoublyLinkedList::DoublyLinkedList()
{
	// Set head and tail as null (not pointing to anything)
	head = nullptr;
	tail = nullptr;
}

//----------------------------------------------------------
// Destructor
//----------------------------------------------------------

// For doubly linked lists, we'll still access from the head
//		and loop through to delete each individual node; 
//		however, this time we also need to finish by setting
//		tail to null

DoublyLinkedList::~DoublyLinkedList()
{
	// Create a pointer to loop through and delete
	Node* current;

	// Loop through list until head is null
	while (head != nullptr)
	{
		current = head; // Set current as the head node
		head = head->nextLink; // Set head's link as the next node
		delete current; // Delete the current node
	}

	// When finished, set tail to null for completeness
	tail = nullptr;
}

//----------------------------------------------------------
// Inserting Nodes
//----------------------------------------------------------

// For doubly linked lists, inserting an item keeps the list
//		sorted, since we can check against the next and 
//		previous nodes. As such, there are four cases:
//			1) Insert in an empty list
//			2) Insert at beginning of non-empty list
//			3) Insert in middle of non-empty list
//			4) Insert at end of non-empty list

void DoublyLinkedList::insertNode(char nodeToInsert)
{
	// First, we set up pointers for:
	Node* current = nullptr; // The current node we're on
	Node* beforeCurrent = nullptr; // The node just before current
	Node* newNode = nullptr; // The node we're inserting

	// It'll be easiest, too, to set up a boolean for when the
	//		proper position to insert is found
	bool foundPosition;

	// Now we can initiate the node to be inserted
	newNode = new Node; // Create the node
	newNode->info = nodeToInsert; // Set up data in node
		// Set both pointers to null
	newNode->nextLink = nullptr; 
	newNode->previousLink = nullptr;

	// Test the first case: list is empty
	if (head == nullptr)
	{
		// Set the new node as head AND tail
		head = newNode;
		tail = newNode;
	}

	// If the list isn't empty, test the other three cases
	else
	{
		// Initialize the found variable to false
		foundPosition = false;
		// Set the current to head to start at list beginning
		current = head;

		// Loop through the list until current is null OR 
		//		found is true
		while (current != nullptr &&
			!foundPosition)
		{
			// If the data at current is the >= the 
			//		data to be inserted, we've found
			//		the proper position
			if (current->info >= nodeToInsert)
			{
				foundPosition = true;
			}

			// If not, move on to next node
			else
			{
				// Set current's previous to current
				beforeCurrent = current; 
				// Set current to next
				current = current->nextLink; 
			}

			// We need to account for possibility that the list has
			//		only one node, so deal with that first
			if (current == head)
			{
				// Insert before head by setting head's previous
				//		to the new node
				head->previousLink = newNode;
				// Set newNode's next link to head
				newNode->nextLink = head;
				// Point head to new node
				head = newNode;
			}

			// Otherwise, either we've found the position or we've
			//		reached the end of the list
			else
			{
				// If current is not null, we've found the right 
				//		position, so we insert the node
				if (current != nullptr)
				{
					// Set the current node to the new node
					//		via current's previous
					beforeCurrent->nextLink = newNode;
					// Set up right linkers in newNode
					newNode->previousLink = beforeCurrent;
					newNode->nextLink = current;
					// Set current's previous as new node
					current->previousLink = newNode;
				}

				// If we've made it here, the proper position is 
				//		the end of the list
				else
				{
					// Set the current node to new node 
					//		via current's previous
					beforeCurrent->nextLink = newNode;
					// Set newNode's previous as beforeCurrent
					newNode->previousLink = beforeCurrent;
					// Set the tail to point to the new node
					tail = newNode;
				}

			}

		}

	}

}

//----------------------------------------------------------
// Deleting Nodes
//----------------------------------------------------------

// Deleting uses a very similar structure to inserting,
//		only instead of adding a node, we're removing
//		one. We will still need to adjust the pointers
//		of the surrounding nodes so the list doesn't break.

void DoublyLinkedList::delNode(char itemToDelete)
{
	// Like insertion, set up two pointers and a boolean
	//		(but no need for three pointers, since we're
	//		not adding anything to the list)
	Node* current;
	Node* beforeCurrent;
	bool foundItem;

	// Since deleting from an empty list is impossible,
	//		first do a validation to prevent this
	if (head == nullptr)
	{
		cout << "Cannot delete from an empty list" << endl;
		return;
	}

	// Next, we check to see if the item to delete is the head
	else if (head->info == itemToDelete)
	{
		// Set current to head and head to next
		current = head;
		head = head->nextLink;
		// If head now equals null, we know that there
		//		was only one item in the list
		if (head != nullptr)
		{
			// If that's not the case, delete the
			//		current item by setting head's 
			//		previous link to null
			head->previousLink = nullptr;
		}
		// If it is, set the tail to null to effectively
		//		empty the list
		else
		{
			tail = nullptr;
		}

		// Either way, we can now safely delete the current item
		delete current;
	}

	// Finally, if the list isn't empty and the item to delete
	//		isn't the head, we need to find the item
	else
	{
		// Set found to false and current to head
		foundItem = false;
		current = head;

		// Loop through the list until we've reached the end
		//		or found the item
		while (current != nullptr &&
			!foundItem)
		{
			// Check if the current item matches
			//		item to be deleted
			if (current->info == itemToDelete)
			{
				foundItem = true;
			}

			// If not, move on to next node
			else
			{
				current = current->nextLink;
			}
		}

		// By now, either found is true or current is null
		
		// If the latter, the item isn't in the list
		if (current == nullptr)
		{
			cout << "Item to be deleted is not in the list" << endl;
			return;
		}

		// If item has been found, reset the pointers and delete
		else if (current->info == itemToDelete)
		{
			// Set beforeCurrent to current's previous and
			//		its next to current's next, thus
			//		unlinking current from the list
			beforeCurrent = current->previousLink;
			beforeCurrent->nextLink = current->nextLink;

			// Test if current is the end of the list
			if (current->nextLink != nullptr)
			{
				// If not, unlink current by setting its 
				//		next node's previous link to 
				//		point to beforeCurrent
				current->nextLink->previousLink = beforeCurrent;
			}

			// If current is the tail, reassign tail to beforeCurrent
			if (current == tail)
			{
				tail = beforeCurrent;
			}

			// Now we can safely delete current since it's unlinked
			delete current;

		}

		// Finally, if we've somehow gotten to this point without
		//		having deleted anything, we can print a message
		else
		{
			cout << "Item is not in list" << endl;
			return;
		}		
	}

}

//----------------------------------------------------------
// Displaying the List
//----------------------------------------------------------

// Since doubly linked lists have two pointers, we can 
//		traverse it in either direction. To demonstrate 
//		this, we can set up the print function to take
//		an int as a parameter. If zero,
//		the function will print the list in order; 
//      otherwise, the function will print the list in 
//		reverse order.

void DoublyLinkedList::print(int order)
{
	// Regardless of order, we need to set up
	//		a pointer to traverse the list
	Node* current;

	// Now, test which value is inputted
	if (order == 0)
	{
		// This prints the list forward
		
		// Set the current to head and loop until it's null
		current = head;
		while (current != nullptr)
		{
			// Print each link individually
			cout << current->info << endl;; // Output data
			current = current->nextLink; // Increment current
		}
	}

	// If input is not zero, print the list backwards
	else
	{
		// Instead of head, current is set to tail
		current = tail;
		while (current != nullptr)
		{
			cout << current->info << endl; // Output data
			current = current->previousLink; // Decrement current
		}
	}
}