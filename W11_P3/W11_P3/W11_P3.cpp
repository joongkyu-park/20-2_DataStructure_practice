#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Node
{
public:
	int data;
	Node* leftChild;
	Node* rightChild;
	Node* parent;

	Node() {
		this->leftChild = NULL;
		this->rightChild = NULL;
		this->parent = NULL;
	}

	Node(int data) {
		this->data = data;
		this->leftChild = NULL;
		this->rightChild = NULL;
		this->parent = NULL;
	}
};

class BST {

public:
	Node* root;
	int size = 0;

	void insert(int e) {
		if (size == 0) {
			Node* node = new Node(e);
			root = node;
			this->size++;
		}
		else {
			Node* node = new Node(e);
			Node* cmp = root;
			Node* save = root;
			while (cmp != NULL) {
				save = cmp;
				if (cmp->data > e) {
					cmp = cmp->leftChild;
				}
				else if (cmp->data < e) {
					cmp = cmp->rightChild;
				}
				else if (cmp->data == e) {
					cout << "insert error" << endl;
					return;
				}
			}

			if (save->data > e) {
				save->leftChild = node;
				node->parent = save;

				this->size++;
			}
			else {
				save->rightChild = node;
				node->parent = save;

				this->size++;
			}
		}
	}

	Node* find(int e) {
		Node* node = root;

		while (node->data != e) {
			if (node->data > e) {
				node = node->leftChild;
			}
			else {
				node = node->rightChild;
			}
		}

		return node;
	}

	Node* findMinOfRightST(Node* node) {

		if (node->rightChild == NULL)
			return node;
		else {
			Node* tmp = node->rightChild;

			while (tmp->leftChild != NULL) {
				tmp = tmp->leftChild;
			}

			return tmp;
		}
	}

	Node* findMaxOfLeftST(Node* node) {

		if (node->leftChild == NULL)
			return node;
		else {
			Node* tmp = node->leftChild;

			while (tmp->rightChild != NULL) {
				tmp = tmp->rightChild;
			}

			return tmp;
		}
	}

	void erase(int e) {

		Node* node = find(e);
		Node* p = NULL;
		if (node != root) {
			p = find(node->parent->data);
		}

		// 자식 노드가 둘 다 X
		if (node->leftChild == NULL && node->rightChild == NULL) {
			
			if (node == root) {
				root = NULL;
				delete node;
				this->size--;
			}
			else {
				if (p->leftChild == node) {
					p->leftChild = NULL;

					delete node;

					this->size--;
				}
				else if (p->rightChild == node) {
					p->rightChild = NULL;

					delete node;

					this->size--;
				}
			}
		}

		// 왼쪽 자식 X, 오른쪽 자식 O
		else if (node->leftChild == NULL) {
			
			Node* rc = node->rightChild;

			if (node == root) {
				root = rc;
				rc->parent = NULL;
				delete node;

				this->size--;
			}
			else {
				if (p->leftChild == node) {
					p->leftChild = rc;
					rc->parent = p;

					delete node;

					this->size--;
				}
				else if (p->rightChild == node) {
					p->rightChild = rc;
					rc->parent = p;

					delete node;

					this->size--;

				}
			}
		}

		// 왼쪽 자식 O, 오른쪽 자식 X
		else if (node->rightChild == NULL) {
			Node* lc = node->leftChild;

			if (node == root) {
				root = lc;
				lc->parent = NULL;
				delete node;

				this->size--;
			}
			else {
			

				if (p->leftChild == node) {
					p->leftChild = lc;
					lc->parent = p;

					delete node;

					this->size--;
				}
				else if (p->rightChild == node) {
					p->rightChild = lc;
					lc->parent = p;

					delete node;

					this->size--;

				}
			}
		}

		// 자식 둘 다 O
		// 이 경우 이렇게 해도 되지만, ppt 방법처럼 successor의 data를 저장해놓고, successor를 erase한 다음에
		// node의 데이터 자리에 방금 저장한 data를 넣어주면 된다.
		else {
			Node* successor = findMaxOfLeftST(node);
			
			node->data = successor->data;


			Node* successor_of_parent = find(successor->parent->data);

			if (successor->leftChild != NULL) {
				

				if (node == successor_of_parent) {

					successor->leftChild->parent = node;
					node->leftChild = successor->leftChild;

					delete successor;
					this->size--;
				}
				else {
					successor_of_parent->rightChild = successor->leftChild;
					successor->leftChild->parent = successor_of_parent;

					delete successor;
					this->size--;
				}
			}
			else {
				if (node == successor_of_parent) {

					node->leftChild = NULL;

					delete successor;
					this->size--;
				}
				else {
					successor_of_parent->rightChild = NULL;

					delete successor;
					this->size--;
				}
			}
		}

	}

	void inorderTraversal(Node* node) {
		if (this->size == 0)
			cout << "Empty" << endl;
		else{
		if (node->leftChild != NULL) {
				inorderTraversal(node->leftChild);
		}
		cout << node->data << " ";
		if (node->rightChild != NULL) {
			inorderTraversal(node->rightChild);
		}

		return;
		}
	}

};

int main() {
	int T;
	cin >> T;

	while (T--) {
		BST bst;

		int P;
		cin >> P;

		while (P--) {
			int N;
			cin >> N;
			bst.insert(N);
		}

		int Q;
		cin >> Q;


		while (Q--) {
			int N;
			cin >> N;
			bst.erase(N);
		}

		bst.inorderTraversal(bst.root);
		cout << endl;
	}
}