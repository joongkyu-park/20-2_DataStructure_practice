#include <iostream>
#include <cstring>
using namespace std;

class Q {
    int* arr;
    int s = 0;
    int f = 0;
    int r = 0;
    int N;
    void enqueue(int);
    void dequeue();
    void size();
    bool isEmpty();
    void front();
    void rear();

    Q(int S) {
        arr = new int[S];
        N = S;
    }
};

void Q::enqueue(int X) {
    arr[r] = X;
    r = (r + 1) % N;
    s++;
}

void Q::dequeue() {
    if (isEmpty())
        cout << "Empty" << endl;
    else {
        cout << arr[f] << endl;
        f = (f + 1) % N;
        s--;
    }

}

void Q::size() {
    cout << s << endl;
}

bool Q::isEmpty() {
    if (s == 0)
        return true;
    else
        return false;
}

void Q::front() {
    cout << arr[f] << endl;
}


void Q::rear() {
    cout << arr[r] << endl;
}

int main()
{

    int S;
    cin >> S;

    Q q(S);

    int N;
    cin >> N;
    while (N--) {

        string opr;
        cin >> opr;

        if (opr = "enqueue") {
            int X;
            cin >> X;
            q.enqueue(X);
        }
        else if (opr = "dequeue") {
            q.dequeue();
        }
        else if (opr = "size") {
            q.size();
        }
        else if (opr = "isEmpty") {
            cout << q.isEmpty() << endl;
        }
        else if (opr = "front") {
            q.front();
        }
        else if (opr = "rear") {
            q.rear();
        }


    }
}