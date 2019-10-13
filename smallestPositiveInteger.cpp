#include <unordered_set>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    unordered_set<int> nums(A.begin(), A.end());
    int i;
    for(i = 1; i <= nums.size(); i++) {
        auto got = nums.find(i);
        if(got == nums.end()) {
            return i;
        }
    }
    return i;
}