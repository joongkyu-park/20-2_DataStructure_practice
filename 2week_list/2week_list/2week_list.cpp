#include <iostream>
#include <cstring>

using namespace std;

class Node {
public:
	int data;
	Node* next = NULL;	
};

class List {
public:
	Node* head;
	Node* tail;
	int size = 0;
	List() {
		head = NULL;
		tail = NULL;
	}

	void addFront(int X) {
		Node* NewNode = new Node; // 이 동적할당은 필수
		size++;
		NewNode->data = X;
		NewNode->next = NULL;

		if (head == NULL) {
			head = NewNode;
			tail = NewNode;
		}
		else
		{
			NewNode->next = head;
			head = NewNode;
		}
	}
	void removeFront() {
		if (head == NULL) {
			cout << -1 << endl;
		}
		else {
			cout << head->data << endl;
			
			/* head = head->next;
			size--;      -> 이렇게 하면 메모리 누수 생긴다! */

			Node* ptr = head;
			head = head->next;
			size--;
			delete ptr;
			
			if (size == 0) {
				tail = NULL;
			}
		}
	}
	void front() {
		if (head == NULL) {
			cout << -1 << endl;
		}
		else {
			cout << head->data << endl;
		}
	}
	void empty() {
		if (head == NULL && tail == NULL) {
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
	void printAll() {
		Node* ptr;
		ptr = head;
		cout << "[ ";
		while (ptr != NULL) {
			cout << ptr->data << " ";
			ptr = ptr->next;
		}
		cout << "]" << endl;
	}
};

int main() {
	List list;  // 동적할당해도되고 안해도되고. 스타일 차이.
	int num;
	cin >> num;
	while (num > 0) {
		num--;
		string command;
		cin >> command;
		if (command == "addFront") {
			int X;
			cin >> X;
			list.addFront(X);
		}
		else if (command == "removeFront") {
			list.removeFront();
		}
		else if (command == "front") {
			list.front();
		}
		else if (command == "empty") {
			list.empty();
		}
		else if (command == "printAll") {
			list.printAll();
		}
	}
}