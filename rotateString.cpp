#include "globals.h"

// Return true if A can become B

bool rotateString(string A, string B) {

	if(A.length() != B.length()) {
		return false;
	}

	if(A.length() == 0) {
		return true;
	}

	A += A;

	if(0 <= A.find(B) && A.find(B) < A.length()) {
		return true;
	}

	return false;
}