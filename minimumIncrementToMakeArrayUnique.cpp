#include "globals.h"

// A mathematical solution does exists with the following criteria:
// Time Complexity: O(N)
// Space Complexity: O(N)
// However, the mathematical solution is not trivial


// Time Complexity: O(N log N)
// Space Complexity: O(1) with heap sort; O(N) with merge sort
int minIncrementForUniqueWithSort(vector<int>& A) {

	sort(A.begin(), A.end());

	int count = 0;

	for(int i = 1; i < A.size(); i++) {
		if(A[i-1] >= A[i]) {
			int difference = A[i-1] - A[i] + 1;
			A[i] = A[i-1] + 1;
			count += difference;
		}
	}
	return count;
}