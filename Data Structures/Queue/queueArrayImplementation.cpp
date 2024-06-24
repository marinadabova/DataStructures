#include <iostream>
#include <cstdlib>
using namespace std;

class Queue {
private:
	int* arr;
	int front;
	int last;
	int capacity;
	int count;
public:
	Queue(int size=10)	{
		arr = new int[size];
		capacity = size;
		front = 0;
		last = -1;
		count = 0;
	}
	~Queue() {
		delete[] arr;
	}

	void dequeue() {
		if (isEmpty()) {
			return ;
		}
		front = (front + 1) % capacity;
		count--;
	}
	void enqueue(int x) {
		if (isFull()) {
			
			return;
		}


		last = (last + 1) % capacity;
		arr[last] = x;
		count++;
	}
	int peekFront() {
		if (isEmpty()) {
			return -1;
		}
		return arr[front];
	}
	int peekBack() {
		if (isEmpty()) {
			return -1;
		}
		return arr[last];
	}
	int size() {
		return count;
	}
	bool isEmpty() {
		return (count == 0);
	}
	bool isFull() {
		return (count == capacity);
	}
};
int main() {
	Queue q(5);

	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);

	cout << "Front element is: " << q.peekFront() << endl;
	cout << "Rear element is: " << q.peekBack() << endl;

	q.dequeue();
	q.enqueue(6);

	cout << "Queue size is " << q.size() << endl;

	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue(); // Try to dequeue from an empty queue

	if (q.isEmpty()) {
		cout << "Queue is empty\n";
	}
	else {
		cout << "Queue is not empty\n";
	}

	return 0;
}
