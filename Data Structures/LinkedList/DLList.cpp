//Doubly Linked List

#include <bits/stdc++.h>
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
	void delete_duplicates(int value);//vs sreshtaniq
	void clear();

	bool search_element(int value);
	int count_element(int value);
	int peek_back();
	int peek_front();

	void print();
	void reverse();
	Node* reverse2(Node* head);
	Node* reverse3();

	void reverse_first_half();
	void group(int start, int end);
	void group2(int start, int end);
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
void DLList::add_after(int value, int pos) { //if the pos is outside list-insert back
	int size = this->size();
	if (pos < 0) {
		return;
	}
	if (pos == 0) {
		push_front(value);
		return;
	}
	if (pos >= size) {
		push_back(value);
		return;
	}
	else {
		Node* node = this->head;
		int counter = 0;
		//while (counter != pos )// if i want to instert after certain pos
		while (counter != pos - 1) { //!//here we do not have prev like SLList - the Node have in itself prev pointer thats why is pos-1- we want prev pos
			node = node->next;
			counter++;
		}
		Node* newNode = new Node(value);
		newNode->next = node->next;
		newNode->prev = node;
		node->next->prev = newNode;
		node->next = newNode;
	}
}
void DLList::insert_at(int value, int pos) { 
	if (pos < 0) {
		return;
	}
	if (pos == 0) {
		push_front(value);
		return;
	}
	Node* cur = head;
	int index = 0;
	while (index != pos - 1) {
		cur = cur->next;
		index++;
	}
	if (cur == nullptr) {
		return;
	}
	Node* newNode = new Node(value);
	newNode->next = cur->next;
	if (cur->next != nullptr) {
		cur->next->prev = newNode;
	}
	cur->next = newNode;
	newNode->prev = cur;
	if (newNode->next == nullptr) {
		tail = newNode;
	}
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
void DLList::remove_at(int pos) {
	int size = this->size();
	if (pos < 0 || pos >= size) {
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
	else {
		Node* cur = head;
		int counter = 0;
		while (counter != pos - 1) {
			cur = cur->next;
			counter++;
		}
		if (cur->next == nullptr) {
			return;
		}
		Node* toDel = cur->next;
		cur->next = toDel->next;
		toDel->next->prev = cur;
		delete toDel;
	}
}

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
void DLList::clear() { //free
	Node* node = head;
	while (node != nullptr) {
		Node* next = node->next;
		delete node;
		node = next;
	}
	head = nullptr;
	tail = nullptr;

}

bool DLList::search_element(int value) {
	Node* node = head;
	while (node != nullptr) {
		if (node->data == value) {
			return true;
		}
		node = node->next;
	}
	return false;
}
int DLList::count_element(int value) {
	int counter = 0;
	Node* node = head;
	while (node != nullptr) {
		if (node->data == value) {
			counter++;
		}
		node = node->next;
	}
	return counter;
}
int DLList::peek_back() {
	if (tail == nullptr) {
		return -1;
	}
	return tail->data;
}
int DLList::peek_front() {
	if (head == nullptr) {
		return -1;
	}
	return head->data;
}

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
void DLList::reverse() {
	if (head == nullptr) {
		return;
	}
	Node* cur = head;
	Node* next = nullptr;
	while (cur != nullptr) {
		next = cur->next;
		cur->next = cur->prev;
		cur->prev = next;
		cur = next;
	}
	cur = head;
	head = tail;
	tail = cur;
}
Node* DLList::reverse2(Node* head) {
	if (head == nullptr) {
		return head;
	}
	Node* cur = head;
	Node* next = nullptr;
	while (cur != nullptr) {
		next = cur->next;
		cur->next = cur->prev;
		cur->prev = next;
		head = cur;
		cur = next;
	}
	
	return head;
}
Node* DLList::reverse3() {
	if (head == nullptr) {
		return head;
	}
	Node* cur = head;
	Node* next = nullptr;
	while (cur != nullptr) {
		next = cur->next;
		cur->next = cur->prev;
		cur->prev = next;
		head = cur;
		cur = next;
	}

	return head;
}
/*Node* Reverse(Node* head)
{
    if(head == NULL)
        return head;
    Node* cur = head;
    Node* temp;
    while(cur != NULL)
    {
        temp = cur->next;
        cur->next = cur->prev;
        cur->prev = temp;
        if(temp == NULL)
            head = cur;
        cur = temp;
    }
    return head;
}*/

void DLList::reverse_first_half() {
	int size = this->size();
	int N;
	if (size % 2 == 0) {
		N = size / 2;
	}
	else {
		N = (size - 1) / 2;
	}
	Node* node = head;
	int count = 0;
	while (count != N - 1) {
		node = node->next;
		count++;
	}
	Node* secondHalf = node->next;
	node->next = nullptr;

	Node* prevNode = nullptr;
	Node* cur = head;
	Node* nextNode = nullptr;
	while (cur != nullptr) {
		nextNode = cur->next;
		cur->next = prevNode;
		prevNode = cur;
		cur = nextNode;
	}

	head = prevNode;
	cur = head;
	
	while (cur->next != nullptr) {
		cur = cur->next;
	}
	cur->next = secondHalf;
}
void DLList::group(int start, int end) {
	int size = this->size();
	if (start > end || (start<0 || start>size) || (end<0 || end>size)) {
		cout << "Error";
		return;
	}
	Node* startNode = head;
	Node* endNode = head;
	for (int i = 0; i < start; i++) {
		startNode = startNode->next;
	}
	for (int i = 0; i < end; i++) {
		endNode = endNode->next;
	}
	int sum = 0;
	Node* cur = startNode;
	while (cur != endNode->next) {
		sum += cur->data;
		cur = cur->next;
	}
	startNode->data = sum;
	cur = startNode->next;
	while (cur != endNode) {
		Node* toDel = cur;
		cur = cur->next;
		delete toDel;
	}
	startNode->next = endNode->next;
	if (endNode->next != nullptr) {
		endNode->next->prev = startNode;
	}
	if (endNode == tail) {
		tail = startNode;
	}
	delete endNode;
}
void DLList::group2(int start, int end) {
	int size = this->size();
	if (start > end || (start<0 || start>size) || (end<0 || end>size)) {
		cout << "Error";
		return;
	}
	Node* node = head;
	int sum = 0;
	if (start == 0) {
		for (int i = 0; i <= end; i++) {
			sum += head->data;
			pop_front();
		}
		Node* new_node = new Node(sum);
		new_node->next = head;
		this->head = new_node;
		return;
	}
	for (int i = 0; i < start - 1; i++) {
		node = node->next;
	}
	Node* save_link = node;
	node = node->next;
	for (int i = start; i <= end; i++) {
		sum += node->data;
		Node* temp = node;
		node = node->next;
		delete temp;
	}
	Node* grouped_node = new Node(sum);
	save_link->next = grouped_node;
	if (node != nullptr)
		grouped_node->next = node;
	if (node == nullptr)
		this->tail = grouped_node;
}




void test() {
	DLList list;

	list.push_front(1);
	list.push_back(5);
	list.insert_at(4, 1);
	list.insert_at(19, 2);
	//list.print();

	DLList l;
	l.push_back(1);
	l.push_back(1);
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	l.push_back(6);

	//l.add_after(3, 1);
	//l.insert_at(3, 2);
	l.print();
	l.delete_duplicates(1);
	l.print();
	//reverse -variants
	//l.reverse();

	//reverse2 v:
	//Node* currentHead = l.getHead();//get head
	//Node* reversedHead = l.reverse2(currentHead);// Reverse the list
	//l.setHead(reversedHead);// Set the new reversed head

	//l.reverse3(); // if in the scope there is not head
	
	//l.print();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	test();

	return 0;
}
