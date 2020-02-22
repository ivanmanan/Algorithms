#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'minSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY num
 *  2. INTEGER k
 */

int minSum(vector<int> num, int k) {

    // PROCESS: Always find the maximimum element, and halve it

    // Create a max heap
    priority_queue<int> max_heap;

    // Heapify array
	// Every insertion takes O(log N) time
	// for-loop is N times
	// Thus, heap sort is O(N log N)
    for(int i = 0; i < num.size(); i++) {
        max_heap.push(num[i]);
    }

    for(int i = 0; i < k; i++) {
        int max = max_heap.top();
        max_heap.pop();

        // Round and insert new element into the heap
        double value = (double)max/(double)2;
        int new_element = round(value);
        max_heap.push(new_element);
    }

    int sum = 0;
    while(!max_heap.empty()) {
        sum += max_heap.top();
        max_heap.pop();
    }
    return sum;
}

int main()