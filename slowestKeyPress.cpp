#include <iostream>
#include <vector>
using namespace std;

int main() {
    int i = 1;

    char c = 'a' + i;

    cout << c << endl; // should pirnt letter '1'
}

char slowestKey(vector<vector<int>> keyTimes) {


    // Calculate first key hit
    int maxDiffTime = keyTimes[0][1];
    int minKey = keyTimes[0][0];

    for(int i = 1; i < keyTimes.size(); i++) {
        int diffTime = keyTimes[i][1] - keyTimes[i-1][1];
        if(diffTime > maxDiffTime) {
            maxDiffTime = diffTime;
            minKey = keyTimes[i][0];
        }
    }
    return 'a' + minKey;
}