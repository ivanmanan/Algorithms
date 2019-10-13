#include <iostream>
#include <vector>

using namespace std;

// Cracking the Coding Interview Book version
/*
  Given two strings, determine if edit is one away to obtain the string
 */

bool oneEditAway(string s, string t) {

	// Length check
	if(abs(s.length() - t.length()) > 1) {
		return false;
	}

	// Determine which string is shorter
	string s1 = s.length() > t.length() ? s : t;
	string s2 = s.length() > t.length() ? t : s;

	int index1 = 0;
	int index2 = 0;
	bool foundDiff = false;

	while(index1 < s1.length() && index2 < s2.length()) {
		if(s1[index1] != s2[index2]) {
			if(foundDiff) {
				return false;
			}
			foundDiff = true;

			// Check if string lengths are equivalent
			// --> then this is a replacement
			if(s1.length() == s2.length()) {
				index1++;
			}
			// Otherwise, this is an insertion/deletion
			else {
				index2++;
			}
			index2++; // always move pointer for longer string
		}
	}
	return true;
}


// Using dynamic progrmaming
int editDistDP(string str1, string str2, int m, int n) {

    // Create a table to store results of subproblems
    int dp[m+1][n+1];

    // Fill d[][] in bottom up manner
    for (int i=0; i<=m; i++) {
        for (int j=0; j<=n; j++) {

            // If first string is empty, only option is to
            // insert all characters of second string
            if (i==0)
                dp[i][j] = j;  // Min. operations = j

            // If second string is empty, only option is to
            // remove all characters of second string
            else if (j==0)
                dp[i][j] = i; // Min. operations = i

            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];

            // If the last character is different, consider all
            // possibilities and find the minimum
            else
                dp[i][j] = 1 + min(dp[i][j-1],  // Insert
                                   dp[i-1][j],  // Remove
                                   dp[i-1][j-1]); // Replace
        }
    }

    return dp[m][n];
}
