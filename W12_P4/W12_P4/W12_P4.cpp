﻿#include <iostream>
#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

using namespace std;


class hashtable {
public:
	int* table;
	int arrsize;

	hashtable(int P) {
		arrsize = P;
		table = new int[P];
		for (int i = 0;i < P;i++) {
			table[i] = -1;
		}
	}

	int hashfunc(int key) {
		return key % arrsize;
	}

	void insert(int key) {
		int hashvalue = hashfunc(key);

		while (1) {
			if (table[hashvalue] != -1) {
				hashvalue++;
				continue;
			}
			else {
				table[hashvalue] = key;
				break;
			}
		}
	}

	void probe(int R) {
		int hashvalue = hashfunc(R);

		int probing = 1;

		while (1) {
			if (table[hashvalue] != -1) {
				if (table[hashvalue] == R) {
					cout << "True " << probing << endl;
					break;
				}
				else {
					hashvalue++;
					probing++;
					continue;
				}
			}
			else {
				cout << "False " << probing << endl;
				break;
			}
		}
	}
};


int main() {

	int T;
	cin >> T;

	while (T--) {
		int P;
		cin >> P;
		hashtable h(P);

		int Q;
		cin >> Q;

		while (Q--) {
			int key;
			cin >> key;

			h.insert(key);
		}

		int Q_find;
		cin >> Q_find;

		while (Q_find--) {
			int R;
			cin >> R;

			h.probe(R);
		}
	}
}