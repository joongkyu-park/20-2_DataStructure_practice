
#include <iostream>
#include <vector>

using namespace std;

static int upheapCnt = 0;

void printUpheapCnt() {
    cout << upheapCnt << endl;
}

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

        upheapCnt++;

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

                upheapCnt++;

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
        if (this->isEmpty() == false) {
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
            cout << endl;
        }
        else {
            cout << -1 << endl;
        }
    }

};
int main()
{
    int T;
    cin >> T;

    while (T--) {
        Heap h;

        int N, p;

        cin >> N >> p;

        while (N--) {
            int num;
            cin >> num;
            h.insert(num);
        }

        h.print();
        cout << h.v[p] << endl;

        /* 내림차순으로 출력하는 방법!!
        while(h.s != 0){
            h.pop();
        }
        */

        // 내림차순 출력법을 이용
        p--;
        while (p--) {
            h.pop();
        }
        cout << h.v[1] << endl;

        printUpheapCnt();
    }

}
