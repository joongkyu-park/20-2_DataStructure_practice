
#include <iostream>
using namespace std;

class Array_Stack {
public:
	int* Stack;
	int capacity;
	int t;

	Array_Stack(int capacity) {
		this->capacity = capacity;
		this->Stack = new int[capacity];
		this->t = -1;
	}

	int size() {
		return t + 1;
	}

	bool empty() {
		if (t == -1)
			return 1;
		else
			return 0;
	}

	int top() {
		if (t == -1)
			return -1;
		else {
			return Stack[t];
		}
	}

	void push(int e) {
		t = t + 1;
		Stack[t] = e;
	}

	int pop() {
		if (t == -1)
			return -1;
		else {
			t = t - 1;
			return Stack[t + 1];
		}
	}
};

int main()
{
	Array_Stack Stack(10001);
	int N;
	cin >> N;
	string Opr;

	while (N > 0) {
		N--;
		cin >> Opr;
		if (Opr == "empty") {
			cout << Stack.empty() << endl;
		}
		else if (Opr == "top") {
			cout << Stack.top() << endl;
		}
		else if (Opr == "push") {
			int push;
			cin >> push;
			Stack.push(push);
		}
		else if (Opr == "pop") {
			cout << Stack.pop() << endl;
		}
		else if (Opr == "size") {
			cout << Stack.size() << endl;
		}
	}
}