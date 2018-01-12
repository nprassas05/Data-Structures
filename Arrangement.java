/*

Suppose you have N integers from 1 to N. We define a beautiful arrangement 
as an array that is constructed by these N numbers successfully if one of 
the following is true for the ith position (1 <= i <= N) in this array:

The number at the ith position is divisible by i.
i is divisible by the number at the ith position.
Now given N, how many beautiful arrangements can you construct?

*/

public class Arrangement {
	public static void main(String[] args) {
		int sol = new Solution().countArrangement(2);
		System.out.println(sol);
	}
}

class Solution {
    public int countArrangement(int N) {
        boolean[] used = new boolean[N + 1];
        Count c = new Count();
        findSol(N, 0, used, c);
        return c.count;
    }
    
    public void findSol(int N, int currPos, boolean[] used, Count c) {
        if (currPos == N) {
            c.incrementCount();
            return;
        }
        
        int[] candidates = getCandidates(N, used, currPos + 1);
        for (int i = 0; i < candidates.length; i++) {
            used[candidates[i]] = true;
            findSol(N, currPos + 1, used, c);
            used[candidates[i]] = false;
        }
    }
    
    public int[] getCandidates(int N, boolean[] used, int currPos) {
        int[] candidates = new int[N];
        int nCandidates = 0;
        for (int i = 1; i <= N; i++) {
        	if (used[i]) continue;
            if (i % currPos == 0 || currPos % i == 0) {
                candidates[nCandidates++] = i;
            }
        }
        
        int[] candidateCopies = new int[nCandidates];
        System.arraycopy(candidates, 0, candidateCopies, 0, nCandidates);
        return candidateCopies;
    }
}

class Count {
    int count;
    
    public Count() {
        count = 0;
    }
    
    public void incrementCount() {
        count++;
    }
}