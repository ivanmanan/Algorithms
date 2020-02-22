class Solution {
public:

    bool isPalindrome(string s) {
        for (int i = 0, j = s.length() - 1; i < j; j--, i++) {
            if (s[j] != s[i]) {
                return false;
            }
        }
        return true;
    }


    // Time Complexity: O(N^2 * S)
    // Space complexity: O(N) --> Every pair is a palindrome; O(2*N) but drop constant term
    vector<vector<int>> palindromePairs(vector<string>& words) {

        vector<vector<int>> solution;

        // Iterators named after indexing pair (first, second)
        for (auto first = words.begin(); first != words.end(); first++) {
            for (auto second = words.begin(); second != words.end(); second++) {

                // Avoid doing identical indexes
                if (first == second) {
                    continue;
                }

                string s = (*first) + (*second);

                if (isPalindrome(s)) {
                    vector<int> pair;
                    pair.push_back(first - words.begin());
                    pair.push_back(second - words.begin());
                    solution.push_back(pair);
                    pair.clear();
                }
            }
        }
        return solution;
    }
};