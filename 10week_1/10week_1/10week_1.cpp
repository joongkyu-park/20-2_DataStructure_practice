#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Heap {

public:
    vector<int> BT;
    int s = 0;

    Heap(){
        BT.push_back(-1);
    }
    void insert(int e) {
        s++;
        BT.push_back(e);
        int i = s;        
        
        upheap(i);
    }
    void upheap(int i) {
        if (i == 1)
            return;
        else {
            if (BT[i / 2] < BT[i]) {
                BT[0] = BT[i / 2];
                BT[i / 2] = BT[i];
                BT[i] = BT[0];
                BT[0] = -1;

                upheap(i / 2);
            }
            else
                return;
        }
    }
    void size() {
        cout << s << '\n';
    }
    bool isEmpty() {
        if (s != 0)
            return false;
        else
            return true;
    }
    void pop() {
        if (isEmpty()) {
            cout << -1 << '\n';
        }
        else {
            cout << BT[1] << '\n';
            BT[1] = BT[s];
            BT.pop_back();
            s--;

            downheap(1);
        }
    }
    void downheap(int i) {
        if ((i*2)>s)
            return;
        else {
            if ((i * 2 + 1) > s) {
                if (BT[i] < BT[i * 2]) {
                    BT[0] = BT[i * 2];
                    BT[i * 2] = BT[i];
                    BT[i] = BT[0];
                    BT[0] = -1;

                    downheap(i * 2);
                }
                else
                    return;
            }
            else {
                if (BT[i * 2] > BT[i * 2 + 1]) {
                    if (BT[i] < BT[i * 2]) {
                        BT[0] = BT[i * 2];
                        BT[i * 2] = BT[i];
                        BT[i] = BT[0];
                        BT[0] = -1;

                        downheap(i * 2);
                    }
                    else
                        return;
                }
                else{
                    if (BT[i] < BT[i * 2 + 1]) {
                        BT[0] = BT[i * 2 + 1];
                        BT[i * 2 + 1] = BT[i];
                        BT[i] = BT[0];
                        BT[0] = -1;

                        downheap(i * 2 + 1);
                    }
                    else
                        return;
                }
            }                
         }
    }
    void top() {
        if (isEmpty())
            cout << -1 << '\n';
        else
            cout << BT[1] << '\n';
    }
    void print() {
        if (isEmpty())
            cout << -1 << '\n';
        else {
            for (int i = 1; i <= s;i++)
                cout << BT[i] << " ";
        }
    }

};

int main()
{
    int N;
    cin >> N;
    
    Heap h;
    while (N--) {
        string opr;
        cin >> opr;

        if (opr == "insert") {
            int num;
            cin >> num;
            h.insert(num);
        }
        else if (opr == "size") {
            h.size();
        }
        else if (opr == "isEmpty") {
            cout << h.isEmpty() << '\n';
        }
        else if (opr == "pop") {
            h.pop();
        }
        else if (opr == "top") {
            h.top();
        }
        else if (opr == "print") {
            h.print();
        }
    }
}
