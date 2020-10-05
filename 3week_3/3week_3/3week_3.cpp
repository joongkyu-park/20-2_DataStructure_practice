
#include <iostream>

using namespace std;

// 배열 스택
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
	int N;
	cin >> N;

	while (N > 0) {
		N--;
		
		string equation;
		cin >> equation;
		Array_Stack stack(equation.length());

		for (int i = 0; i < equation.length(); i++) {
			if ((equation[i] - '0') >= 0 && (equation[i] - '0') < 10) {
				stack.push(equation[i]-'0');
			}
			else {
				int a = stack.pop();
				int b = stack.pop();
				if (equation[i] == '+') {
					stack.push(a + b);
				}
				else if (equation[i] == '-') {
					stack.push(b - a);
				}
				else if (equation[i] == '*') {
					stack.push(a * b);
				}
			}
		}

		cout << stack.top() << endl;

		delete[] stack.Stack;
	}	
}