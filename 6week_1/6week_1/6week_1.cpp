#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* par;
    vector<Node*> chi_v;

    Node(int data) {
        this->data = data;
        this->par = NULL;
    }
    ~Node() {}

    void setParent(Node* parent) {             // 노드 부모를 설정
        this->par = parent;
    }
    void insertChild(Node* child) {            // 현재 노드에 자식 노드를추가
        this->chi_v.push_back(child);
    }
    void delChild(Node* child) {                // 현재 노드의 자식노드 중 특정 노드 삭제
        for (int i = 0; i < this->chi_v.size(); i++) {
            if (this->chi_v[i] == child) {
                this->chi_v.erase(this->chi_v.begin() + i);
            }
        }
    }
};

class Tree {
private:
    Node* root;
    vector<Node*> node_list;

public:
    Tree(int);
    ~Tree() {};
    int size();
    void insertNode(int, int);
    void delNode(int);
    void printChi(int);
    void printSib(int);

};

Tree::Tree(int data) {
    this->root = new Node(data);
    node_list.push_back(this->root);
}

int Tree::size() {
    return this->node_list.size();
}

void Tree::insertNode(int par_data, int data) {    // 해당 부모 노드를 찾고 자식 노드로 추가
    for (int i = 0; i < size(); i++) {
        if (node_list[i]->data == par_data) {
            Node* node = new Node(data);
            node->setParent(node_list[i]);         // 노드의 부모를 설정
            node_list[i]->insertChild(node);       // 노드의 부모의 자식리스트에 해당노드 추가
            node_list.push_back(node);             // tree의 노드리스트에 추가
            return;
        }
    }
}

void Tree::delNode(int data) {                     // 노드를 삭제하고 자식 노드들을 부모노드의 자식으로 추가
    Node* nownode;
    Node* par;
    for (int i = 0; i < this->node_list.size(); i++) {
        if (this->node_list[i]->data == data) {
            nownode = node_list[i];
            if (nownode == root) {
                return;
            }
            par = nownode->par;
            for (Node*& child : nownode->chi_v) {    // nownode의 자식들을 부모노드의 자식으로 옮기기, **이표현 모르겠음. 공부
                par->insertChild(child);
                child->par = par;
            }
            par->delChild(nownode);                  // 부모의 자식에서 nownode 지우기
            this->node_list.erase(this->node_list.begin() + i);         // tree의 노드리스트에서 nownode 삭제
            delete nownode; 
        }
    }
}

void Tree::printChi(int data) {                     // 해당 노드의 자식 노드들을 출력
    for (int i = 0; i < size(); i++) {
        if (node_list[i]->data == data) {
            if (node_list[i]->chi_v.size() == 0) {
                cout << "0" << endl;
                return;
            }
            for (int j = 0; j < node_list[i]->chi_v.size(); j++) {
                cout << node_list[i]->chi_v[j]->data << " ";
            }
            cout << endl;
            return;
        }
    }
}

void Tree::printSib(int data) {                      // 같은 부모를 가지는 자식 노드들을 출력
    for (int i = 0; i < size(); i++) {
        if (node_list[i]->data == data) {
            if (node_list[i]->par == NULL) cout << data << endl;
            else {
                Node* par_node = node_list[i]->par;
                for (int j = 0; j < par_node->chi_v.size(); j++) {
                    cout << par_node->chi_v[j]->data << " ";
                }
                cout << endl;
                return;
            }
        }
    }
}
int main()
{
    int N;
    cin >> N;

    Tree t(1);

    while (N--) {
        string opr;
        cin >> opr;
        if (opr == "insert") {
            int x, y;
            cin >> x >> y;
            t.insertNode(x, y);
        }
        else if (opr == "delete") {
            int x;
            cin >> x;
            t.delNode(x);
        }
        else if (opr == "print") {
            int x;
            cin >> x;
            t.printChi(x);
        }
    }
}