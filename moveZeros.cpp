#include <iostream>
#include <vector>

using namespace std;

/*
  Ex. given [1,0,0,1]

  [1,0,0,1]
  [1]
  [1,0]
  [1,0,0]
  [1,1,0,0] --> curr pointer is at i=3,
                but lastNonZeroFoundAt is at i=1
				so we swap the two eleemnts at i=1,i=3
 */
void moveZerosOptimal(vector<int>& nums) {
	for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
		if (nums[cur] != 0) {
			swap(nums[lastNonZeroFoundAt++], nums[cur]);
		}
	}
}

void moveZeroesSlightlyOptimal(vector<int>& nums) {
	int lastNonZeroFoundAt = 0;
	for(int i = 0; i < nums.size(); i++) {
		if(nums[i] != 0) {
			nums[lastNonZeroFoundAt++] = nums[i];
		}
	}
	for(int i = lastNonZeroFoundAt; i < nums.size(); i++) {
		nums[i] = 0;
	}
}

/*
  Create a new array
  Insert all the nonzeros into the vector
  Then fill the rest of the vector with zeros
*/
void moveZeroesSubOptimal(vector<int>& nums) {
	int countZeros = 0;
	vector<int> ans;

	for(int i = 0; i < nums.size(); i++) {
		if(nums[i] != 0) {
			ans.push_back(nums[i]);
		}
		else {
			countZeros++;
		}
	}
	while(countZeros > 0) {
		ans.push_back(0);
		countZeros--;
	}
	swap(nums, ans);
}
