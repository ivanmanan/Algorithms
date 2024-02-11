#include "globals.h"

vector<string> commonChars(vector<string>& A) {

	int MAX_CHAR = 26;
	vector<int> charMap(MAX_CHAR, INT_MAX);

	for(int i = 0; i < A.size(); i++) {

		string s = A[i];
		vector<int> localChar(MAX_CHAR, 0);

		// Update local characters for one string
		for(int j = 0; j < s.length(); j++) {
			int index = s[j] - 'a';
			localChar[index]++;
		}

		// Update the global char map
		for(int j = 0; j < MAX_CHAR; j++) {
			charMap[j] = min(charMap[j], localChar[j]);
		}
	}

	vector<string> res;
	for(int i = 0; i < MAX_CHAR; i++) {
		// Construct local vector, size charMap[i], with values initialized as ('a' + i)
		vector<string> temp(charMap[i], string(1,'a' + i));

		// Insert items into the vector
		res.insert(res.end(), temp.begin(), temp.end());
	}
	return res;
}