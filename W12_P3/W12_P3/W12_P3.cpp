#include <iostream>
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
	int hashfunc2(int key) {
		return (17 - (key % 17));
	}

	void insert(int key) {
		int hashvalue = hashfunc(key);
		int j = 1;
		while (1) {
			if (table[hashvalue] != -1) {
				hashvalue = ((hashfunc(key) + j * hashfunc2(key)) % arrsize);
				j++;
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
		int j = 1;

		int probing = 1;

		while (1) {
			if (table[hashvalue] != -1) {
				if (table[hashvalue] == R) {
					cout << "True " << probing << endl;
					break;
				}
				else {
					hashvalue = ((hashfunc(R) + j * hashfunc2(R)) % arrsize);
					j++;
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