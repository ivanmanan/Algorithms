#include "globals.h"

/*
  map<int,int> {KEY:VALUE} = {s[i], freq_count}
  map<int,int> {KEY:VALUE} = {freq_count, vector}
*/

// Length of string is N
string frequencySort(string s) {

	unordered_map<char,int> charFrequency;
	// TIME: O(N) for creating hash table
	for(int i = 0; i < s.length(); i++) {
		charFrequency[s[i]]++;
	}

	// Create ordered map based on integer frequency
	map<int,vector<string>> numFrequency;
	// TIME: O(N) worst case every character in s is unique
	for(auto it = charFrequency.begin(); it != charFrequency.end(); it++) {

		string value = "";
		for(int i = 0; i < it->second; i++) {
			value += it->first;
		}

		auto got = numFrequency.find(it->second);

		// TIME: O(log N) -- tree height for insertion of the keys b/c BST
		if(got != numFrequency.end()) {
			(got->second).push_back(value);
		}
		else {
			vector<string> temp = {value};
			numFrequency[it->second] = temp;
		}
	}
	// TIME: O(N log N)

	// Reverse iterate the map to get descending order
	string res = "";
	for(auto it = numFrequency.rbegin(); it != numFrequency.rend(); it++) {
		for(auto ite = it->second.begin(); ite != it->second.end(); ite++) {
			res += *ite;
		}
	}
	return res;
}

// FINAL TIME COMPLEXITy
// O(N log N + N log N + N)
// O(2 N log N + N)
// O(N log N)

// SPACE COMPLEXITY
// maps, vector
// O(N)


int main() {
	string s = "tree";
	string ans = "eetr";
	string res = frequencySort(s);
	cout << "Output:   " << res << endl;
	cout << "Expected: " << ans << endl;
}