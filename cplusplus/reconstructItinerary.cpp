#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
  Input:
  [LAX]
  [[LAX,SEA], [SEA, SFO], [SFO, SJC], [SJC, LAX], [LAX, HOU]]

  Output:
  [LAX SEA SFO SJC LAX HOU]

  Given list of tickets with departure/arrival [from, to],
  reconstruct the itinerary in order.
*/


/*
  To solve duplicate cases, you need to do backtracking.
  https://en.wikipedia.org/wiki/Topological_sorting#Depth-first_search

  It is possible to do topological sorting with DFS.
 */

// TODO: Implement this algorithm
// See Leetcode solutions
// https://leetcode.com/problems/reconstruct-itinerary/discuss/?currentPage=1&orderBy=most_relevant&query=C%2B%2B


// NOTE: This works for non-duplicate locations
vector<string> findItineraryWithoutDuplicates(vector<vector<string>>& tickets) {

	// Create Hash Table with key:value {FROM:TO}
	unordered_map<string, string> fromToMap;
	for(int i = 0; i < tickets.size(); i++) {
		fromToMap.insert({tickets[i][0], tickets[i][1]});
	}

	// Create reverse Hash Table with key:value {TO:FROM}
	unordered_map<string, string> toFromMap;
	for(int i = 0; i < tickets.size(); i++) {
		toFromMap.insert({tickets[i][1], tickets[i][0]});
	}

	// Traverse the tickets array. If the FROM destination does not exist
	// in the {TO:FROM} map, then that is the starting location

	string location;
	for(int i = 0; i < tickets.size(); i++) {

		auto got = toFromMap.find(tickets[i][0]);
		if(got == toFromMap.end()) {
			location = tickets[i][0];
			break;
		}
	}

	vector<string> itinerary;
	auto ticket = fromToMap.find(location);
	itinerary.push_back(location);
	while(ticket != fromToMap.end()) {


		location = ticket->second;
		itinerary.push_back(location);
		ticket = fromToMap.find(location);

	}

	return itinerary;

}