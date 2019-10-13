#include <iostream>
using namespace std;

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

string solution(string &S, int K) {
    // write your code in C++14 (g++ 6.2.0)
    string ans = "";

    int countDashes = 0;
    for (unsigned int i = 0; i < S.length(); i++) {
        if (S[i] == '-') {
            countDashes++;
        }
    }
    unsigned int new_length = S.length() - countDashes;

    // Deal with remainder first
    unsigned int j = 0;
    unsigned int remainder = new_length % K;
    if (remainder) {
        for (unsigned int i = 0; i < S.length(); i++) {
            if (S[i] == '-') {
                continue;
            }
            else if (ans.length() == remainder) {
                j = i;
                ans += '-';
                break;
            }
            else {
                ans += toupper(S[i]);
            }
        }
    }

    // Deal with all other strings
    int count = 0;
    for (; j < S.length(); j++) {
        if (S[j] == '-') {
            continue;
        }
        if (count % K == 0 && count != 0) {
            ans += '-';
        }
        ans += toupper(S[j]);

        count++;
    }

    return ans;
}