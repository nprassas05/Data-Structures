import java.util.*;
import java.io.*;
import static java.lang.Math.*;
import java.math.*;
import static java.lang.System.out;

public class Subsets {
	public static final int MAX_SOLUTION_LEN = 1000;
	static int[] solution = new int[MAX_SOLUTION_LEN];

	public static void main(String[] args) throws IOException {
		constructSubsets(3);
	}

	public static void constructSubsets(int n) {
		findSol(n, 0, solution);
	}

	public static void findSol(int n, int k, int[] solution) {
		if (k == n) {
			printSol(solution, n);
			return;
		}

		int[] candidates = getCandidates(n, k);
		for (int i = 0; i < candidates.length; i++) {
			solution[k] = candidates[i]; // make move
			findSol(n, k + 1, solution);
			// unmake move
		}
	}

	public static void printSol(int[] solution, int n) {
		out.print("Solution: {");
		for (int i = 0; i < n; i++) {
			if (solution[i] == 1)
				out.print(" "  + (i + 1));
		}
		out.println(" }");
	}

	public static int[] getCandidates(int n, int k) {
		return new int[]{0, 1};
	}
}