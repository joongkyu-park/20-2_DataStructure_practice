
#include <iostream>

using namespace std;

// 배열 스택
class Array_Stack {
public:
	char* Stack;
	int capacity;
	int t;

	Array_Stack(int capacity) {
		this->capacity = capacity;
		this->Stack = new char[capacity];
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

	char top() {
		if (t == -1)
			return -1;
		else {
			return Stack[t];
		}
	}

	void push(char e) {
		t = t + 1;
		Stack[t] = e;
	}

	char pop() {
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
	string equation;
	
	
	while (N > 0) {
		Array_Stack stack(10001);
		N--;
		cin >> equation;
		
		
		int i = 0;
		while (i < equation.length()) {

			// 연산자일 경우
			if (equation[i] == '(' || equation[i] == ')' || equation[i] == '+' || equation[i] == '-' || equation[i] == '*' || equation[i] == '/' ) {

				// 연산자별 switch문
				switch (equation[i]){
				case '(':
					stack.push(equation[i]);
					break;

				case ')':
					while(stack.top()!='(')
						cout << stack.pop();
					stack.pop();
					break;

				case '+':
					while(stack.top() == '+' || stack.top() == '-' || stack.top() == '*' || stack.top() == '/')
						cout << stack.pop();
					stack.push(equation[i]);
					break;

				case '-':
					while (stack.top() == '+' || stack.top() == '-' || stack.top() == '*' || stack.top() == '/')
						cout << stack.pop();
					stack.push(equation[i]);
					break;

				case '*':
					while (stack.top() == '*' || stack.top() == '/')
						cout << stack.pop();
					stack.push(equation[i]);
					break;

				case '/':
					while (stack.top() == '*' || stack.top() == '/')
						cout << stack.pop();
					stack.push(equation[i]);
					break;
				}
			}

			// 피연산자일 경우
			else {
				cout << equation[i];
			}
			i++;
		}

		// 스택안에 남아있는 연산자들 모두 pop
		while (stack.empty() != true)
			cout << stack.pop();

		cout << '\n';

		delete[] stack.Stack;
	}
}