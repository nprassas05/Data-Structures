#include <iostream>
#include <utility>
#include <set>
#include <unordered_set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <sstream>
#include <bitset>
#include <functional>
#include <string>
#include <cctype>
#include <cassert>
#include <cmath>
#include <list>
#include <algorithm>
using namespace std;

vector<int> distFromTree;

bool closestToMST(const int& a, const int& b) {
	assert(0 <= a && a < (int) distFromTree.size());
	assert(0 <= b && b < (int) distFromTree.size());
	return distFromTree[a] >= distFromTree[b];
}

int mypop(priority_queue<int, vector<int>, function<bool(int, int)>>& pq) {
	int r = pq.top();
	pq.pop();
	return r;
}

class graph {
public:
	int numVertices;

	struct edge {
		int u;
		int v;
		int weight;

		int other(int x) const {
			return x == u ? v : u;
		}
	};

	vector<vector<edge>> edges;

	graph(int n) {
		numVertices = n;
		edges.clear();
		edges.resize(n);
	}
	
	void addEdge(int u, int v, int w) {
		edges[u].emplace_back(edge{u, v, w});
		edges[v].emplace_back(edge{u, v, w});
	}
};

void prim(const graph& g, int start = 0) {
	cout << "Edge     Weight" << endl;
	vector<bool> visited(g.numVertices, false);
	vector<int> distFromTree(g.numVertices, INT_MAX);
	vector<int> parent(g.numVertices, -1);
	distFromTree[start] = 0;

	int v = start;
	int lightestWeight;
	int lightestNeighbor;

	while (!visited[v]) {
		visited[v] = true;
		lightestNeighbor = v; // arbitrary
		lightestWeight = INT_MAX;

		for (const auto& e: g.edges[v]) {
			int u = e.other(v);
			if (!visited[u] && distFromTree[u] > e.weight) {
				distFromTree[u] = e.weight;
				parent[u] = v;
			}
		}

		for (int i = 0; i < g.numVertices; i++) {
			if (!visited[i] && distFromTree[i] < lightestWeight) {
				lightestWeight = distFromTree[i];
				lightestNeighbor = i;
			}
		}

		if (!visited[lightestNeighbor])
			cout << parent[lightestNeighbor] << " --- " 
				 << lightestNeighbor <<  ", " << lightestWeight 
				 << endl;
		v = lightestNeighbor;
	}
}

void prim2(const graph& g, int start = 0) {
	distFromTree.resize(g.numVertices);
	for (int i = 0; i < g.numVertices; i++) {
		distFromTree[i] = INT_MAX;
	}

	vector<int> visited(g.numVertices, false);
	vector<int> parent(g.numVertices, -1);

	distFromTree[start] = 0;
	priority_queue<int, vector<int>, function<bool(int, int)>> pq(closestToMST);
	pq.push(start);
	int v;

	while (!pq.empty()) {
		v = pq.top(); 
		pq.pop();
		if (visited[v]) continue;
		visited[v] = true;

		// cout << "Adding vertex " << v << " to the MST whose parent is "
		// 	 << parent[v] << endl;
		
		for (auto &e: g.edges[v]) {
			int u = e.other(v);
			if (!visited[u] && e.weight < distFromTree[u]) {
				distFromTree[u] = e.weight;
				parent[u] = v;
				pq.push(u);
			}
		}
	}

	for (int i = 1; i < g.numVertices; i++) {
		cout << "Edge: (" << i << ", " << parent[i] << ") : "
		     << distFromTree[i] << endl;
	}
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	graph g(7);
	g.addEdge(0, 1, 2);
	g.addEdge(0, 2, 1);
	g.addEdge(2, 5, 15);
	g.addEdge(2, 1, 5);
	g.addEdge(1, 3, 11);
	g.addEdge(3, 6, 1);
	g.addEdge(5, 6, 1);
	g.addEdge(4, 5, 4);
	g.addEdge(2, 4, 1);
	g.addEdge(4, 6, 3);
	g.addEdge(4, 3, 2);
	g.addEdge(4, 1, 3);
	prim2(g);
	return 0;
}