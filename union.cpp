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

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

class unionfind {
public:
	int n;
	int elems[MAX_SIZE];
	int parent[MAX_SIZE];

	bool connected(int a, int b) const {
		assert(0 <= a && a < n);
		assert(0 <= b && b < n);
		return parent[a] == parent[b];
	}

	void join(int a, int b) {
		if (connected(a, b)) return;
		if (a < b) swap(a, b);
		int p = parent[a];
		while (a != p) {
			parent[a] = parent[b];
			a = p;
			p = parent[a];
		}
		parent[a] = parent[b];
	}

	unionfind(int n) {
		this->n = n;
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}
};

void isConnected(const unionfind& uf, int a, int b) {
	if (uf.connected(a, b)) {
		cout << a << " and " << b << " are connected" << endl;
	} else {
		cout << a << " and " << b << " are NOT connected" << endl;
	}
}

int main() {
	unionfind uf(10);
	uf.join(0, 1);
	uf.join(1, 2);
	uf.join(0, 4);
	uf.join(3, 5);
	isConnected(uf, 2, 4);
	isConnected(uf, 3, 0);
	uf.join(4, 2);
	uf.join(4, 6);
	uf.join(3, 6);
	isConnected(uf, 0, 6);
	isConnected(uf, 3, 0);

	for (int i = 0; i < 10; i++) {
		cout << i << "\'s parent: " << uf.parent[i] << endl;
	}
	return 0;
}