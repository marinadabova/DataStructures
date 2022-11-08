#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next;

	Node(int value) {
		this->data = value;
		next = nullptr;
	}
};

class SLList {
private:
	Node* head;
	Node* tail;
public:
	SLList() {
		this->head = NULL;
		this->tail = NULL;

	}
	void push_back(int value) {
		Node* newNode = new Node(value);

		if (!tail) {
			head = tail = newNode;
			return;
		}

		this->tail->next = newNode;
		this->tail = newNode;
	}

	void push_front(int value) {
		Node* newNode = new Node(value);

		if (!head) {
			head = tail = newNode;
			return;
		}

		newNode->next = head;
		this->head = newNode;
	}
	int size() {
		int size = 0;
		Node* current = nullptr;
		current = this->head;
		while (current) {
			size++;
			current = current->next;
		}
		return size;
	}
	void insert_at_pos(int value, int position) {
		int size = 0;
		size = this->size();
		if (position == 0) {
			push_front(value);
			return;
		}
		if (position < 0 || position >= size) {
			return;
		}
		/*
		ako se iska da se dobavi sled size-a
		if (position >= size) {
			push_back(value);

		}
		*/
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

	}

	void pop_front() {
		if (!head) {
			return;
		}
		if (this->head == this->tail) {
			delete this->head;
			this->head = nullptr;
			this->tail = nullptr;
			return;
		}
		Node* newHead = this->head->next;
		delete this->head;
		head = newHead;
	}
	void pop_back() {
		if (!head) {
			return;
		}
		if (this->head == this->tail) {
			delete this->head;
			this->head = nullptr;
			this->tail = nullptr;
			return;
		}
		Node* newTail = this->head;
		Node* curr = this->head->next;
		while (curr != this->tail) {
			curr = curr->next;
			newTail = newTail->next;
		}
		delete this->tail;
		this->tail = newTail;
		this->tail->next = nullptr;
	}
	void remove_at_pos(int position) {
		int size = 0;
		size = this->size();
		if (position < 0 || position >= size) {
			return;
		}
		if (position == 0) {
			pop_front();
			return;
		}
		if (position == size - 1) {
			pop_back();
			return;
		}
		Node* prev = this->head;
		int index = 0;
		while (index != position - 1) {
			prev = prev->next;
			index++;
		}
		if (prev->next == nullptr) {
			return;
		}
		Node* toDelete = prev->next;
		prev->next = toDelete->next;
		delete toDelete;


		if (this->tail == nullptr) {
			this->tail = prev;
		}

	}
	int peek_front() {
		return head->data;
	}

	int peek_back() {
		return tail->data;
	}
	int get_element_at_pos(int position) {
		int size = this->size();
		if (position < 0 || position >= size) {
			return -1;
		}
		int currPos = 0;
		Node* curr = this->head;
		while (currPos != position) {
			curr = curr->next;
			currPos++;
		}
		return curr->data;
	}
	/*Node* goToPosition(int position) {
		int currentPosition = 0;
		Node* currentNode = head;
		while (currentPosition < position) {
			currentNode = currentNode->next;
			currentPosition++;
		}

		return currentNode;
	}*/
	void reverse() {
		Node* prev = NULL;
		Node* cur = head;
		Node* next = NULL;
		while (cur != nullptr) {
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		this->head = prev;
	}
	void clear() {
		Node* cur = this->head;
		while (cur != nullptr) {
			Node* toDelete = cur;
			cur = cur->next;
			delete toDelete;
		}
		this->head = nullptr;
		this->tail = nullptr;

	}

	void printList() {
		Node* curr;
		curr = head;
		while (curr != nullptr) {
			cout << curr->data << " ";
			curr = curr->next;

		}
	}
	int count_element(int value) {//broi broq na srehstaniqta na element v spisuka
		int counter = 0;
		Node* temp = head;

		while (temp) {
			if (temp->data == value)
				counter++;

			temp = temp->next;

		}
		return counter;
	}
	bool search_element(int value) {// vrushta true ako se sreshta elementa
		Node* temp = head;
		while (temp->data != value && temp->next != NULL) {

			temp = temp->next;
		}
		if (temp->data != value)
			return false;

		return true;
	}
	void print(Node* head)
	{
		Node* t = head;
		while (t != NULL)
		{
			cout << t->data << endl;
			t = t->next;
		}
	}
	void reversePrint(Node* llist) {
		if (llist == nullptr) {
			return;
		}
		Node* curr = llist;
		Node* pv = NULL;

		while (curr != nullptr) {
			Node* temp = new Node(curr->data);
			temp->next = pv;
			pv = temp;
			curr = curr->next;
		}
		print(pv);

	}
	int size(Node* head) {
		Node* cur = head;
		int size = 0;
		while (cur) {
			size++;
			cur = cur->next;
		}
		return size;
	}
	bool compare_lists(Node* head1, Node* head2) {
		Node* list1 = head1;
		Node* list2 = head2;

		int size1 = size(head1);
		int size2 = size(head2);
		bool i = false;
		if (size1 != size2) {
			return 0;
		}
		else {
			while (list1 != nullptr && list2 != nullptr) {
				if (list1->data == list2->data)
					i = true;
				else {
					i = false;
					break;
				}
				list1 = list1->next;
				list2 = list2->next;
			}
		}
		return i;

	}

	void insert_node(int node_data) {
		Node* node = new Node(node_data);

		if (!this->head) {
			this->head = node;
		}
		else {
			this->tail->next = node;
		}

		this->tail = node;
	}
	Node* mergeLists(Node* head1, Node* head2) {

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
				temp->insert_node(tempA->data);
				tempA = tempA->next;
			}
			else {
				temp->insert_node(tempB->data);
				tempB = tempB->next;
			}

		}
		if (tempA != nullptr) {
			while (tempA != nullptr) {
				temp->insert_node(tempA->data);
				tempA = tempA->next;

			}
		}
		if (tempB != nullptr) {
			while (tempB != nullptr) {
				temp->insert_node(tempB->data);
				tempB = tempB->next;
			}
		}

		return temp->head;

	}
	int getNode(int positionFromTail) {
		Node* ptr = head;
		Node* ptr2 = ptr;

		for (int i = 0; i < positionFromTail; i++)
			ptr2 = ptr2->next;

		while (ptr2->next != nullptr)
		{
			ptr = ptr->next;
			ptr2 = ptr2->next;
		}

		return ptr->data;

	}
	Node* removeDuplicates(Node* llist) {
		if (llist == nullptr) {
			return NULL;
		}
		Node* cur = llist;

		while (cur->next != nullptr) {
			if (cur->data == cur->next->data) {
				cur->next = cur->next->next;
			}
			else {
				cur = cur->next;
			}
		}
		return llist;
	}
};

void testFunc() {
	SLList list;
	//list.push_front(0);

	//list.push_back(1);
	//list.push_back(2);
	//list.push_back(3);
	//list.push_back(4);

	////list.insert_at_pos(6,2);

	////list.pop_front();
	////list.pop_back();
	////list.remove_at_pos(2);

	//list.printList();
	//cout << endl;

	////cout << list.get_element_at_pos(2) << endl;

	////list.reverse();

	////list.clear();

	////list.printList();
	//SLList list2;

	//list2.push_back(1);
	//list2.push_back(2);
	//list2.push_back(2);
	//list2.push_back(4);

	//cout << list2.count_element(2);

	//cout << list2.search_element(3);
	list.push_back(3);
	list.push_back(2);
	list.push_back(1);
	list.push_back(4);
	cout << list.getNode(2);

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	testFunc();

	return 0;
}