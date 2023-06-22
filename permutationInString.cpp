#include "globals.h"

// Compare hash tables
bool same_map(unordered_map<char,int> m1, unordered_map<char,int> m2) {

	for(auto it = m1.begin(); it != m1.end(); it++) {
		char key = it->first;
		int val = it->second;

		if(val != m2[key]) {
			return false;
		}
	}
	return true;
}

bool checkInclusion(string s1, string s2) {

	unordered_map<char, int> target_map;
	unordered_map<char, int> state_map;

	if(s1.length() > s2.length()) {
		return false;
	}

	for(int i = 0; i < s1.length(); i++) {
		target_map[s1[i]]++;
		state_map[s2[i]]++;
	}


	for(int i = 0; i < s2.length() - s1.length() + 1; i++) {

		if(same_map(state_map, target_map)) {
			return true;
		}
		else {
			state_map[s2[i]]--;
			state_map[s2[i+s1.length()]]++;
		}
	}
	return false;

}

int main() {
	string s1 = "horse";
	string s2 = "ros";

	string res = checkInclusion(s1, s2) ? "true" : "false";
	string ans = "true";

	cout << "Output:   " << res << endl;
	cout << "Expected: " << ans << endl;
}