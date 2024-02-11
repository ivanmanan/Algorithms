#include "globals.h"
using namespace std;

/*
  WALKTHROUGH

  s1 = "abaa"
  s2 = "abcd"

  frequencyMap over s1:
  a:3
  b:1

  frequencyMap over s2:
  a:2
  b:0
  c:-1
  d:-1

  count: 2

  ================

  s1 = "abc"
  s2 = "aaa"

  frequencyMap over s1:
  a:1
  b:1
  c:1

  frequencyMap over s2:
  a:-2
  b:1
  c:1

  count: 2

 */

vector<int> getMinimumDifference(vector<string> a, vector<string> b) {
    vector<int> differences;

    for(int i = 0; i < a.size(); i++) {
        unordered_map<char, int> frequencyMap;

        // Determine if given strings are possible anagrams
        if(a[i].length() != b[i].length()) {
            differences.push_back(-1);
            continue;
        }

        // Iterate first string and track frequencies
        for(int j = 0; j < a[i].length(); j++) {

            // In C++, uninitalized key has value default to 0
            frequencyMap[a[i][j]]++;
        }

        // Iterate second string and update frequencyMap
        for(int j = 0; j < b[i].length(); j++) {
            frequencyMap[b[i][j]]--;
        }

        int count = 0;
        for(auto it = frequencyMap.begin(); it != frequencyMap.end(); it++) {
            if(it->second < 0) {
                count += abs(it->second);
            }
        }
        differences.push_back(count);
    }
    return differences;
}