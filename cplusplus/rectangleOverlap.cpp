#include "globals.h"

bool isRectangleOverlap(vector<int>& r1, vector<int>& r2) {
    return (r2[0] > r1[0] && r2[0] < r1[2]
            || r2[2] > r1[0] && r2[2] < r1[2]
            || r2[0] <= r1[0] && r2[2] >= r1[2])
        && (r2[1] > r1[1] && r2[1] < r1[3]
            || r2[3] > r1[1] && r2[3] < r1[3]
            || r2[1] <= r1[1] && r2[3] >= r1[3]);
}
