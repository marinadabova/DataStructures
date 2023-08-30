//Doubly Linked List

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
struct Node {
	int data;
	Node* prev;
	Node* next;
	Node() {
		this->data = 0;
		this->prev = nullptr;
		this->next = nullptr;
	}
	Node(int value) {
		this->data = value;
		this->prev = nullptr;
		this->next = nullptr;
	}
};
class DLList {
private:
	Node* head;
	Node* tail;
public:
	DLList() {
		this->head = nullptr;
		this->tail = nullptr;
	}
	Node* getHead() const {
		return head;
	}
	void setHead(Node* newHead) {
		head = newHead;
	}
	void push_back(int value);
	void push_front(int value);
	int size();
	void add_after(int value, int pos);
	void insert_at(int value, int pos);

	void pop_back();
	void pop_front();
	void remove_at(int pos);
	//void delete_duplicates(int value);//vs sreshtaniq
	//Node* deleteDuplicatesSorted(Node* head); // sortiran trqbva da e // 111233456 - 123456
	//Node* deleteDuplicatesSorted3(Node* head); // sortiran trqbva da e // 111233456 - 123456 - uj po-dobyr na gorniq

	//Node* deleteDuplicatesSorted2(Node* head); // sortiran trqbva da e // trie si gi   111233456- 2456
	void clear();
	Node* deleteDuplicatesUnsorted(Node* head);
	void print();
	
};
void DLList::push_back(int value) {
	if (tail == nullptr) {
		head = new Node(value);
		tail = head;
		return;
	}
	else {
		Node* newNode = new Node(value);
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}
void DLList::push_front(int value) {
	if (head == nullptr) {
		head = new Node(value);
		tail = head;
		return;
	}
	else {
		Node* newNode = new Node(value);
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
}
int DLList::size() {
	int size = 0;
	Node* node = this->head;
	while (node != nullptr) {
		size++;
		node = node->next;
	}
	return size;
}
void DLList::pop_back() {
	if (tail == nullptr) {
		return;
	}
	if (head == tail) {
		delete head;
		head = nullptr;
		tail = nullptr;
		return;
	}
	else {
		Node* toDel = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete toDel;

		/*
		 Node *newTail = tail->previous;
		delete tail;
		tail = newTail;

		if (tail == nullptr)
			head = nullptr;
		else
			tail->next = nullptr;
		*/
	}
}
void DLList::pop_front() {
	if (head == nullptr) {
		return;
	}
	if (head == tail) {
		delete head;
		head = nullptr;
		tail = nullptr;
		return;
	}
	else {
		Node* toDel = head;
		head = head->next;
		head->prev = nullptr;
		delete toDel;
	}
}
/*
void DLList::delete_duplicates(int value) {//vs sreshtaniq na value
	if (head == nullptr) {
		return;
	}
	Node* node = head;
	int pos = 0;
	while (node->next != nullptr) {
		node = node->next;
		if (node->prev->data == value) {
			remove_at(pos);
			pos--;
		}
		pos++;
	}
}
Node* DLList::deleteDuplicatesSorted(Node* head) { //1 1 1 2 3 -> 1 2 3
	if (head == nullptr) {
		return NULL;
	}
	Node* cur = head;

	while (cur->next != nullptr) {
		if (cur->data == cur->next->data) {
			cur->next = cur->next->next;
		}
		else {
			cur = cur->next;
		}
	}
	return head;
}
//better aproach
Node* DLList::deleteDuplicatesSorted3(Node* head) {
	if (head == nullptr) {
		return nullptr;
	}

	Node* cur = head;

	while (cur->next != nullptr) {
		if (cur->data == cur->next->data) {
			Node* duplicate = cur->next;
			cur->next = cur->next->next;

			if (cur->next != nullptr) {
				cur->next->prev = cur; // Update the next node's prev pointer
			}

			// Properly deallocate memory if necessary
			delete duplicate;
		} else {
			cur = cur->next;
		}
	}

	// Handle the last node if it's a duplicate
	if (head->next != nullptr && head->data == head->next->data) {
		Node* duplicate = head;
		head = head->next;
		head->prev = nullptr; // Update the new head's prev pointer

		// Properly deallocate memory if necessary
		delete duplicate;
	}

	return head;
}


Node* DLList::deleteDuplicatesSorted2(Node* head) { //1,2,3,3,4,4,5] -> Output: [1, 2, 5]
	if (!head || !head->next) {
		return head;
	}

	Node* dummy = new Node(0); // Create a dummy node to handle edge cases
	dummy->next = head;
	head->prev = dummy;

	Node* prev = dummy;
	Node* curr = head;

	while (curr) {
		bool hasDuplicates = false;
		while (curr->next && curr->data == curr->next->data) {
			hasDuplicates = true;
			curr = curr->next;
		}

		if (hasDuplicates) {
			prev->next = curr->next;
			if (curr->next) {
				curr->next->prev = prev;
			}
		}
		else {
			prev = curr;
		}

		curr = curr->next;
	}

	head = dummy->next;
	head->prev = nullptr; // Update the new head's prev pointer

	delete dummy;

	return head;
}
*/
void DLList::print() {
	if (head == nullptr) {
		return;
	}
	Node* node = head;
	while (node != nullptr) {
		cout << node->data << " ";
		node = node->next;
	}
	cout << "\n"; //
}
Node* DLList::deleteDuplicatesUnsorted(Node* head) {
	if (head == nullptr) {
		return nullptr;
	}

	unordered_map<int, int> cnt;
	Node* cur = head;

	// Count the frequency of each value in the linked list
	while (cur != nullptr) {
		cnt[cur->data]++;
		cur = cur->next;
	}

	Node* temp = new Node(0);
	temp->next = head;
	head->prev = temp;

	Node* prev = temp;
	cur = head;

	// Delete nodes with values that appear more than once
	while (cur != nullptr) {
		if (cnt[cur->data] > 1) {
			prev->next = cur->next;
			if (cur->next != nullptr) {
				cur->next->prev = prev;
			}
			Node* toDelete = cur;
			cur = cur->next;
			delete toDelete;
		}
		else {
			prev = cur;
			cur = cur->next;
		}
	}

	return temp->next;
}
void testFunc() {
	DLList list;
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
	DLList modifiedList; // Create a new list to store the modified version
	modifiedList.setHead(deleted); // Set the modified head
	modifiedList.print(); // Print modified list

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	testFunc();

	return 0;
}
