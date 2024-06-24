#include <iostream>
#include <cstdlib>
using namespace std;

// 5 6 3 1
//front 5 last 1 q.pop() ->5 FIFO

struct Node {
	int data;
	Node* next;
	
	Node(int value) {
		data = value;
		next = nullptr;
	}
};
class Queue {
private:
	Node* front;
	Node* last;
public:
	Queue() {
		front = nullptr;
		last = nullptr;
	}
	bool isEmpty() {
		return front == nullptr;
	}
	void enqueue(int val) { // insert at the end
		Node* newNode = new Node(val);
		if (isEmpty()) {
			front = last = newNode;
		}
		else {
			last->next = newNode;
			last = newNode;
		}
	}
	void dequeue() { // delete at front
		if (isEmpty()) {
			return;
		}
		
			Node* toDel = front;
			front = front->next;
			delete toDel;
			if (front == nullptr) {
				last = nullptr; // Update rear if queue becomes empty
			}
	}
	int peekFront() { // get front element
		if (isEmpty()) {
			return -1;
		}
		return front->data;
	}
	int peekBack() {
		if (isEmpty()) {
			return -1;
		}
		return last->data;
	}

	int size() {
		Node* temp = front;
		int s = 0;
		if (front==nullptr ) {
			return -1;
		}
		while (temp) {
			s++;
			temp = temp->next;
		}
		return s;
	}

};
int main() {
	Queue q;

	q.enqueue(5);
	q.enqueue(6);
	q.enqueue(3);
	q.enqueue(1);

	cout << "Front element: " << q.peekFront() << endl;
	cout << "Back element: " << q.peekBack() << endl;

	q.dequeue();

	cout << "Front element after dequeue: " << q.peekFront() << endl;
	cout << "Queue size: " << q.size() << endl;
	return 0;
}
