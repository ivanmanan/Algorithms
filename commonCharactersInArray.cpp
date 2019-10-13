#include <vector>
#include <iostream>
#include <climits>
using namespace std;

/*
  EXPLANATION
  1. I have a global array for 26 chars - each have infinity
  2. I loop through every character per string in array
  3. I constantly take the minimum and insert it into the global array
 */

vector<string> commonChars(vector<string>& A) {

	const int MAX_CHAR = 26;

	vector<int> global_char(MAX_CHAR, INT_MAX);

	for(auto it = A.begin(); it != A.end(); it++) {

		vector<int> local_char(MAX_CHAR, 0);

		string s = *it;
		for(int i = 0; i < s.length(); i++) {
			++local_char[s[i] - 'a'];
		}

		for(int i = 0; i < MAX_CHAR; i++) {
			global_char[i] = min(global_char[i], local_char[i]);
		}
	}

	vector<string> res;
	for(int i = 0; i < MAX_CHAR; i++) {
		vector<string> temp(global_char[i], string(1, 'a' + i));
		res.insert(res.end(), temp.begin(), temp.end());
	}


	return res;
}
