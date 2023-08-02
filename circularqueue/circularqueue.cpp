// circularqueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
const int maxSize = 10;
template <class t>
class circularQueue {
	int front;
	int rear;
	int length;
	t arr[maxSize];
public:
	circularQueue() {
		front = 0;
		rear = maxSize - 1;
		length = 0;
	}
	bool isEmpty() {
		return length == 0;
	}
	bool isFull() {
		return length == maxSize;
	}
	int getSize() {
		return length;
	}
	t getFront() {
		if (isEmpty())
			cout << "Queue is empty" << endl;
		else
			return arr[front];
	}
	t getRear() {
		if (isEmpty())
			cout << "Queue is empty" << endl;
		else
			return arr[rear];
	}
	void enqueue(t element) {
		if (isFull())
			cout << "Queue is Full" << endl;
		else {
			rear = (rear + 1) % maxSize;
			arr[rear] = element;
			length++;
		}
	}
	void dequeue() {
		if (isEmpty())
			cout << "Queue is empty" << endl;
		else {
			front = (front + 1) % maxSize;
			length--;
		}
	}
	void display() {
		if (isEmpty())
			cout << "Queue is empty" << endl;
		else {
			int temp = front;
			while (temp != rear) {
				cout << arr[temp];
				temp = (temp + 1) % maxSize;
			}
			cout << arr[rear];
			cout << endl;
		}
	}
};

int main()
{
	circularQueue<char> q;
	cout << q.getFront() << endl;
	cout << "----------------------------" << endl;
	cout << q.getRear() << endl;
	cout << "----------------------------" << endl;
	cout << q.getSize() << endl;
	cout << "----------------------------" << endl;
	q.enqueue('s');
	q.enqueue('H');
	q.enqueue('a');
	q.enqueue('s');
	q.enqueue('s');
	q.enqueue('a');
	q.enqueue('n');
	q.display();
	cout << "----------------------------" << endl;
	q.dequeue();
	q.display();
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
