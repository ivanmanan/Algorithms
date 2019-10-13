#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;


/*
  Ex. Given  [(1,2), (2,3), (3,4), (3,6), (4,5)]
      Output [(1,2), (3,6), (4,5)]
  These servers are connected to each other end-to-end
  I want to determine which servers have critical connections, which means
  disconnecting that connection results in disconnection of the network

  SOLUTION
  Create a graph

  Use BFS and check if node has been visited
  --> if we see a node already visited, then a cycle is detected

 */






// MY ATTEMPT
vector<pair<int, int> > criticalConnections(int numOfServers,
                                           int numOfConnections,
                                           vector<pair<int, int> > connections)
{
    vector<pair<int,int>> criticals;

    unordered_map<int, vector<pair<int,int>>> connectionsMap;

    for(int i = 0; i < connections.size(); i++) {

        int firstNum = connections[i].first;
        int secondNum = connections[i].second;

        auto gotOne = connectionsMap.find(firstNum);
        auto gotTwo = connectionsMap.find(secondNum);

        pair<int,int> pairNums(firstNum, secondNum);

        if(gotOne == connectionsMap.end()) {
            vector<pair<int,int>> connectsOne;
            connectsOne.push_back(pairNums);
            connectionsMap.insert({firstNum, connectsOne});
        }
        else {
            // gotOne is a pointer to the pair from hash table
            (gotOne->second).push_back(pairNums);
        }

        if(gotTwo == connectionsMap.end()) {
            vector<pair<int,int>> connectsTwo;
            connectsTwo.push_back(pairNums);
            connectionsMap.insert({secondNum, connectsTwo});
        }
        else {
            // gotTwo is a pointer to the pair from hash table
            (gotTwo->second).push_back(pairNums);
        }
    }

    while(numOfConnections > 0) {

        // Find servers with single connections
        for(auto it = connectionsMap.begin(); it != connectionsMap.end(); it++) {
            if((it->second).size() == 1) {
                criticals.push_back((it->second)[0]);

                // Update hash table by removing the critical connection pair

                // Remove pair from the rest of the hash table
                for(auto ite = connectionsMap.begin(); ite != connectionsMap.end(); ite++) {
                    for(int j = 0; j < (ite->second).size(); j++) {

						cout << "Hello!" << endl;
						/*
                        if((ite->second)[j] == (it->second)[0]) {
                            (ite->second).erase((ite->second).begin() + j);
                        }
						*/
                    }
                }


                // Remove critical connection from hash table
                connectionsMap.erase(it->first);
				break;

            }
        }

        numOfConnections--;

    }


    return criticals;
}

int main() {
	vector<pair<int,int>> arg;

	pair<int,int> pairOne(1,2);
	pair<int,int> pairTwo(2,3);

	arg.push_back(pairOne);
	arg.push_back(pairTwo);

	vector<pair<int, int>> ans = criticalConnections(6, 5, arg);

	for(uint i = 0; i < ans.size(); i++) {
		cout << ans[i].first  << ", " << ans[i].second << endl;
	}
}