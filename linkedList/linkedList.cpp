// linkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
using namespace std;
template<class t>
class linkedlist {
	struct node {
		t item;
		node* next;
	};
	node* head;
	node* tail;
	int length;
public:
	linkedlist() {
		head = tail = NULL;
		length = 0;
	}
	bool isEmpty() {
		return length == 0;
	}
	int getSize() {
		return length;
	}
	t getHead() {
		if (isEmpty())
			return NULL;
		else
			return head->item;
	}
	t getTail() {
		if (isEmpty())
			return NULL;
		else
			return tail->item;
	}
	void display() {
		if (isEmpty())
			cout << "List IS Empty" << endl;
		else {
			node* temp = head;
			while (temp != NULL) {
				cout << temp->item;
				temp = temp->next;
			}
			cout << endl;
		}
	}
	void insertAtFirst(t element) {
		node* newItem = new node;
		newItem->item = element;
		if (isEmpty()) {
			newItem->next = NULL;
			head = tail = newItem;
		}
		else {
			newItem->next = head;
			head = newItem;
		}
		length++;
	}
	void insertAtLast(t element) {
		node* newItem = new node;
		newItem->item = element;
		newItem->next = NULL;
		if (isEmpty()) {
			head = tail = newItem;
		}
		else {
			tail->next = newItem;
			tail = newItem;
		}
		length++;
	}
	void insertAtPos(int pos, t element) {
		if (pos<0 || pos>length)
			cout << "Out Of Range" << endl;
		else {
			if (pos == 0)
				insertAtFirst(element);
			else if (pos == length)
				insertAtLast(element);
			else {
				node* newItem = new node;
				newItem->item = element;
				node* prv = head;
				node* cur = head->next;
				for (int i = 1; i < pos; i++) {
					prv = cur;
					cur = cur->next;
				}
				newItem->next = cur;
				prv->next = newItem;
			}
			length++;
		}
	}
	void removeFirst() {
		if (isEmpty())
			cout << "List IS Empty To Remove" << endl;
		else {
			node* temp = head;
			head = head->next;
			delete temp;
			length--;
		}
	}
	void removeLast() {
		if (isEmpty())
			cout << "List IS Empty To Remove" << endl;
		else {
			node* temp = head->next;
			node* prv = head;
			while (temp != tail) {
				prv = temp;
				temp = temp->next;
			}
			prv->next = NULL;
			tail = prv;
			delete temp;
			length--;
		}
	}
};

int main()
{
	linkedlist<char> l;
	cout << "Head : " << l.getHead() << endl;
	cout << "Tail : " << l.getTail() << endl;
	cout << "Size : " << l.getSize() << endl;
	l.insertAtFirst('n');
	l.insertAtFirst('a');
	l.insertAtFirst('s');
	l.insertAtFirst('s');
	l.insertAtFirst('a');
	l.insertAtFirst('H');
	l.insertAtLast(' ');
	l.insertAtLast('K');
	l.insertAtLast('h');
	l.insertAtPos(0, 'N');
	l.insertAtPos(1, ' ');
	l.insertAtPos(2, ':');
	l.insertAtPos(3, ' ');
	l.insertAtPos(13, 'a');
	l.display();
	cout << "Size : " << l.getSize() << endl;
	l.removeLast();
	l.display();
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
