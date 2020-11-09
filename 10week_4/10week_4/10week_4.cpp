#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Heap {

public:
    vector<int> BT;
    int s = 0;
    int upheap_cnt = 0;

    Heap() {
        BT.push_back(-1);
    }
    void insert(int e) {
        s++;
        BT.push_back(e);
        int i = s;

        upheap_cnt++;
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

                upheap_cnt++;
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
    int pop() {
        if (isEmpty()) {
            return -1;
        }
        else {
            int x;
            x = BT[1];
            BT[1] = BT[s];
            BT.pop_back();
            s--;

            downheap(1);
            return x;
        }
    }
    void downheap(int i) {
        if ((i * 2) > s)
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
                else {
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
            cout << "\n";
        }
    }
    void printP(int p) {
        if (isEmpty())
            cout << -1 << '\n';
        else {
                cout << BT[p] << '\n';
        }
    }

};

int main()
{
    int T;
    cin >> T;
    int result = 0;
    while (T--) {
        Heap h;
        
        int N;
        int p;
        cin >> N >> p;
        
        vector<int>input;
        while (N--) {
            int num;
            cin >> num;
            input.push_back(num);
        }
        for (int i = 0;i < input.size();i++) {
            h.insert(input[i]);
        }
        result += h.upheap_cnt;
        h.print();
        h.printP(p);
        input.clear();

        int tmp = h.s;
        for (int i = 0; i < tmp;i++)
            input.push_back(h.pop());
        cout << input[p-1] << '\n';
        cout << result << '\n';


    }
}
