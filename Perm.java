import java.util.*;
import java.io.*;
import static java.lang.Math.*;
import java.math.*;
import static java.lang.System.out;

public class Perm {
	public static final int MAX_SOLUTION_LEN = 1000;
	static int[] solution = new int[MAX_SOLUTION_LEN];

	public static void main(String[] args) throws IOException {
		constructPermutations(3);
	}

	public static void constructPermutations(int n) {
		findSol(n, 0, solution);
	}

	public static void findSol(int n, int k, int[] solution) {
		if (k == n) {
			printSol(solution, n);
			return;
		}

		int[] candidates = getCandidates(n, k, solution);
		for (int i = 0; i < candidates.length; i++) {
			solution[k] = candidates[i]; // make move
			findSol(n, k + 1, solution);
			// unmake move
		}
	}

	public static void printSol(int[] solution, int n) {
		out.print("Solution: (");
		for (int i = 0; i < n; i++) {
			out.print(" " + solution[i]);
		}
		out.println(" )");
	}

	public static int[] getCandidates(int n, int k, int[] solution) {
		boolean[] inPerm = new boolean[n + 1];
		//Arrays.fill(inPerm, false); --> this happens by default in java
		int[] candidates = new int[n - k];

		for (int i = 0; i < k; i++) {
			inPerm[solution[i]] = true;
		}

		int nCandidates = 0;
		for (int i = 1; i <= n; i++) {
			if (!inPerm[i]) {
				candidates[nCandidates++] = i;
			}
		}
		return candidates;
	}
}