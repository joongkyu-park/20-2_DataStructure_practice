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

		if (Empty()) { // list�� ����ִ��� Ȯ���ϰ� ����ִٸ� head�� tail������
			head = new_node;
			tail = new_node;
		}
		else {
			tail->next = new_node; // tail�� ����Ű�� ��带 ����
			tail = tail->next; // tail node ����
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

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		L_Queue p1(N);
		L_Queue p2(N);
		int tmp = N;
		// p1, p2 �� ����
		while (tmp--) {
			int input;
			cin >> input;
			p1.enqueue(input);
		}
		tmp = N;

		while (tmp--) {
			int input;
			cin >> input;
			p2.enqueue(input);
		}
		tmp = N;

		// ����
		int score_p1 = 0;
		int score_p2 = 0;
		int diff = 0;
		int flag = 0;

		while (N--) {
			int card_p1 = p1.dequeue();
			int card_p2 = p2.dequeue();

			// �� �÷��׸� �ٲ� ����
			if (flag == 2) {
				card_p1 += diff;
			}
			else if (flag == 1) {
				card_p2 += diff;
			}
			else {

			}

			if (card_p1 > card_p2) {
				score_p1++;
				flag = 1;
				diff = card_p1 - card_p2 - 1;
			}
			else if (card_p1 < card_p2) {
				score_p2++;
				flag = 2;
				diff = card_p2 - card_p1 - 1;
			}
			else {
				flag = 0;
				diff = 0;
			}
		}

		if (score_p1 > score_p2)
			cout << 1 << endl;
		else if (score_p1 < score_p2)
			cout << 2 << endl;
		else
			cout << 0 << endl;
	}

	return 0;
}
