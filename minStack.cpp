#include "globals.h"

class MinStack {
public:
    MinStack() {}

    void push(int x) {
		if(st.empty()) {
			currMin = x;
		}
		currMin = min(x, currMin);
		pair<int,int> p(x, currMin);
		st.push(p);
    }

    void pop() {
		st.pop();
		if(!st.empty()) {
			pair<int,int> p = st.top();
			currMin = p.second;
		}
    }

    int top() {
		pair<int,int> p = st.top();
		return p.first;
    }

    int getMin() {
        return currMin;
    }

	// Pair is value:current_minimum
	stack<pair<int,int>> st;
	int currMin;
};