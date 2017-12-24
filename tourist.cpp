#include <iostream>
#include <utility>
#include <set>
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
#include <cstring>
#include <climits>
using namespace std;

struct edge {
	int from;
	int to;
	int cost;
};

bool edgeCompare(edge e, edge f) {
	return e.cost > f.cost;
}

const int MAXV = 100 + 1;
vector<edge> edges;
int V, E;
int SOURCE, DESTINATION, NUMTOURISTS;

class union_find {
private:
	int numElements;
	int parent[MAXV];
	int treeSize[MAXV];
public:
	union_find(int n) {
		assert (0 <= n && n <= MAXV);
		numElements = n;

		for (int i = 0; i <= n; i++) {
			parent[i] = i;
			treeSize[i] = 1;
		}
	}

	int find(int x) {
		int r = parent[x];
		while (r != x) {
			if (r < 0) {
				cerr << "x = " << x << ", r = " << r << endl;
				assert(false);
			}
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

void kruskal() {
	union_find uf(V);
	sort(edges.begin(), edges.end(), edgeCompare);
	int bestEdgeWeight = 0;

	//printf("now looping\n");
	for (int i = 0; i < edges.size(); i++) {
		edge e = edges[i];
		//printf("(%d) edge from %d to %d: weight = %d\n", i, e.from, e.to, e.cost);
		if (uf.join(e.from, e.to)) {
			if (uf.connected(SOURCE, DESTINATION)) {
				bestEdgeWeight = e.cost - 1;
				break;
			}
		}
	}

	int numTrips = bestEdgeWeight >= NUMTOURISTS ? 1 :
				   NUMTOURISTS % bestEdgeWeight == 0 ? NUMTOURISTS / bestEdgeWeight :
				   (NUMTOURISTS / bestEdgeWeight) + 1;
	printf("Minimum Number of Trips = %d\n", numTrips);
}

int main() {
	int x, y, w;
	int caseNum = 1;

	scanf("%d %d", &V, &E);
	while (!(V == 0 && E == 0)) {
		edges.clear();
		edges.resize(E);
		for (int i = 0; i < E; i++) {
			scanf("%d %d %d", &x, &y, &w);
			edges.push_back({x, y, w});
		}
		scanf("%d %d %d", &SOURCE, &DESTINATION, &NUMTOURISTS);
		printf("Scenario #%d\n", caseNum++);
		//printf("Source: %d, Destination: %d\n", SOURCE, DESTINATION);
		kruskal();
		scanf("%d %d", &V, &E);
		puts("");
	}
	return 0;
}