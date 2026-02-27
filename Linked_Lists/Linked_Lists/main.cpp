
// This is the driver program to see both SinglyLinkedList
//		and DoublyLinkedList in action. 

#include "SinglyLinkedList.h" // Include singly linked list header
#include "DoublyLinkedList.h" // Include doubly linked list header
#include <iostream> // For cin, cout
using namespace std; // To abbreviate
 
int main()
{
	// Welcome message
	cout << "Welcome to the Linked Lists program!" << endl;

	// Constructor tests
	SinglyLinkedList singleList;
	DoublyLinkedList doubleList;

	// Start by adding elements to each list

	// SinglyLinkedList class takes ints
	singleList.appendNode(1);
	singleList.appendNode(2);
	singleList.appendNode(5);
	singleList.appendNode(7);

	// DoublyLinkedList class takes chars
	//		Notice order of insertion!
	doubleList.insertNode('a');
	doubleList.insertNode('z');
	doubleList.insertNode('m');
	doubleList.insertNode('j');

	// Now we'll print the lists to show that adding worked

	// For singly linked list, we can only print in order
	cout << "Singly linked list after inserting 1, 2, 5, 7: " << endl;
	singleList.printList();
	cout << endl;

	// For double list, we'll print in both ways
	cout << "Doubly linked list after inserting a, z, m, j: " << endl;
	cout << "First print: In Forward Order: " << endl;
	doubleList.print(0);
	cout << endl;
	cout << "Second print: In Reverse Order: " << endl;
	doubleList.print(1);
	cout << endl;

	// From here we can test the delete function
	singleList.deleteNode(2);
	doubleList.delNode('m');

	// Print again to show deletion worked
	cout << "Singly linked list after deleting 2: " << endl;
	singleList.printList();
	cout << endl;
	cout << "Doubly linked list after deleting m: " << endl;
	doubleList.print(0);
	cout << endl;

	cout << "End of Linked List Program" << endl;


}