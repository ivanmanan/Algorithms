#include "globals.h"

// Time Complexity: O(N)
// Space Complexity: O(N) for auxiliary merge function


void merge(vector<int>& A, int l, int m, int r) {

	int i, j;

	// Obtain sizes of the halves
	int n1 = m - l + 1;
	int n2 = r - m;

	// Create temporary arrays
	int* L = new int[n1];
	int* R = new int[n2];

	// Copy data to temporary arrays L and R
	for (i = 0; i < n1; i++)
		L[i] = A[l+i];
	for (j = 0; j < n2; j++)
		R[j] = A[m + 1 + j];

	// Merge the arrays back to Array[l...r]
	i = 0; // Initial index of first sub-array
	j = 0; // Initial index of second subarray
	int k = l; // Initial index of merged subarray
	while (i < n1 && j < n2) {

		// This part does all the comparison
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of L[] and R[]
	// if there are any
	while (i < n1) {
		A[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		A[k] = R[j];
		j++;
		k++;
	}

	// Release memory
	delete[] L;
	delete[] R;
}



void mergeSort(vector<int>& A, int l, int r) {
	if (l < r) {

		// Same as (l+r)/2, but avoids overflow
		// for large l and r
		int m = l + ((r-l) / 2);

		// Sort first and second halves
		mergeSort(A, l, m);
		mergeSort(A, m+1, r);

		merge(A, l, m, r);
	}
}


void printArray(vector<int>& A) {
	cout << "[";
	for (unsigned int i = 0; i < A.size(); i++) {
		if (i != A.size()-1) {
			cout << A[i] << ", ";
		}
	}

	cout << A[A.size()-1];
	cout << "]" << endl;;
}


int main() {
	vector<int> arr = {12, 11, 13, 5, 6, 7};

	cout << "Given Array:" << endl;
	printArray(arr);

	mergeSort(arr, 0, arr.size()-1);

	cout << "Output Array:" << endl;
	printArray(arr);
}