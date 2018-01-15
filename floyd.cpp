#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

const int MAXV = 100;

struct adjMatrix {
    int nVertices;
    int weight[MAXV + 1][MAXV + 1];

    adjMatrix(int N) {
        nVertices = N;
        for (int i = 1; i <= nVertices; i++) {
            for (int j = 1; j <= nVertices; j++) {
                weight[i][j] = i == j ? 0 : INT_MAX;
            }
        }
    }

    void addEdge(int i, int j, int w) {
        weight[i][j] = w;
        weight[j][i] = w;
    }
};

ostream& operator <<(ostream& os, const adjMatrix& g) {
    for (int i = 1; i < g.nVertices; i++) {
        cout << i << ": ";
        for (int j = 1; j <= g.nVertices; j++) {
            cout << g.weight[i][j] << " ";
        }
        cout << endl;
    }
    return os;
}

int addWeights(int w1, int w2) {
    if (w1 == INT_MAX) return w2;
    if (w2 == INT_MAX) return w1;
    return w1 + w2;
}

void floyd(adjMatrix *g) {
    for (int k = 1; k <= g->nVertices; k++) {
        for (int i = 1; i <= g->nVertices; i++) {
            for (int j = 1; j <= g->nVertices; j++) {
                int through_k = addWeights(g->weight[i][k], g->weight[k][j]);
                if (through_k < g->weight[i][j])
                    g->weight[i][j] = through_k;
            }
        }
    }
}

int main() {
    adjMatrix g(4);
    g.addEdge(1, 2, 12);
    g.addEdge(1, 3, 25);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 3, 2);
    g.addEdge(2, 4, 3);
    g.addEdge(4, 3, 11);
    cout << g << endl;
    floyd(&g);
    cout << g << endl;
    return 0;
}
