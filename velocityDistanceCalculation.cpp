#include <vector>
#include <iostream>

using namespace std;

double solution(vector< vector< double > > readings, long endTime) {

    double distance = 0;
    int i = 0;
    double rate;

    for(; i < readings.size() - 1; i++) {
        // Calculate distance between velocity changes
        rate = readings[i][1] / 3600;
        double diff = readings[i+1][0] - readings[i][0];
        endTime -= diff;
        distance += rate * diff;
    }

    // Take remaining endTime and calculate final distance
    rate = readings.back()[1] / 3600;
    distance += rate * double(endTime);


    return distance;
}

int main() {
	vector<vector<double>> readings;
	vector<double> temp;
	temp.push_back(0);
	temp.push_back(90);
	readings.push_back(temp);
	long endTime = 600;

	double ans = solution(readings, endTime);
	cout << ans << endl;
}