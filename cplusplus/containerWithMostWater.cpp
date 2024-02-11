int maxArea(vector<int>& height) {
    /*
        Start by evaluating the widest container, using
        the first and the last line. All other possible
        containers are less wide, so to hold more water,
        they need to be higher
    */

    int i = 0;
    int j = height.size()-1;
    int res = 0;

    // NOTE: Move pointer to the larger height
    while(i < j) {

        int area = (j-i) * min(height[i], height[j]);
        res = max(res, area);

        if(height[i] <= height[j]) {
            // Greedily iterate pointer that is currently
            // on the lower height
            i++;
        }
        else {
            j--;
        }
    }
    return res;
}
