#include <bits/stdc++.h>
using namespace std;
struct Node {
	int value;
	struct Node* next;
	struct Node* prev;
	Node(int value) {
		this->value = value;
		next = nullptr;
		prev = nullptr;
	}

};
class DLList {
private:
	Node* head;
	Node* tail;
public:
	void push_front(int value) {
		Node* newNode = new Node(value);
		if (head == nullptr) { //nqma elementi
			head = tail = newNode;

			return;
		}
		newNode->next = head;
		head->prev = newNode;
		head = newNode;

	}
	void push_back(int value) {
		Node* newNode = new Node(value);

		if (tail == nullptr) {
			head = newNode;
			tail = head;
			return;
		}
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
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
		Node* newNode = new Node(value);

		if (position == 0) {
			push_front(value);
			return;
		}
		if (position < 0 || position >= size) {
			return;
		}
		Node* currentEL = head;
		int index = 0;
		while (index != position - 1) {
			currentEL = currentEL->next;
			index++;
		}
		newNode->next = currentEL->next;
		currentEL->next = newNode;

	}
	void add_after(int value, int position) {
		//dobavq element na tochna poziciq c spisuka kato ako poziciqta e
		//izvun spisuka go dobavq v kraq
		int size = 0;
		Node* curr = head;
		while (curr) {
			size++;
			curr = curr->next;
		}
		Node* newNode = new Node(value);
		if (position < 0) {
			return;
		}

		if (position == 0) {
			push_front(value);
			return;
		}
		if (position >= size) {
			push_back(value);
			return;
		}
		Node* currentEL = head;
		int index = 0;
		while (index != position - 1) {
			currentEL = currentEL->next;
			index++;
		}
		newNode->next = currentEL->next;
		currentEL->next = newNode;
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
		Node* toDel = this->head;
		Node* newHead = this->head->next;
		delete toDel;
		head->prev = nullptr;
		this->head = newHead;
	}
	void pop_back() {
		if (!tail) {
			return;
		}
		if (this->head == this->tail) {
			delete this->head;
			this->head = nullptr;
			this->tail = nullptr;
			return;
		}
		Node* newTail = tail->prev;
		delete this->tail;
		newTail->next = nullptr;
		this->tail = newTail;


	}
	void remove_at_pos(int position) {
		int size = this->size();
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

	}
	void delete_duplicates(int value) {
		if (!head || !head->next) {
			return;
		}
		Node* curr = this->head;
		Node* next = this->head;
		while (curr && curr->next) {
			next = curr->next;
			if (curr->value == next->value) {
				curr->next = next->next;
			}
			else {
				curr = curr->next;
			}
		}

	}
	void deleteNode( Node* head,  Node* toDel)
	{
		if (!head || !toDel) {
			return;
		}

		if (head == toDel) {
			head = toDel->next;
		}
		if (toDel->next != NULL)
			toDel->next->prev = toDel->prev;

		/* Change prev only if node to be deleted
		   is NOT the first node */
		if (toDel->prev != NULL)
			toDel->prev->next = toDel->next;

		/* Finally, free the memory occupied by del*/
		free(toDel);
	}
	void delete_element(int value) {
		// iztriva vs sreshtaniq

		if (!head) {
			return;
		}

		Node* cur = head;
		Node* next = head;
		while (cur) {
			if (cur->value == value) {
				next = cur->next;

				deleteNode(head, cur);
				cur = next;
			}
			else {
				cur = cur->next;
			}
		}

	}
	bool search_element(int value) {// vrushta true ako se sreshta elementa
		Node* temp = head;
		while (temp->value != value && temp->next != NULL) {

			temp = temp->next;
		}
		if (temp->value != value)
			return false;

		return true;
	}
	int count_element(int value) {//broi broq na srehstaniqta na element v spisuka
		int counter = 0;
		Node* temp = head;

		while (temp) {
			if (temp->value == value)
				counter++;

			temp = temp->next;

		}
		return counter;
	}
	void reverse() {
		int size = this->size();
		if (size == 2) {
			swap(head->value, head->next->value);
			return;
		}

		Node* forward = head;
		Node* backward = tail;

		int currentPosition = 0;

		while (currentPosition < size / 2) {
			swap(forward->value, backward->value);
			forward = forward->next;
			backward = backward->prev;
			currentPosition++;
		}
	}

	int peek_front() {
		return head->value;
	}

	int peek_back() {
		return tail->value;
	}
	void reverse_first_half() {
		//obrushta reda na purvata polovina na elementite v spisuka
		//ako elementite sa necheten br N br elementite v purvata polovina shte e (N-1)/2

		int size = this->size();
		int N = 0;
		if (size % 2 == 0) {
			N = size;

		}
		else {
			N = (size - 1) / 2;
		}
		///
		Node* temp = head;
		int count = 1;
		while (count < N) {
			temp = temp->next;
			count++;
		}

		// backup the joint point
		Node* joint_point = temp->next;
		temp->next = NULL; // break the list

		// reverse the list till break point
		Node* prev = NULL;
		Node* current = head;
		Node* next;
		while (current != NULL) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}

		// join both parts of the linked list
		// traverse the list until NULL is not
		// found
		head = prev;
		current = head;
		while (current->next != NULL)
			current = current->next;

		// joint both part of the list
		current->next = joint_point;


	}
	void group(int start_pos, int end_pos) {
		//sumira elementite mejdu podadenite dve posiziii vkluchitelno rqh i gi zamestva v spisuka sus sumata im
		//primer
		//pri spisuk 1 2 3 4 5 6 7 8 9 i group(2,4) 
		//poluchavame spisuk 1 2 12 6 7 8 9
		//ako poziciite ne sa validni operaciqta ne se izpulnqva a na standartniq izhod se printira error
		if (!head) {
			return;
		}
		int size = this->size();
		if (start_pos < 0 || start_pos >= size) {
			return;
		}
		if (end_pos < 0 || end_pos >= size) {
			return;
		}
		Node* cur = head;
		int index = 0;
		while (index < start_pos) {
			index++;
			cur = cur->next;
		}
		int sum = 0;
		while (end_pos-1) {
			sum += cur->value;
			cur = cur->next;
			deleteNode(head, cur);
		}



	}
	void display() {
		Node* ptr;
		ptr = head;
		while (ptr != NULL) {
			cout << ptr->value << " ";
			ptr = ptr->next;
		}
	}

	DLList() {
		head = NULL;
		tail = NULL;

	}

};


void test() {
	DLList list;

	/*list.push_front(1);
	list.push_back(5);
	list.add_after(4, 1);
	list.add_after(19, 2);
	list.add_after(2, 0);

	list.display();
	cout << endl;
	cout<<list.search_element(6);
	*/
	DLList list1;
	list1.push_back(1);
	list1.push_back(2);
	list1.push_back(2);
	list1.push_back(3);
	list1.push_back(2);
	list1.push_back(4);
	list1.push_back(2);
	list1.display();
	cout << endl;

	DLList list2;
	list2.push_back(1);
	list2.push_back(2);
	list2.push_back(3);
	list2.push_back(4);
	list2.push_back(5);
	list2.push_back(6);
	list2.push_back(7);
	list2.push_back(8);
	list2.push_back(9);


	//list2.pop_front();
	//list2.pop_back();
	//list2.remove_at_pos(2);
	//list1.delete_element(2);

	//list1.reverse_first_half();

	list1.display();

	cout << endl;
	//cout << list1.count_element(2);

	list2.group(2, 4);
	list2.display();

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	test();


	return 0;
}