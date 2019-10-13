#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<string> result;
	string s = "Split by whitespaces";

	int index = s.find(" ");
	string first_word = s.substr(0, index);

	string second_word = s.substr(index, s.length());

	result.push_back(first_word);
	result.push_back(second_word);

	for (auto it = result.begin(); it != result.end(); it++) {
		cout << *it << endl;
	}
}