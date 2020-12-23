
#include <iostream>
#include <vector>

using namespace std;

class Heap {
public:
    vector<int> v;
    int s = 0;

    Heap() {
        v.push_back(-1);
    }

    void insert(int e) {
        s++;
        v.push_back(e);

        upheap(s);
    }
    
    void upheap(int child) {
        int parent = (child / 2);
        if (parent >= 1) {
            if (v[child] > v[parent]) {
                int tmp;
                tmp = v[child];
                v[child] = v[parent];
                v[parent] = tmp;

                upheap(parent);
            }
            else {
                return;
            }
        }
        else {
            return;
        }
    }
    
    void downheap(int parent) {
        int leftchild = parent * 2;
        int rightchild = parent * 2 + 1;

        if (rightchild <= s)
        {
            if (v[leftchild] > v[rightchild]) {
                if (v[parent] < v[leftchild]) {
                    int tmp;
                    tmp = v[leftchild];
                    v[leftchild] = v[parent];
                    v[parent] = tmp;

                    downheap(leftchild);
                }
            }
            else {
                if (v[parent] < v[rightchild]) {
                    int tmp;
                    tmp = v[rightchild];
                    v[rightchild] = v[parent];
                    v[parent] = tmp;

                    downheap(rightchild);
                }
            }
        }
        else if (leftchild <= s)
        {
            if (v[parent] < v[leftchild]) {
                int tmp;
                tmp = v[leftchild];
                v[leftchild] = v[parent];
                v[parent] = tmp;
            }

            return;
        }
        else {
            return;
        }
        
    }

    void size() {
        cout << s << endl;
    }

    bool isEmpty() {
        if (s == 0)
            return true;
        else
            return false;
    }

    void pop() {
        if (this->isEmpty()==false) {
            cout << v[1] << endl;
            v[1] = v[s];
            v.pop_back();
            s--;

            downheap(1);
        }
        else {
            cout << -1 << endl;
        }
    }

    void top() {
        if (this->isEmpty() == false) {
            cout << v[1] << endl;
        }
        else {
            cout << -1 << endl;
        }
    }

    void print() {
        if (this->isEmpty() == false) {
            for (int i = 1; i <= s; i++) {
                cout << v[i] << " ";
            }
        }
        else {
            cout << -1 << endl;
        }
    }
};
int main()
{
    int N;
    cin >> N;
    Heap h;

    while (N--) {
        string cmd;

        cin >> cmd;

        if (cmd == "insert") {
            int e;
            cin >> e;
            h.insert(e);
        }
        else if (cmd == "size") {
            h.size();
        }
        else if (cmd == "isEmpty") {
            cout << h.isEmpty() << endl;
        }
        else if (cmd == "pop") {
            h.pop();
        }
        else if (cmd == "top") {
            h.top();
        }
        else if (cmd == "print") {
            h.print();
        }

    }
}
