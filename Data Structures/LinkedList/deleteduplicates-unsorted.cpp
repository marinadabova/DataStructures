//SinglyLinkedList -https://github.com/doocs/leetcode/blob/main/solution/1800-1899/1836.Remove%20Duplicates%20From%20an%20Unsorted%20Linked%20List/README_EN.md
#include <bits/stdc++.h>
#include <unordered_map>
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
	void insert_at(int element, int pos);

	void pop_back();
	void pop_front();
	void remove_at(int pos);

	void print();

	
	void reverse();

	void clear(); //delete all elements in the SLL
	void remove_all(int val); //delete all of val in the SLL
	//Node* removeDuplicates(Node* head); //removing without specific given value in function
	
	Node* deleteDuplicatesUnsorted(Node* head);
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

void SLList::insert_at(int element, int pos) {
	int size = this->size();
	if (pos <0 || pos>size) {
		return;
	}
	if (pos == 0) {
		push_front(element);
		return;
	}
	if (pos == size) {
		push_back(element);
		return;
	}
	else {
		Node* prev = nullptr;
		Node* node = this->head;
		int counter = 0;
		while (counter < pos) {
			prev = node;
			node = node->next;
			counter++;
		}
		Node* toAdd = new Node(element);
		toAdd->next = node;
		prev->next = toAdd;
		/*if (this->tail == prev) {
			this->tail = toAdd;
		}*/
	}
}
/*void insert_at_pos(int value, int position) {
	int size = 0;
	size = this->size();
	if (position == 0) {
		push_front(value);
		return;
	}
	if (position < 0 || position >= size) {
		return;
	}

	//ako se iska da se dobavi sled size-a
	if (position >= size) {
		push_back(value);

	}
	//
	Node* prev = nullptr;
	prev = this->head;
	int index = 0;
	while (index != position - 1) {
		prev = prev->next;
		index++;
	}
	Node* newNode = new Node(value);

	newNode->next = prev->next;//!

	prev->next = newNode;
	if (this->tail == prev) {
		this->tail = newNode;
	}

}*/
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
void SLList::remove_at(int pos) {
	int size = this->size();
	if (pos<0 || pos>size) {
		return;
	}
	if (pos == 0) {
		pop_front();
		return;
	}
	if (pos == size - 1) {
		pop_back();
		return;
	}
	Node* node = this->head;
	Node* prev = nullptr;
	int counter = 0;
	while (counter < pos) {
		prev = node;
		node = node->next;
		counter++;
	}
	prev->next = node->next;
	/*if (tail == node) {
		tail = prev;
	}*/
	delete node;
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
void SLList::clear() {
	Node* node = this->head;
	while (node != nullptr) {
		Node* toDel = node;
		node = node->next;
		delete toDel;
	}
	this->head = nullptr;
	this->tail = nullptr;
}
void SLList::remove_all(int val) {
	Node* node = this->head;
	Node* prev = nullptr;
	int counter = 0;
	while (node != nullptr) {
		prev = node;
		node = node->next;
		if (prev->data == val) {
			remove_at(counter);
			counter--;
		}
		counter++;
	}

}
//Node* SLList::removeDuplicates(Node* head) {
//	if (head == nullptr) {
//		return NULL;
//	}
//	Node* cur = head;
//
//	while (cur->next != nullptr) {
//		if (cur->data == cur->next->data) {
//			cur->next = cur->next->next;
//		}
//		else {
//			cur = cur->next;
//		}
//	}
//	return head;
//}
//Node* removeDuplicates(Node* head) { //in sorted list
//	if (head == nullptr) {
//		return NULL;
//	}
//	Node* cur = head;
//
//	while (cur->next != nullptr) {
//		if (cur->data == cur->next->data) {
//			cur->next = cur->next->next;
//		}
//		else {
//			cur = cur->next;
//		}
//	}
//	return head;
//}
//Node* deleteDuplicates(Node* head) { // premahva si gi 1123345 -> 245
//	if (head == nullptr || head->next == nullptr) {
//		return head;
//	}
//	Node* temp = new Node(0);
//	temp->next = head;//dobavq v nachaloto
//	//head->prev=temp; //DLList
//	Node* prev = temp;
//	Node* cur = head;
//	while (cur != nullptr) {
//		bool isDuplicated = false;
//		while (cur->next != nullptr && cur->data == cur->next->data) {
//			isDuplicated = true;
//			cur = cur->next;
//		}
//		if (isDuplicated == true) {
//			prev->next = cur->next;
//
//		}
//		else {
//			prev = prev->next;
//		}
//		cur = cur->next;
//	}
//	head = temp->next;
//	delete temp;
//
//	return head;
//}
//

Node* SLList::deleteDuplicatesUnsorted(Node* head) {
	if (head == nullptr) {
		return NULL;
	}
	unordered_map<int, int> cnt;
	Node* cur = head;
	while(cur!=nullptr){
		cnt[cur->data]++;
		cur = cur->next;
	}
	Node* temp = new Node(0);
	temp->next = head;
	Node* prev = temp;
	cur = head;
	while (cur != nullptr) {
		if (cnt[cur->data] > 1) {
			prev->next = cur->next;
			Node* toDelete = cur;
			cur = cur->next;
			delete toDelete; // Delete the node with duplicate value
		}
		else {
			prev = cur;
			cur = cur->next;
		}
	}

	return temp->next;
	
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
	Node* deleted = list.deleteDuplicatesUnsorted(curHead);
	SLList modifiedList; // Create a new list to store the modified version
	modifiedList.setHead(deleted); // Set the modified head
	modifiedList.print(); // Print modified list
	//list.print();
	////list.insert_at(6,2);
	//list.print();

	////list.pop_front();
	////list.pop_back();



	////list.reverse();

	////list.clear();


	//SLList list2;

	//list2.push_back(1);
	//list2.push_back(2);
	//list2.push_back(2);
	//list2.push_back(4);

	/*list.push_back(3);
	list.push_back(2);
	list.push_back(1);
	list.push_back(4);

	list.insert_at(5, 3);

	list.print();*/
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	testFunc();

	return 0;
}
