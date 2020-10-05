#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};
class LinkedList {
public:
	Node* head;
	Node* tail;

	LinkedList() {
		head = NULL;
		tail = NULL;
	}

	int Empty() {
		if (head == NULL && tail == NULL)
			return 1;
		else {
			
			return 0;
		}
	}

	void Append(int data) {
		Node* new_node = new Node(data);

		if (Empty()) { // list가 비어있는지 확인하고 비어있다면 head와 tail을설정
			head = new_node;
			tail = new_node;
		}
		else {
			tail->next = new_node; // tail이 가리키는 노드를 변경
			tail = tail->next; // tail node 변경
		}
	}

	void DeleteHead() {
		if (Empty()) {
			cout << "Empty list" << endl;
		}
		else {
			Node* tmp = head;
			if (head->next == NULL) {
				head = NULL;
				tail = NULL;
			}
			else {
				head = head->next;
			}
			delete tmp;
		}
	}

	//void DeleteTail() {
	//	if (Empty()) {
	//		cout << "Empty list" << endl;
	//	}
	//	else {
	//		Node* tmp = head;
	//		while (true) {
	//			if (head == tail) {
	//				delete tmp;
	//				break;
	//			}
	//			else if (tmp->next->next == NULL) {
	//				tail = tmp;

	//				delete tail->next;
	//				break;
	//			}
	//			else {
	//				tmp = tmp->next;
	//			}
	//		}
	//		
	//	}
	//}
};


class L_Queue {
public:
	LinkedList* L;
	int N;
	int capacity;

	L_Queue(int capacity) {
		this->L = new LinkedList();
		this->N = 0;
		this->capacity = capacity;
	};

	void enqueue(int X) {
		if (N >= capacity) {
			cout << "Full" << endl;
		}
		else {
			L->Append(X);
			this->N++;
		}
	}

	int dequeue() {
			int tmp;
			tmp = L->head->data;
			L->DeleteHead();

			this->N--;
			return tmp;
	}

	int size() {
		return this->N;
	}

	int isEmpty() {
		return L->Empty();
	}

	int front() {
		if (isEmpty()) {
			return -1;
		}
		else {
			return L->head->data;
		}
	}

	int rear() {
		if (isEmpty()) {
			return -1;
		}
		else {
			return L->tail->data;
		}
	}
};
int main() {
	
	int S;
	cin >> S;
	L_Queue Q(S);

	int N;
	cin >> N;
	string cmd;

	while (N!=0) {
		N--;
		cin >> cmd;

		if (cmd == "enqueue") {
			int num;
			cin >> num;
			Q.enqueue(num);
		}
		else if (cmd == "dequeue") {
			if (Q.isEmpty()== 1) {
				cout << "Empty" << endl;
			}
			else
				cout << Q.dequeue() << endl;
		}
		else if (cmd == "size") {
			cout << Q.size() << endl;
		}
		else if (cmd == "isEmpty") {
			cout << Q.isEmpty() << endl;
		}
		else if (cmd == "front") {
			if (Q.front() == -1)
				cout << "Empty" << endl;
			else
				cout << Q.front() << endl;;
		}
		else if (cmd == "rear") {
			if (Q.rear() == -1)
				cout << "Empty" << endl;
			else
				cout << Q.rear() << endl;
		}
		else {
			cout << "Your command is wrong, try again." << endl;
		}
	}

	return 0;
}