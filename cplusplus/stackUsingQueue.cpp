#include "globals.h"


// Can either make the push operation O(N) or pop operation O(N) time complexity
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res;
        while(!q1.empty()) {
            res = q1.front();
            q1.pop();
            if(!q1.empty()) {
                q2.push(res);
            }
        }
        swap(q1,q2);
        return res;
    }

    /** Get the top element. */
    int top() {
        return q1.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }

private:
    queue<int> q1;
    queue<int> q2;
};