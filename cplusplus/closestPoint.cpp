#include <vector>
#include <iostream>

using namespace std;

long solution(vector< vector< long > > clients) {

    // Find the smallest x and largest x values
    // find the smallest y and largest y values
    // Take difference and sum

    long minX = clients[0][0];
    long maxX = clients[0][0];
    long minY = clients[0][1];
    long maxY = clients[0][1];

    for(uint i = 0; i < clients.size(); i++) {

        if(minX > clients[i][0]) {
            minX = clients[i][0];
        }
        if(maxX < clients[i][0]) {
            maxX = clients[i][0];
        }
        if(minY > clients[i][1]) {
            minY = clients[i][1];
        }
        if(maxY < clients[i][1]) {
            maxY = clients[i][1];
        }
    }
	long diffX = abs(maxX - minX);
	long diffY = abs(maxY - minY);
	return (diffX + diffY);
}


int main() {
	vector<vector<long>> input;

	vector<long> insert1;
	insert1.push_back(1);
	insert1.push_back(0);

	vector<long> insert2;
	insert1.push_back(1);
	insert1.push_back(1);

	input.push_back(insert1);
	input.push_back(insert2);

	cout << solution(input) << endl;
}