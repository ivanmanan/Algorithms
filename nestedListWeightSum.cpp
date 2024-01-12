// Let N = number of nested elements
// Example: [ [[[[1]]]], 2 ] contains 4 nested lists and 2 nested integers
// So, N=6
// TIME: O(N)
// SPACE: O(N) --> at most O(D) [D=depth] recursive calls made, but D can equal N
int navigateDepth(vector<NestedInteger>& nestedList, int depth) {
    int sum = 0;
    for(auto& nestedInt: nestedList) {
        if(nestedInt.isInteger()) {
            sum += depth * nestedInt.getInteger();
        }
        else {
            sum += navigateDepth(nestedInt.getList(), depth+1);
        }
    }
    return sum;
}

int depthSum(vector<NestedInteger>& nestedList) {
    int res = navigateDepth(nestedList, 1);
    return res;
}
