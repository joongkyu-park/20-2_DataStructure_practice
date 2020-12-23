#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

class edge;
class vertex {
public:
	int index;

	int data;

	string state = "UNEXPLORED";

	vertex(int data, int index) {
		this->data = data;
		this->index = index;
	}

	vector<edge*> v_edges_list;
};
class edge {
public:
	vertex* v;
	vertex* u;
	string data = "";

	string state = "UNEXPLORED";

	edge(vertex* v, vertex* u, string data) {
		this->v = v;
		this->u = u;
		this->data = data;
	}
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

	vector<vector<edge*>> adjacency_matrix; // 이부분!!

	int v_index = 0;

	graph(int N) {
		vector<vector<edge*>>* tmp = new vector<vector<edge*>>(N + 1, vector<edge*>(N + 1)); // 이부분!!

		this->adjacency_matrix = *tmp;  // 이부분!!

		for (int i = 0;i < N + 1;i++) {
			for (int j = 0; j < N + 1;j++) {
				this->adjacency_matrix[i][j] = nullptr;
			}
		}
	}


	// 정점삽입
	void insert_vertex(int data, int index) {
		vertex* v = new vertex(data, index);
		this->v_index++;
		this->vertices_list.push_back(v);
	}

	// 간선삽입
	void insert_edge(int num1, int num2, string edge_data) {
		vertex* v = NULL;
		vertex* u = NULL;
		for (int i = 0; i < this->vertices_list.size();i++) {
			if (this->vertices_list[i]->data == num1) {
				v = this->vertices_list[i];
			}
			if (this->vertices_list[i]->data == num2) {
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

			v->v_edges_list.push_back(e);
			u->v_edges_list.push_back(e);

			this->edges_list.push_back(e);
			return;
		}

	}
	void insert_edge(int num1, int num2) {
		vertex* v = NULL;
		vertex* u = NULL;
		for (int i = 0; i < this->vertices_list.size();i++) {
			if (this->vertices_list[i]->data == num1) {
				v = this->vertices_list[i];
			}
			if (this->vertices_list[i]->data == num2) {
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
			edge* e = new edge(v, u);
			this->adjacency_matrix[v->index][u->index] = e;
			this->adjacency_matrix[u->index][v->index] = e;

			v->v_edges_list.push_back(e);
			u->v_edges_list.push_back(e);

			this->edges_list.push_back(e);
			return;
		}

	}

	// 두 정점 연결여부
	void isAdjacency(int num1, int num2) {
		vertex* v = NULL;
		vertex* u = NULL;

		for (int i = 0; i < this->vertices_list.size();i++) {
			if (this->vertices_list[i]->data == num1) {
				v = this->vertices_list[i];
			}
			if (this->vertices_list[i]->data == num2) {
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

	// 정점 삭제
	void deleteVertex(int number) {
		vertex* v = NULL;

		// 정점 존재 확인
		int flag = 1;
		for (int i = 0; i < this->vertices_list.size();i++) {
			if (number == this->vertices_list[i]->data) {
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
		cout << this->edges_list.size() << " ";
		for (int i = 0;i < this->edges_list.size();i++) {
			cout << this->edges_list[i]->data << " ";
		}
		cout << endl;
	}
};

void DFS(graph G, int data) {
	vertex* start_v = nullptr;

	// 시작정점 찾기
	for (int i = 0; i < G.vertices_list.size(); i++) {
		if (G.vertices_list[i]->data == data) {
			start_v = G.vertices_list[i];
			break;
		}
	}

	if (start_v == nullptr) {
		cout << -1 << endl;
		return;
	}

	// DFS 시작
	start_v->state = "VISITED";
	cout << start_v->data << " ";
	for (int i = 0; i < start_v->v_edges_list.size();i++) {
		if (start_v->v_edges_list[i] != nullptr) {
			edge* e = start_v->v_edges_list[i];

			if (e->state == "DISCOVERY" || e->state == "BACK") {
				continue;
			}
			else {
				if (e->oppostie(start_v)->state == "VISITED") {
					e->state = "BACK";
					continue;
				}
				else {
					e->state = "DISCOVERY";
					vertex* u = e->oppostie(start_v);
					DFS(G, u->data);
				}
			}
		}
	}

	return;
}

void BFS(graph G, int data) {
	vertex* v=nullptr;
	for (int i = 0; i < G.vertices_list.size();i++) {
		if (G.vertices_list[i]->data == data) {
			v = G.vertices_list[i];
			break;
		}
	}
	
	queue<vertex*> Q;

	v->state = "VISITED";
	cout << v->data << " ";
	
	Q.push(v);

	
	while (!Q.empty()) {
		
		for (int i = 0; i < Q.size(); i++) {
			vertex* cur_v = Q.front();
			Q.pop();

			for (int i = 0; i < cur_v->v_edges_list.size();i++) {
				edge* e = cur_v->v_edges_list[i];				

				if (e->state == "CROSS" || e->state == "DISCOVERY")
					continue;
				else {
					vertex* u = e->oppostie(cur_v);
					
					if (u->state == "VISITED") {
						e->state = "CROSS";
						continue;
					}
					else {
						e->state = "DISCOVERY";
						u->state = "VISITED";
						cout << u->data << " ";
						Q.push(u);
					}
				}
			}
		}
	}

	

		
}


int main() {
	int N;
	cin >> N;

	int M;
	cin >> M;

	int A;
	cin >> A;

	graph g(N);

	while (N--) {
		int I;
		cin >> I;

		g.insert_vertex(I, g.v_index);
	}

	while (M--) {
		int S, D;

		cin >> S >> D;

		g.insert_edge(S, D);
	}

	BFS(g, A);



}
