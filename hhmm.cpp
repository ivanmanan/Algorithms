// you can use includes, for example:
// #include <algorithm>
#include <unordered_set>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// NOTE: This should be for the 2nd M
// Then compare it to the 1st M, if it unchanged, then obviously must decrement
char fillMM(unordered_set<int>& number_set, string& ans, int currentM) {
    for (int i = currentM-1; i >= 0; i--) {
        auto got = number_set.find(i);
        if (got == number_set.end()) {
            continue;
        }
        else { // If it exists in the set, then place it as M
            return '0' + i;
        }
    }
    // If M does not already exist, then add current M
    return '0' + currentM;
}

string solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)

    string ans = "";
    unordered_set<int> number_set;

    // Replicate the "HH:" format
    // NOTE: This does not work for '15:00' --> '10:50'
    for (unsigned int i = 0; i < 3; i++) {
        ans += S[i];
    }

    // Fill-in char set
    for (unsigned int i = 0; i < S.length(); i++) {
        if (S[i] == ':') {
            continue;
        }
        else {
            number_set.insert(S[i] - '0');
        }
    }
    // Do MM
    char secondM = fillMM(number_set, ans, S[4]-'0');

    // If secondM does not change, then change firstM
    char firstM;
    if (secondM == S[4])
        firstM = fillMM(number_set, ans, S[3]-'0');
    else {
        firstM = S[3];
    }
    ans = ans + firstM + secondM;
    return ans;
}