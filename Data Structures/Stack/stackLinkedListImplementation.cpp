#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node(int value) {
		data = value;
		next = nullptr;
	}
};

class Stack {
private:
	Node* top; // not first and last element
public:
	Stack() {
		top = nullptr;
	}
	bool isEmpty() {
		return !top;
	}
	void push(int x){
		Node* newNode = new Node(x);
		newNode->next = top;
		top = newNode;
	}
	void pop() {
		if (top == NULL) { //isEmpty
			return;
		}
		Node* toDel = top;
		top = top->next;
		delete toDel;
	}
	int peek() {
		if (top == NULL) {
			return -1;
		}
		return top->data;

	}
	int size() {
		if (top == NULL) {
			return -1;
		}
		int count = 0;
		Node* temp = top;
		while (temp) {
			count++;
			temp = temp->next;
		}
		return count;
	}
	void display() {
		if (top == NULL) {
			return;
		}
		Node* temp = top;
		while (temp) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};
int main() {
	Stack stack;

	stack.push(10);
	stack.push(20);
	stack.push(30);

	cout << "Stack elements: ";
	stack.display();

	cout << "Top element is " << stack.peek() << endl;
	stack.pop();

	cout << "Stack elements after pop: ";
	stack.display();
	cout << "Current stack size: " << stack.size() << endl;

	return 0;
}
