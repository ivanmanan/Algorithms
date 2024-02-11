#include "globals.h"

vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
	sort(arr.begin(),arr.end());
	vector<vector<int>> res;
	int currDiff =INT_MAX;
	short t;
	for(int i=0; i < arr.size()-1; i++){
		t = abs(arr[i]-arr[i+1]);
		if(t <= currDiff){
			if(t < currDiff) {
				currDiff = t;
				res.clear();
			}
			res.push_back({arr[i],arr[i+1]});
		}
	}
	return res;
}
