import java.util.*;

public class UniqueDigits {
	public static void main(String[] args) {
		int sol = countNumbersWithUniqueDigits(3);
		System.out.println(sol);
	}

	public static int countNumbersWithUniqueDigits(int n) {
		Counter c = new Counter();
		boolean[] used = new boolean[10];
		findSol(n, 0, used, c);
		return c.getCount();
	}

	public static void findSol(int n, int k, boolean[] used, Counter c) {
		c.incrementCount();

		if (k == n) {
			return;
		}

		for (int x: getCandidates(k, used)) {
			used[x] = true;
			findSol(n, k + 1, used, c);
			used[x] = false;
		}
	}

	public static List<Integer> getCandidates(int k, boolean[] used) {
		List<Integer> result = new ArrayList<>();
		int i = k > 0 ? 0 : 1;

		for (; i <= 9; i++) {
			if (!used[i]) {
				result.add(i);
			}
		}
		return result;
	}
}

class Counter {
	int count;

	public Counter() {
		count = 0;
	}

	public void incrementCount() {
		++count;
	}

	public int getCount() {
		return count;
	}
}