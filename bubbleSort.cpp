#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> nums) {
	uint i,j;
	for(i = 0; i < nums.size() - 1; i++) {
		for(j = 0; j < nums.size() - i - 1; j++) {
			if(nums[j] > nums[j+1]) {
				swap(nums[j], nums[j+1]);
			}
		}
	}
}