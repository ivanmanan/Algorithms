/*

Given a set list of pickups and deliveries for order, figure out if the given list is valid or not.
A delivery cannot happen for an order before pickup.


[P1, P2, D1, D2]==>valid
[P1, D1, P2, D2]==>valid
[P1, D2, D1, P2]==>invalid
[P1, D2]==>invalid
[P1, P2]==>invalid
[P1, D1, D1]==>invalid
[]==>valid
[P1, P1, D1]==>invalid
[P1, P1, D1, D1]==>invalid
[P1, D1, P1]==>invalid
[P1, D1, P1, D1]==>invalid

*/

#include "../Algorithms/globals.h"
#include <iostream>
using namespace std;

bool validateOrdersPath(vector<string> ordersPath) {

    unordered_set<int> pickups;
    unordered_set<int> deliveries;

    for(auto it = ordersPath.begin(); it != ordersPath.end(); it++) {
        string order = (*it).substr(0,1);
        int num = stoi((*it).substr(1, (*it).length()-1));
        // TODO: Figure out if pickups and deliveries must be done in ascending order
        if(order == "P") {
            if(pickups.find(num) != pickups.end()) {
                // Delivery exists
                return false;
            }
            pickups.insert(num);
        }
        else if(order == "D") {
            if(pickups.find(num) == pickups.end() || deliveries.find(num) != deliveries.end()) {
                // Pickup was not handled yet OR there is a duplciate already
                return false;
            }
            else {
                deliveries.insert(num);
            }
        }
    }
    return pickups.size() == deliveries.size();
}

void runTest(vector<string> test, bool expected) {
    bool res = validateOrdersPath(test);

    cout << "INPUT: [ ";
    for(auto it = test.begin(); it != test.end(); it++) {
        cout << *it << " ";
    }
    cout << "];";
    cout << " ANSWER: " << res << "; EXPECTED: " << expected << endl;

}

int main() {
    cout << "HELLO!" << endl;
    vector<string> test1 = {"P1", "P2", "D1", "D2"};
    vector<string> test2 = {"P1", "D1", "P2", "D2"};
    vector<string> test3 = {"P1", "P1", "D1", "D1"};
    vector<string> test4 = {"P1", "D2", "D1", "P2"};

    runTest(test1, true);
    runTest(test2, true);
    runTest(test3, false);
    runTest(test4, false);
}
