//https://leetcode.com/problems/sort-list/submissions/
//SinglyLinkedList
#include <bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	Node* next;
	Node() {
		this->data = 0;
		this->next = nullptr;
	}
	Node(int value) {
		this->data = value;
		this->next = nullptr;
	}

};
class SLList {
private:
	Node* head;
	Node* tail;
public:
	SLList() {
		this->head = nullptr;
		this->tail = nullptr;
	}
	Node* getHead()const {
		return head;
	}
	void setHead(Node* newHead) {
		head = newHead;
	}

	void push_back(int element);
	void push_front(int element);
	int size();

	void pop_back();
	void pop_front();

	void print();

	void reverse();

	Node* sortList(Node* head);
};
void SLList::push_back(int element) {
	if (this->head == nullptr) {

		this->head = new Node(element);
		this->tail = this->head;
	}
	else {
		this->tail->next = new Node(element);
		this->tail = this->tail->next;
	}
}
void SLList::push_front(int element) {
	if (this->head == nullptr) {
		this->head = new Node(element);
		this->tail = this->head;
	}
	else {
		Node* node = new Node(element);
		node->next = this->head;
		this->head = node;
	}
}
int SLList::size() {
	int size = 0;
	Node* cur = this->head;
	while (cur != nullptr) {
		size++;
		cur = cur->next;
	}
	return size;
}

void SLList::pop_back() {
	if (this->head == nullptr) {
		return;
	}
	if (this->head == this->tail) {
		delete this->head;
		this->head = nullptr;
		this->tail = this->head;
		return;
	}
	else {
		Node* node = this->head;
		Node* prev = nullptr;
		while (node->next != nullptr) { //!
			prev = node;
			node = node->next;
		}
		delete node;
		if (prev != nullptr) {
			prev->next = nullptr;
		}
		this->tail = prev;
	}
}
void SLList::pop_front() {
	if (this->head == nullptr) {
		return;
	}
	if (this->head == this->tail) {
		delete this->head;
		this->head = nullptr;
		this->tail = this->head;
		return;
	}
	else {
		Node* node = this->head;
		this->head = this->head->next;
		delete node;
	}
}

void SLList::print() {
	if (head == nullptr) {
		return;
	}
	Node* node = this->head;
	while (node != nullptr) {
		cout << node->data << " ";
		node = node->next;
	}
	cout << '\n';
}

void SLList::reverse() {
	Node* prev = nullptr;
	Node* cur = head;
	Node* next = nullptr;
	while (cur != nullptr) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	this->head = prev;
}


Node* merge(Node* a, Node* b) {

	if (a == nullptr)
		return b;
	if (b == nullptr)
		return a;

	Node* result = nullptr;
	if (a->data >= b->data) {
		result = a;
		result->next = merge(a->next, b);
	}
	else {
		result = b;
		result->next = merge(a, b->next);
	}
	return result;
}

Node* merge_sort(Node* head) {

	if (head == nullptr || head->next == nullptr)
		return head;

	Node* slow = head;
	Node* fast = head->next;

	while (fast != nullptr && fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
	}

	Node* second = slow->next;
	slow->next = NULL;

	Node* left = merge_sort(head);
	Node* right = merge_sort(second);

	return merge(right, left);

}
Node* SLList::sortList(Node* head) {
	return merge_sort(head);
}
void testFunc() {
	SLList list;
	//list.push_front(0);
	list.push_back(1);
	list.push_back(3);
	list.push_back(2);

	list.push_back(5);
	list.push_back(4);
	list.push_back(1);

	list.print();

	Node* curHead = list.getHead();
	Node* sorted = list.sortList(curHead);
	SLList modifiedList; // Create a new list to store the modified version
	modifiedList.setHead(sorted); // Set the modified head
	modifiedList.print(); // Print modified list

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	testFunc();

	return 0;
}
