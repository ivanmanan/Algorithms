#include <iostream>
#include <vector>

using namespace std;

int trap(vector<int>& height) {
    int i = 0;
    int j = height.size()-1;

    int maxLeft = height[i];
    int maxRight = height[j];

    int res = 0;

    while(i < j) {
        if(maxLeft <= maxRight) {
            i++;
            maxLeft = max(maxLeft, height[i]);
            res += maxLeft-height[i];
        }
        else {
            j--;
            maxRight = max(maxRight, height[j]);
            res += maxRight-height[j];
        }
    }

    return res;
}
