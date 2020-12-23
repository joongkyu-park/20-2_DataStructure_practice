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

	edge(vertex* v, vertex* u) {
		this->v = v;
		this->u = u;
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

	vector<vector<int>> adjacency_matrix; // 이부분!!

	graph(int N) {
		vector<vector<int>>* tmp = new vector<vector<int>>(N, vector<int>(N, 0)); // 이부분!!
		adjacency_matrix = *tmp;  // 이부분!!
	}

	void insert_vertex(int number, int index) {
		vertex* v = new vertex(number, index);

		this->vertices_list.push_back(v);
	}

	void insert_edge(int num1, int num2) {
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

		if (this->adjacency_matrix[v->index][u->index] == 1) {
			cout << -1 << endl;
			return;
		}
		else {
			edge* e = new edge(v, u);
			this->adjacency_matrix[v->index][u->index] = 1;
			this->adjacency_matrix[u->index][v->index] = 1;

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

		if (this->adjacency_matrix[v->index][u->index] == 1) {
			cout << 1 << endl;
			return;
		}
		else {
			cout << 0 << endl;
		}
		
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
		cin >> S >> D;

		g.insert_edge(S, D);
	}

	cout << g.vertices_list.size() << " " << g.edges_list.size() << endl;

	
	while (K--) {
		int num1, num2;
		cin >> num1 >> num2;

		g.isAdjacency(num1, num2);
	}
}
