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

typedef int color;
const int MAXV = 60000;
const char *faceTypes[] = {"front", "back", "left", 
							"right",  "top", "bottom"};
bool visited[MAXV + 1];
int parent[MAXV + 1];
int startingVertex;

struct node {
	int id;
	int faceType;
	color faceColor;
	color opposingFaceColor;
};

class graph {
public:
	int nVertices;
	vector<vector<int>> adjList;
	graph() {
		adjList.resize(MAXV);
	}

	void reset(int n) {
		nVertices = n * 6;
		for (int i = 0; i < nVertices; i++) {
			adjList[i].clear();
		}
	}

	void addEdge(int u, int v) {
		adjList[u].push_back(v);
	}
};

vector<vector<node>> faceNodes;

graph g;

int frontColor, backColor, leftColor,
	rightColor, topColor, bottomColor;

void reset(int n) {
	g.reset(n);
	memset(visited, false, sizeof(visited));
	faceNodes.clear();
	faceNodes.resize(n);
}

void addNodes(int i) {
	faceNodes[i].push_back({i + 1, 0, frontColor, backColor});
	faceNodes[i].push_back({i + 1, 1, backColor, frontColor});
	faceNodes[i].push_back({i + 1, 2, leftColor, rightColor});
	faceNodes[i].push_back({i + 1, 3, rightColor, leftColor});
	faceNodes[i].push_back({i + 1, 4, topColor, bottomColor});
	faceNodes[i].push_back({i + 1, 5, bottomColor, topColor});
}

bool kissing(node u, node v) {
	return u.opposingFaceColor == v.faceColor;
}

void buildGraph() {
	for (int i = 0; i + 1 < faceNodes.size(); i++) {
		for (int j = 0; j < 6; j++) {
			int uIndex = (i * 6) + j;
			node u = faceNodes[i][j];

			for (int k = i + 1; k < faceNodes.size(); k++) {
				for (int l = 0; l < 6; l++) {
					int vIndex = (k * 6) + l;
					node v = faceNodes[k][l];

					if (kissing(u, v)) {
						assert(u.id < v.id);
						// printf("(%d: %s, %d: %s)\n", u.id, 
						// faceTypes[u.faceType], v.id, faceTypes[v.faceType]);
						g.addEdge(uIndex, vIndex);
					}
				}
			}
		}
	}
}

bool sameNode(int u, int v) {
	int rowU = u / 6;
	int colU = u % 6;
	int rowV = v / 6;
	int colV = v % 6;

	node uNode = faceNodes[rowU][colU];
	node vNode = faceNodes[rowV][colV];

	return uNode.id == vNode.id;
}

void printStuff(int p) {
	int row = p / 6;
	int col = p % 6;

	node n = faceNodes[row][col];
	printf("%d %s\n", n.id, faceTypes[n.faceType]);
}

int maxLenDP() {
	int maxLen = 0;
	vector<int> length_to(g.nVertices, 0);
	vector<int> parent(g.nVertices);
	for (int i = 0; i < g.nVertices; i++) {
		parent[i] = i;
	}

	for (int v = 0; v < g.nVertices; v++) {
		vector<int> neighbors = g.adjList[v];
		for (auto& x: neighbors) {
			if (length_to[x] < length_to[v] + 1) {
				parent[x] = v;
				length_to[x] = length_to[v] + 1;
			}
		}
	}

	stack<int> mystack;
	int p = 0;

	for (int v = 0; v < g.nVertices; v++) {
		if (length_to[v] > maxLen) {
			maxLen = length_to[v];
			p = v;
		}
	}

	while (parent[p] != p) {
		mystack.push(p);
		p = parent[p];
	}
	mystack.push(p);

	cout << mystack.size() << endl;

	while (!mystack.empty()) {
		printStuff(mystack.top());
		mystack.pop();
	}

	return maxLen;
}

int main() {
	int n;
	int caseNum = 0;
	scanf("%d", &n);

	while(n != 0) {
		reset(n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d %d %d %d", &frontColor, &backColor, &leftColor,
				  &rightColor, &topColor, &bottomColor);
			addNodes(i);
		}

		buildGraph();
		printf("Case #%d\n", ++caseNum);
		int maxLen = maxLenDP();
		scanf("%d", &n);
		if (n != 0) puts("");
	}
	return 0;
}