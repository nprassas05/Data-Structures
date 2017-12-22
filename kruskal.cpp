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

#define MAX_SIZE 10000

class union_find {
private:
	int numElements;
	int parent[MAX_SIZE];
	int treeSize[MAX_SIZE];
public:
	union_find(int n) {
		assert (0 <= n && n <= MAX_SIZE);
		numElements = n;

		for (int i = 0; i < n; i++) {
			parent[i] = i;
			treeSize[i] = 1;
		}
	}

	int find(int x) {
		int r = parent[x];
		while (r != x) {
			x = r;
			r = parent[x];
		}
		return r;
	}

	bool join(int x, int y) {
		int rootOfX = find(x);
		int rootOfY = find(y);
		if (rootOfX == rootOfY) return false;

		if (treeSize[rootOfX] < treeSize[rootOfY]) {
			treeSize[rootOfY] += treeSize[rootOfX];
			parent[rootOfX] = rootOfY;
		} else {
			treeSize[rootOfY] += treeSize[rootOfX];
			parent[rootOfX] = rootOfY;
		}

		return true;
	}

	bool connected(int x, int y) {
		return find(x) == find(y);
	}
};

/* edge */
struct edge {
	int from;
	int to;
	int weight;
};

/* comparison functionf for edges */
bool edgeCompare(const edge& e1, const edge& e2) {
	return e1.weight < e2.weight;
}

void printEdge(const edge& e) {
	cout << "Edge: (" << e.from << ", " << e.to << ") : " << e.weight << endl;
}

/* weighted undirected graph */
class graph {
public:
	int v;

	vector<edge> edges;
	vector<vector<int>> g;

	graph(int n) {
		v = n;
		g.clear();
		edges.clear();
		g.resize(n);
	}

	void addEdge(int x, int y, int w) {
		int i = (int) edges.size();
		edges.push_back({x, y, w});
		g[x].push_back(i);
		g[y].push_back(i);
	}
};

void kruskal(const graph& g) {
	union_find uf(g.v);
	vector<edge> edgeQueue(g.edges.begin(), g.edges.end());
	sort(edgeQueue.begin(), edgeQueue.end(), edgeCompare);

	int edgesInMST = 0;
	for (int i = 0; i < edgeQueue.size(); i++) {
		edge e = edgeQueue[i];
		if (uf.join(e.from, e.to)) {
			printEdge(e);
			++edgesInMST;
		}

		if (edgesInMST == g.v - 1) return;
	}
}

void testA() {
	graph g(9);
	g.addEdge(7, 6, 1);
	g.addEdge(8, 2, 2);
	g.addEdge(6, 5, 2);
	g.addEdge(0, 1, 4);
	g.addEdge(2, 5, 4);
	g.addEdge(8, 6, 6);
	g.addEdge(2, 3, 7);
	g.addEdge(7, 8, 7);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(3, 4, 9);
	g.addEdge(5, 4, 10);
	g.addEdge(1, 7, 11);
	g.addEdge(3, 5, 14);
	kruskal(g);
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	// graph g(7);
	// g.addEdge(0, 1, 2);
	// g.addEdge(0, 2, 1);
	// g.addEdge(2, 5, 15);
	// g.addEdge(2, 1, 5);
	// g.addEdge(1, 3, 11);
	// g.addEdge(3, 6, 1);
	// g.addEdge(5, 6, 1);
	// g.addEdge(4, 5, 4);
	// g.addEdge(2, 4, 1);
	// g.addEdge(4, 6, 3);
	// g.addEdge(4, 3, 2);
	// g.addEdge(4, 1, 3);
	// kruskal(g);
	testA();
	return 0;
}