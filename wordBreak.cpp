// https://www.geeksforgeeks.org/word-break-problem-dp-32/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


bool dictionaryContains(string s, unordered_set<string>& wordset) {

	auto got = wordset.find(s);

	if (got == wordset.end()) {
		return false;
	}
	else {
		return true;
	}
}

string wordBreak(string str, vector<string>& wordDict) {

	unordered_set<string> wordset;
	for (auto it = wordDict.begin(); it != wordDict.end(); it++) {
		wordset.insert(*it);
	}


    int size = str.size();
    if (size == 0)   return "true";

    // Create the DP table to store results of subproblems. The value wb[i]
    // will be true if str[0..i-1] can be segmented into dictionary words,
    // otherwise false.
    bool wb[size+1] = { false };

    for (int i=1; i<=size; i++)
    {
        // if wb[i] is false, then check if current prefix can make it true.
        // Current prefix is "str.substr(0, i)"
        if (wb[i] == false &&
			dictionaryContains( str.substr(0, i), wordset ))
            wb[i] = true;

        // wb[i] is true, then check for all substrings starting from
        // (i+1)th character and store their results.
        if (wb[i] == true)
        {
            // If we reached the last prefix
            if (i == size)
                return "true";

            for (int j = i+1; j <= size; j++)
            {
                // Update wb[j] if it is false and can be updated
                // Note the parameter passed to dictionaryContains() is
                // substring starting from index 'i' and length 'j-i'
                if (wb[j] == false && dictionaryContains( str.substr(i, j-i), wordset ))
                    wb[j] = true;

                // If we reached the last character
                if (j == size && wb[j] == true)
                    return "true";
            }
        }
    }

    /* Uncomment these lines to print DP table "wb[]"
     for (int i = 1; i <= size; i++)
        cout << " " << wb[i]; */

    // If we have tried all prefixes and none of them worked
    return "false";

}

int main() {
	vector<string> dict1 = {"apple", "pen"};
	vector<string> dict2 = {"cats", "dog", "sand", "and", "cat"};
	vector<string> dict3 = {"aaaa", "aaa"};
	//string ans1 = wordBreak("applepenapple", dict1);
	//string ans2 = wordBreak("catsandog", dict2);

	string ans3 = wordBreak("aaaaaaa", dict3);

	//cout << "Solution: true; " << "My answer: " << ans1 << endl;
	cout << "Solution: true; " << "My answer: " << ans3 << endl;
}