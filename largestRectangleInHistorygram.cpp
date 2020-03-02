#include "globals.h"

int largestRectangleArea(vector<int>& heights) {
	stack<int> s;
	uint index = 0;
	int largest = 0;

	while(index <= heights.size()) {
		while(!s.empty() && (index == heights.size() || heights[index] < heights[s.top()])) {
			int curr = s.top();
			s.pop();
			int area = heights[curr] * (index-1-(s.empty() ? -1 : s.top()));
			if(area > largest) {
				largest=area;
			}
		}
		s.push(index++);
	}
	return largest;
}
