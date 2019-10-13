#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

string electionWinner(vector<string> votes) {

    if (votes.empty()) {
        return "";
    }

    unordered_map<string, int> votes_set;
    for (auto name = votes.begin(); name != votes.end(); name++) {

        // See if candidate already received votes
        auto got = votes_set.find(*name);

        if (got == votes_set.end()) {
            // Candidate not found in hash table
            // So insert candidate with first vote
            votes_set.insert({*name, 1});
        }
        else {
            // Replace key/value pair with new vote
            int value = got->second;
            value++;
            votes_set.erase(*name);
            votes_set.insert({*name, value});
        }
    }

    vector<string> popular_candidates;

    // Find candidates with greatest number of votes
    for (auto candidate = votes_set.begin(); candidate != votes_set.end(); candidate++) {
        if (popular_candidates.empty()) {
            popular_candidates.push_back(candidate->first);
        }
        else {
            // Compare the current candidates in the vector
            auto current_candidate = votes_set.find(popular_candidates[0]);

            if (candidate->second > current_candidate->second) {
                // Clear the vector, insert new candidate
                popular_candidates.clear();
                popular_candidates.push_back(candidate->first);
            }
            else if (candidate->second == current_candidate->second) {
                popular_candidates.push_back(candidate->first);
            }
        }
    }

    // If tie, sort by alphabetical order and return candidate
    sort(popular_candidates.rbegin(), popular_candidates.rend());
    return popular_candidates[0];
}

int main() {
	vector<string> votes;
	votes.push_back("Marco");
	votes.push_back("Marco");
	votes.push_back("Marco");
	votes.push_back("Rubin");
	votes.push_back("Rubin");
	votes.push_back("Biden");
	votes.push_back("Biden");
	votes.push_back("Biden");

	string winner = electionWinner(votes);

	cout << "Winner of the election is: " << winner << endl;
}