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
	void push_back(int element);
	void push_front(int element);
	int size();
	void insert_at(int element, int pos);

	void pop_back();
	void pop_front();
	void remove_at(int pos);

	void print();

	int peek_back();
	int peek_front();

	int get_at(int pos);
	Node* go_to_pos(int pos); //get element at the pos
	int count(int X);  //count how many times is X in the SLL
	int search(int element);//search element- if is there return pos of element, if not -1
	
	void reverse(); 

	void clear(); //delete all elements in the SLL
	void remove_all(int val); //delete all of val in the SLL

	void group(int start_pos, int end_pos);
	bool is_palindrom();

	//Node* mergeLists(Node* head1, Node* head2); //toDO
	Node* middleNode(Node* head);
	int findMergeNode(Node* head1, Node* head2);

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
int SLList::peek_back() {
	if (tail != nullptr) {
		return tail->data;
	}
	//else {
	//	return -1; //depends on the task
	//}
}
int SLList::peek_front() {
	if (head != nullptr) {
		return head->data;
	}
	//else {
	//	return -1; //depends on the task
	//}
}
int SLList::get_at(int pos) {
	int size = this->size();
	if(head ==nullptr){
		return -1;
	}
	if(pos<0 || pos>size){
		return -1;
	}
	Node* node = this->head;
	int counter = 0;
	while (counter < pos) {
		node = node->next;
		counter++;
	}
	return node->data;
}
Node* SLList::go_to_pos(int pos) {
	int size = this->size();
	if (head == nullptr) {
		return;
	}
	if (pos<0 || pos>size) {
		return;
	}
	Node* node = this->head;
	int counter = 0;
	while (counter < pos) {
		node = node->next;
		counter++;
	}
	return node;
}
int SLList::count(int X) {
	Node* node = this->head;
	int counter = 0;
	while (node != nullptr) {
		if (node->data == X) {
			counter++;
		}
		node = node->next;
	}
	return counter;
}
int SLList::search(int element) {
	Node* node = this->head;
	int pos = 0;
	while (node != nullptr) {
		if (node->data == element) {
			return pos;
		}
		pos++;
		node = node->next;
	}
	return -1;
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
Node* removeDuplicates(Node* head) { //in sorted list
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

//
void SLList::group(int start_pos, int end_pos) {
	int size = this->size();
	if (start_pos > end_pos || (start_pos<0 || start_pos>size) || (end_pos<0 || end_pos>size)) {
		cout << "fail_grouping";
		return;
	}
	Node* node = head;
	int sum = 0;
	if (start_pos == 0) {
		for (int i = 0; i <= end_pos; i++) {
			sum += head->data;
			pop_front();
		}
		Node* new_node = new Node(sum);
		new_node->next = head;
		this->head = new_node;
		size++;
		return;
	}
	for (int i = 0; i < start_pos - 1; i++) {
		node = node->next;
	}
	Node* save_link = node;
	node = node->next;
	for (int i = start_pos; i <= end_pos; i++) {
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
	//this->size = this->size - (end_pos - start_pos);
}
bool SLList::is_palindrom() {
	if (this->head == nullptr)
		return true;
	vector<int> palindrom;
	Node* node = this->head;
	while (node != nullptr) {
		palindrom.push_back(node->data);
		node = node->next;
	}
	int l = 0, r = palindrom.size() - 1;
	while (l <= r) {
		if (palindrom[l] != palindrom[r])
			return false;
		l++;
		r--;
	}
	return true;
}
//
/*Node* SLList::mergeLists(Node* head1, Node* head2) {

	SLList* temp = new SLList();
	Node* tempA = head1;
	Node* tempB = head2;
	if (tempA == NULL && tempB == NULL) {
		return NULL;
	}
	if (tempA == nullptr) {
		return tempB;
	}
	if (tempB == nullptr) {
		return tempA;
	}
	while (tempA != nullptr && tempB != nullptr) {

		if (tempA->data < tempB->data) {
			temp->insert_at(tempA->data);
			tempA = tempA->next;
		}
		else {
			temp->insert_at(tempB->data);
			tempB = tempB->next;
		}

	}
	if (tempA != nullptr) {
		while (tempA != nullptr) {
			temp->insert_at(tempA->data);
			tempA = tempA->next;

		}
	}
	if (tempB != nullptr) {
		while (tempB != nullptr) {
			temp->insert_at(tempB->data);
			tempB = tempB->next;
		}
	}

	return temp->head;

}
*/
Node* SLList::middleNode(Node* head) {
	Node* cur = head;
	int size = 0;

	while (cur) {
		size++;
		cur = cur->next;
	}
	int middle = size / 2;

	while (middle--) {
		head = head->next;
	}
	cout << head->data;
}

int SLList::findMergeNode(Node* head1, Node* head2) {
	Node* currentEl1 = head1;
	Node* currentEl2 = head2;
	int size1 = 0;
	int size2 = 0;
	while (currentEl1 != NULL) {
		currentEl1 = currentEl1->next;
		size1++;
	}
	currentEl1 = head1;
	while (currentEl2 != NULL) {
		currentEl2 = currentEl2->next;
		size2++;
	}
	currentEl2 = head2;

	int differenceOfLen = 0;
	if (size1 > size2) {
		differenceOfLen = size1 - size2;
		while (differenceOfLen != 0) {
			currentEl1 = currentEl1->next;
			differenceOfLen--;
		}
	}
	if (size2 > size1) {
		differenceOfLen = size2 - size1;
		while (differenceOfLen != 0) {
			currentEl2 = currentEl2->next;
			differenceOfLen--;
		}
	}
	while (currentEl1 != currentEl2) {
		currentEl1 = currentEl1->next;
		currentEl2 = currentEl2->next;
	}
	return currentEl1->data;
}
void testFunc() {
	SLList list;
	//list.push_front(0);

	//list.push_back(1);
	//list.push_back(2);
	//list.push_back(3);
	//list.push_back(4);

	////list.insert_at(6,2);

	////list.pop_front();
	////list.pop_back();

	

	////list.reverse();

	////list.clear();


	//SLList list2;

	//list2.push_back(1);
	//list2.push_back(2);
	//list2.push_back(2);
	//list2.push_back(4);

	list.push_back(3);
	list.push_back(2);
	list.push_back(1);
	list.push_back(4);

	list.insert_at(5, 3);
	
	list.print();
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	testFunc();

	return 0;
}
