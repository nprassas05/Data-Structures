import java.util.*;
import java.io.*;
import static java.lang.Math.*;
import java.math.*;
import static java.lang.System.out;

class Graph {
	int nVertices;
	List<Integer>[] adjList;

	@SuppressWarnings("unchecked")
	public Graph(int n) {
		nVertices = n;
		adjList = (List<Integer>[]) new List[nVertices + 1];
		for (int i = 1; i <= n; i++) {
			adjList[i] = new ArrayList<>();
		}
	}

	public void addEdge(int u, int v) {
		adjList[u].add(v);
		adjList[v].add(u);
	}
}

public class GraphPaths {
	static final int MAXV = 10;
	static boolean[] visited = new boolean[MAXV + 1];

	public static void main(String[] args) throws IOException {
		Graph g = new Graph(6);
		g.addEdge(1, 2);
		g.addEdge(1, 3);
		g.addEdge(1, 4);
		g.addEdge(1, 5);
		g.addEdge(2, 6);
		g.addEdge(3, 6);
		g.addEdge(3, 4);
		g.addEdge(4, 6);
		g.addEdge(5, 6);

		constructPaths(g, 1, 3);
	}

	public static void constructPaths(Graph g, int s, int t) {
		Arrays.fill(visited, false);
		int[] pathVector = new int[MAXV + 1];
		findSol(g, s, t, 0, pathVector);
	}

	public static void findSol(Graph g, int s, int t, int pathSize, int[] pathVector) {
		pathVector[pathSize] = s;
		if (s == t) {
			printSol(pathVector, pathSize + 1);
			return;
		}

		visited[s] = true;

		int[] candidates = getCandidates(g, s);

		for (int i = 0; i < candidates.length; i++) {
			//pathVector[pathSize] = candidates[i]; // make move
			findSol(g, candidates[i], t, pathSize + 1, pathVector);
			// unmake move
		}

		visited[s] = false;
	}

	public static void printSol(int[] solution, int n) {
		out.print("Solution: (");
		for (int i = 0; i < n; i++) {
			out.print(" " + solution[i]);
			if (i + 1 < n) out.print(" ->");
		}
		out.println(" )");
	}

	public static int[] getCandidates(Graph g, int s) {
		List<Integer> candidateList = new ArrayList<>();
		for (int neighbor: g.adjList[s]) {
			if (!visited[neighbor]) {
				candidateList.add(neighbor);
			}
		}

		int[] candidateArray = new int[candidateList.size()];
		for (int i = 0; i  <candidateList.size(); i++) 
			candidateArray[i] = candidateList.get(i);
		return candidateArray;
	}
}