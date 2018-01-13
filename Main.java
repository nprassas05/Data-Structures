import java.util.*;
import java.io.*;
import java.math.*;

public class Test2 {
	static InputGetter in = new InputGetter();
	static PrintWriter out = new PrintWriter(System.out);

	public static void main(String[] args) {
		solve();
		out.close();
	}

	public static void solve() {
		int n = in.nextInt();
		out.println(n / 2);
	}

	static class InputGetter {
		BufferedReader br;
		StringTokenizer st = null;
		String line;

		public InputGetter() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		public String next() {
			if (st == null || !st.hasMoreTokens()) {
				try {
					while ((line = br.readLine()).isEmpty()) {}
					st = new StringTokenizer(line);
				} catch (IOException ex) {
					throw new RuntimeException(ex);
				}
			}
			return st.nextToken();
		}

		public int nextInt() { return Integer.parseInt(next()); }
		public double nextDouble() { return Double.parseDouble(next()); }
	}
}