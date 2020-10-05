#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int M;
    cin >> M;
    int arr[10000] = { 0 };
    while (M > 0) {
        M--;
        string command;

        cin >> command;
        if (command == "at") {
            int tmp;
            cin >> tmp;

            cout << arr[tmp] << endl;
        }
        else if (command == "set") {
            int tmp;
            int value;
            cin >> tmp >> value;

            if (arr[tmp] == 0) {
                cout << 0 << endl;
            }
            else {
                arr[tmp] = value;
            }
        }
        else if (command == "add") {
            int tmp;
            int value;
            cin >> tmp >> value;
            
            if (arr[tmp] == 0) {
                int index = 0;
                while (arr[index]!=0) {
                    index++;
                }
                arr[index] = value;
            }
            else {
                int a = arr[tmp];
                arr[tmp] = value;
                int b = a;
                tmp++;
                a = arr[tmp];
                while (b!=0) {
                    arr[tmp] = b;
                    b = a;
                    a = arr[tmp + 1];
                    tmp++;
                }
            }
            
        }
    }
}
