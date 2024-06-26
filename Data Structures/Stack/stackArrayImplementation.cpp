#include <iostream>
#define MAX 1000

using namespace std;
class Stack {
private:
	int top;
public:
	int arr[MAX];
	Stack() {
		top = -1;
	}
	void push(int x){
		if (top >= (MAX - 1)) {
			return;
		}
		else {
			top++;
			arr[top] = x;
		}
	}
	int pop() {
		if (top == -1){
			return -1;
		}
		int toDel = arr[top];
		top--;
		return toDel;
	}
	int peek() {
		if (top == -1) {
			return -1;
		}
		else {
			return arr[top];
		}
	}
	int size() {
		return top + 1;
	}
	bool isEmpty() {
		return (top < 0);
	}
	void display() {
		if (top == -1) {
			return;
		}
		for (int i = top; i >= 0; i--) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};
int main() {

	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	cout << s.pop() << " Popped from stack\n";
	cout << "Top element is " << s.peek() << endl;
	cout << "Stack size is " << s.size() << endl;
	cout << "Stack elements: ";
	s.display();
	return 0;
}
