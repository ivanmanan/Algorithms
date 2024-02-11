// https://www.geeksforgeeks.org/find-maximum-meetings-in-one-room/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Sort based on meeting's end time
bool comp(pair<int,int> m1, pair<int,int> m2) {
    return m1.second < m2.second;
}

void print(vector<pair<int,int>> m) {
    for(int i = 0; i < m.size(); i++) {
        cout << "First: " << m[i].first << "; Second: " << m[i].second << endl;
    }
}

int countMeetings(vector<int> arrival, vector<int> departure) {

    vector<pair<int, int>> meetings;

    // Store all meetings into a single vector
    for(int i = 0; i < arrival.size(); i++) {
        pair<int, int> m;
        m.first = arrival[i]; // start time
        m.second = departure[i]; // end time
        meetings.push_back(m);
    }

    // Sort meetings based on ending time
    sort(meetings.begin(), meetings.end(), comp);

    print(meetings);

    // Select first meeting's end time
    int maxTime = meetings[0].second;
    int maxMeetings = 1;

    for(int i = 1; i < arrival.size(); i++) {

        cout << "Comparing: " << meetings[i].first << " >= " << maxTime << endl;
        if(meetings[i].first >= maxTime) {
            maxTime = meetings[i].second;
            maxMeetings++;
        }
    }
    return maxMeetings;
}

int main() {
    vector<int> arrival = {1, 10, 11};
    vector<int> departure = {11, 10, 11};
    cout << countMeetings(arrival, departure) << endl;
}