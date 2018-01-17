import java.util.*;
import java.io.*;

public class MatrixChain {
	public static void main(String[] args) {
		int n = 6;
		int[] r = {30, 35, 15, 5, 10, 20};
		int[] c = {35,  15, 5, 10, 20, 25};
		System.out.println(minChainCost(r, c, n));
	}

	public static int minChainCost(int[] r, int[] c, int n) {
		assert r.length == n && c.length == n : "Invalid Parameters";
		int[][] b = new int[n][n]; // will not use every open space in this memo array
		for (int i = 0; i < n; i++) b[i][i] = 0;

		for (int d = 1; d < n; d++) {
			for (int i = 0, j = i + d; i < n && j < n; i++, j = i + d) {
				int minCost = Integer.MAX_VALUE;
				for (int k = i; k <= j - 1; k++) {
					int cost = b[i][k] + b[k + 1][j] + (r[i]*c[k]*c[j]);
					if (cost < minCost) {
						minCost = cost;
					}
				}
				b[i][j] = minCost;
			}
		}
		return b[0][n - 1];
	}
}