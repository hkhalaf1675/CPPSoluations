// linkedqueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
template<class t>
class linkedQueue {
	struct node {
		t item;
		node* next;
	};
	node* front;
	node* rear;
	int length;
public:
	linkedQueue() {
		front = rear = NULL;
		length = 0;
	}
	bool isEmpty() {
		return length == 0;
	}
	int getSize() {
		return length;
	}
	t getFront() {
		if (isEmpty())
			return NULL;
		else
			return front->item;
	}
	t getRear() {
		if (isEmpty())
			return NULL;
		else
			return rear->item;
	}
	void enqueue(t element) {
		node* newItem = new node;
		newItem->item = element;
		newItem->next = NULL;
		if (isEmpty())
			front = rear = newItem;
		else {
			rear->next = newItem;
			rear = newItem;
		}
		length++;
	}
	void dequeue() {
		if (isEmpty())
			cout << "Queue is empty" << endl;
		else {
			node* temp = front;
			front = front->next;
			delete temp;
			length--;
		}
	}
	void display() {
		if (isEmpty())
			cout << "Queue is empty" << endl;
		else {
			node* temp = front;
			while (temp != NULL) {
				cout << temp->item;
				temp = temp->next;
			}
			cout << endl;
		}
	}


};

int main()
{
	linkedQueue<char> q;
	q.dequeue();
	cout << "Front : " << q.getFront() << endl;
	q.enqueue('H');
	q.enqueue('a');
	q.enqueue('s');
	q.enqueue('s');
	q.enqueue('a');
	q.enqueue('n');
	q.display();
	cout << "Rear : " << q.getRear() << endl;
	cout << "Size : " << q.getSize() << endl;
	cout << "Front : " << q.getFront() << endl;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
