#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>
using namespace std;

// Expected answer:
// hello, good, noice

bool comp(pair<string, int> i, pair<string, int> j) {
	return (i.second > j.second);
}

vector<string> printTopThreeWords(vector<string> words) {
	vector<string> solution;
	unordered_map<string, int> word_count;
	string word;

	// O(N) time
	for (auto it = words.begin(); it != words.end(); it++) {
		word = *it;

		auto got = word_count.find(*it);

		// word exists in hash table
		if (got != word_count.end()) {
			(got->second)++;
		} // otherwise, word does not exist in hash table
		else {
			word_count.insert({word,1});
		}
	}

	// O(N log N) time for sorting map descending order
	vector<pair<string, int>> elems(word_count.begin(), word_count.end());
	sort(elems.begin(), elems.end(), comp);

	//
	for (int i = 0; i < 5; i++) {
		solution.push_back(elems[i].first);
	}
	return solution;
}

int main() {

	vector<string> words;
	ifstream myfile;
	string line;
	myfile.open("words.txt");

	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			words.push_back(line);
		}
		myfile.close();
	}

	vector<string> ans = printTopThreeWords(words);

	for (auto it = ans.begin(); it != ans.end(); it++) {
		cout << *it << endl;
	}
}