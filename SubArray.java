public class SubArray {
	public static void main(String[] args) {
		/* test various arrays to see if they correctly
		 * return the maximum sub array
		*/
		int[] array1 = {-8, 5, 7, -2, 10};
		int[] array2 = {23, 5, -9, 45, 1};
		int[] array3 = {2, -14, 9, -5};
		System.out.println("max sub array sum of array1 = "
			+ maxSubArraySum(array1));
		System.out.println("max sub array sum of array2 = "
			+ maxSubArraySum(array2));
		System.out.println("max sub array sum of array3 = "
			+ maxSubArraySum(array3));
	}

	public static int maxSubArraySum(int[] array) {
		if (array.length == 0)
			return 0;
		
		int currentSum = array[0];
		int maxSum = array[0];
		
		for (int i = 1; i < array.length; i++) {
			int n = array[i];
			if (n < 0 || currentSum < 0) {
				currentSum = n;
			} else {
				currentSum += n;
			}
			
			if (currentSum > maxSum) {
					maxSum = currentSum;
			}
		}
		
		return maxSum;
	}
}
