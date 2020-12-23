#include<iostream>
#include<string>
#include<vector>

using namespace std;

class vertex {
public:
	int index;
	int number;

	vertex(int number, int index) {
		this->number = number;
		this->index = index;
	}
};
class edge {
public:
	vertex* v;
	vertex* u;
	string data;

	edge(vertex* v, vertex* u, string data) {
		this->v = v;
		this->u = u;
		this->data = data;
	}

	vertex* oppostie(vertex* v) {
		if (v == this->v)
			return u;
		else
			return v;
	}
};

class graph {
public:
	vector<vertex*> vertices_list;
	vector<edge*> edges_list;

	vector<vector<edge*>> adjacency_matrix; // 이부분!!

	graph(int N) {
		vector<vector<edge*>>* tmp = new vector<vector<edge*>>(N, vector<edge*>(N)); // 이부분!!

		this->adjacency_matrix = *tmp;  // 이부분!!

		for (int i = 0;i < N;i++) {
			for (int j = 0; j < N;j++) {
				this->adjacency_matrix[i][j] = nullptr;
			}
		}
	}

	void insert_vertex(int number, int index) {
		vertex* v = new vertex(number, index);

		this->vertices_list.push_back(v);
	}

	void insert_edge(int num1, int num2, string edge_data) {
		vertex* v = NULL;
		vertex* u = NULL;
		for (int i = 0; i < this->vertices_list.size();i++) {
			if (this->vertices_list[i]->number == num1) {
				v = this->vertices_list[i];
			}
			if (this->vertices_list[i]->number == num2) {
				u = this->vertices_list[i];
			}
		}

		if (v == NULL || u == NULL) {
			cout << -1 << endl;
			return;
		}

		if (this->adjacency_matrix[v->index][u->index] != nullptr) {
			cout << -1 << endl;
			return;
		}
		else {
			edge* e = new edge(v, u, edge_data);
			this->adjacency_matrix[v->index][u->index] = e;
			this->adjacency_matrix[u->index][v->index] = e;

			this->edges_list.push_back(e);
			return;
		}

	}

	void isAdjacency(int num1, int num2) {
		vertex* v = NULL;
		vertex* u = NULL;

		for (int i = 0; i < this->vertices_list.size();i++) {
			if (this->vertices_list[i]->number == num1) {
				v = this->vertices_list[i];
			}
			if (this->vertices_list[i]->number == num2) {
				u = this->vertices_list[i];
			}
		}

		if (v == NULL || u == NULL) {
			cout << -1 << endl;
			return;
		}

		if (this->adjacency_matrix[v->index][u->index] != nullptr) {
			cout << 1 << endl;
			return;
		}
		else {
			cout << 0 << endl;
		}

	}

	void deleteVertex(int number) {
		vertex* v = NULL;

		// 정점 존재 확인
		int flag = 1;
		for (int i = 0; i < this->vertices_list.size();i++) {
			if (number == this->vertices_list[i]->number) {
				v = this->vertices_list[i];
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			cout << -1 << endl;
			return;
		}

		int index = v->index;

		// 정점과 관련된 edges 삭제
		for (int i = 0;i < this->adjacency_matrix[index].size();i++) {
			if (this->adjacency_matrix[index][i] != nullptr) {
				edge* e = this->adjacency_matrix[index][i];

				this->adjacency_matrix[index][i] = nullptr;
				this->adjacency_matrix[i][index] = nullptr;

				for (int j = 0; j < this->edges_list.size();j++) {
					if (this->edges_list[j] == e) {
						this->edges_list.erase(this->edges_list.begin() + j);  // 벡터 특정원소 삭제 : erase 함수 다시 상기!
						break;
					}
				}
				delete e;
			}
		}

		// 해당 정점 삭제
		for (int i = 0; i < this->vertices_list.size();i++) {
			if (this->vertices_list[i] == v) {
				this->vertices_list.erase(this->vertices_list.begin() + i);
				break;
			}
		}
		delete v;

		// 남은 간선 정보들 출력
		cout << this->edges_list.size() << endl;
	}
};



int main() {
	int N;
	cin >> N;

	int M;
	cin >> M;

	int K;
	cin >> K;

	graph g(N);

	int index = 0;
	while (N--) {
		int I;
		cin >> I;


		g.insert_vertex(I, index);
		index++;
	}

	while (M--) {
		int S, D;
		string U;
		cin >> S >> D >> U;

		g.insert_edge(S, D, U);
	}

	cout << g.vertices_list.size() << " " << g.edges_list.size() << endl;


	while (K--) {
		int del_number;
		cin >> del_number;

		g.deleteVertex(del_number);

	}
}
