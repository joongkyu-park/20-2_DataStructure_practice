
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

class S_LinkedList {
public:
	Node* head;
	Node* tail;

	S_LinkedList() {
		head = NULL;
		tail = NULL;
	}

	int Empty() { // 리스트가 비어있는지 확인하는 함수
		if (head == NULL && tail == NULL)
			return 1;
		else
			return 0;
	}

	int Peek() {
		return tail->data;
	}

	void Append(int data) { // 연결 리스트에 node를 추가하는함수
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

	int Delete() {
		int removeNum = 0;
		int cnt = 0;
		Node* cur_node;
		Node* pre_node;

		pre_node = cur_node = head; // head node에서 시작

		while (cur_node->next != NULL) { // 마지막 노드를 제거
			pre_node = cur_node;
			cur_node = cur_node->next;
		}
		removeNum = cur_node->data;
		pre_node->next = cur_node->next;
		tail = pre_node;
		return removeNum;
	}

};

class Linked_Stack {
public:
	int n;
	S_LinkedList* Stack;

	Linked_Stack() {
		this->Stack = new S_LinkedList();
		this->n = 0;
	}
	int size() {

	}
	bool empty() {

	}
	int top() {

	}
	void push(int e) {

	}
	int pop() {

	}
};

int main()
{
	
}