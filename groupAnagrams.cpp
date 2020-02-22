#include "globals.h"


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