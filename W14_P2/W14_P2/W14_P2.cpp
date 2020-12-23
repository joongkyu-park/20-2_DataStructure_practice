#include<iostream>
#include<string>
#include<vector>

using namespace std;

class edge;
class vertex {
public:
	int data = -1;

	string state = "UNEXPLORED";

	vertex(int data) {
		this->data = data;
	}

	vector<edge*> incident_edges;
	vector<vertex*> adjacency_vertices;
};
class edge {
public:
	vertex* v = nullptr;
	vertex* u = nullptr;

	string state = "UNEXPLORED";

	edge(vertex* v, vertex* u) {
		this->v = v;
		this->u = u;
	}

	vertex* oppostie(vertex* v) {
		if (v == this->v)
			return this->u;
		else
			return this->v;
	}
};

class graph {
public:
	vector<vertex*> vertices_list;
	vector<edge*> edges_list;


	// 정점삽입
	void insert_vertex(int data) {
		vertex* v = new vertex(data);
		this->vertices_list.push_back(v);
	}

	// 간선삽입
	void insert_edge(int num1, int num2) {
		vertex* v = nullptr;
		vertex* u = nullptr;
		for (int i = 0; i < this->vertices_list.size();i++) {
			if (this->vertices_list[i]->data == num1) {
				v = this->vertices_list[i];
			}
			if (this->vertices_list[i]->data == num2) {
				u = this->vertices_list[i];
			}
		}

		/*if (v == nullptr || u == nullptr) {
			cout << -1 << endl;
			return;
		}*/

		for (int i = 0; i < v->incident_edges.size(); i++) {
			vertex* v_opposite = v->incident_edges[i]->oppostie(v);
			if (v_opposite == u) {
				cout << -1 << endl;
				return;
			}
		}

		edge* e = new edge(v, u);

		v->incident_edges.push_back(e);
		u->incident_edges.push_back(e);

		v->adjacency_vertices.push_back(u);
		u->adjacency_vertices.push_back(v);

		this->edges_list.push_back(e);
		return;


	}
};

void DFS(graph G, vertex* v) {

	// DFS 시작
	
	v->state = "VISITED";
	cout << v->data << " ";
	for (int i = 0; i < v->adjacency_vertices.size();i++) {
		vertex* u = v->adjacency_vertices[i];

		if (u->state == "VISITED") {
			continue;
		}
		else {
			DFS(G, u);
		}
	}

	return;
}

int main() {
	int N;
	cin >> N;

	int M;
	cin >> M;

	int A;
	cin >> A;

	graph g;

	while (N--) {
		int I;
		cin >> I;

		g.insert_vertex(I);
	}

	while (M--) {
		int S, D;

		cin >> S >> D;

		g.insert_edge(S, D);
	}

	vertex* start_v = nullptr;
	for (int i = 0; i < g.vertices_list.size();i++) {
		if (g.vertices_list[i]->data == A) {
			start_v = g.vertices_list[i];
			break;
		}
	}
	DFS(g, start_v);

}
