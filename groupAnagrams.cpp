#include "globals.h"

vector<vector<string>> groupAnagrams(vector<string>& strs) {


	/*
		1. Sort the strings and create a map
		{eat -> aet, tea -> aet, tan -> ant, ate -> aet}
		2. Insert sorted strings as a map
	*/

	// O(N) space
	unordered_map<string, vector<string>> ma;

	// O(N) time
	for(int i = 0; i < strs.size(); i++) {
		string temp = strs[i];

		// Time: (S log S); Space: O(S)
		sort(temp.begin(), temp.end());

		auto got = ma.find(temp);
		if(got != ma.end()) {
			// Key exists in map
			ma[temp].push_back(strs[i]);
		}
		else {
			vector<string> temp_str = {strs[i]};
			ma[temp] = temp_str;
		}
	}

	// Time: O(N * S log S)
	// Space: O(N * S)

	vector<vector<string>> res;
	for(auto it = ma.begin(); it != ma.end(); it++) {
		res.push_back(it->second);
	}
	return res;
}


vector<vector<string>> groupAnagrams(vector<string>& strs) {

	// Create a map that is keyed by all of the sorted and unique words.
	// Value corresponds with a vector consisting of the strings that when sorted, reuslts in the key.

	vector<vector<string>> res;
	if(strs.empty()) {
		return res;
	}

	// Ordered map
	map<string, vector<string>> ma;

	for(string s: strs) {
		// Sort the string
		string sorted = s;
		sort(sorted.begin(), sorted.end());
		ma[sorted].push_back(s);
	}

	for(auto it = ma.begin(); it != ma.end(); it++) {
		res.push_back(it->second);
	}
	return res;
}


vector<vector<string>> groupAnagrams(vector<string>& strs) {

	const int MAX_CHAR = 26;

	// key:value = string permutation:anagrams
	unordered_map<string,vector<string>> permutationMap;


	for(auto it = strs.begin(); it != strs.end(); it++) {
		string s = *it;

		// Create char map for string s
		vector<int> ch(MAX_CHAR, 0);
		for(int i = 0; i < s.length(); i++) {
			ch[s[i] - 'a']++;
		}

		// Create the original string permutation
		string permutationString = "";
		for(int i = 0; i < ch.size(); i++) {
			for(int j = 0; j < ch[i]; j++) {
				permutationString += i + 'a';
			}
		}

		// Insert into map
		auto got = permutationMap.find(permutationString);
		if(got == permutationMap.end()) {
			vector<string> value = {s};
			permutationMap[permutationString] = value;
		}
		else {
			(got->second).push_back(s);
		}
	}

	vector<vector<string>> res;
	for(auto it = permutationMap.begin(); it != permutationMap.end(); it++) {
		res.push_back(it->second);
	}

	return res;
}

void printVectors(vector<vector<string>> input) {

	for(auto it = input.begin(); it != input.end(); it++) {
		vector<string> group = *it;
		for(int i = 0; i < group.size(); i++) {
			cout << group[i] << " ";
		}
		cout << endl;
	}
}

int main() {
	vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<vector<string>> res = groupAnagrams(input);

	vector<vector<string>> ans = {
		{"ate","eat","tea"},
		{"nat","tan"},
		{"bat"}
	};

	cout << "Output:" << endl;
	printVectors(res);

	cout << endl << "Expected:" << endl;
	printVectors(ans);
}