#include "globals.h"

/*
  Three problems:
  1. Simple string expression
  2. Basic Calculator I from Leetcode
  3. Basic Calculator II from Leetcode
 */
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// HARD BASIC CALCULATOR III
/*
    Calculate inner-most parentheses first

    2*(5+5*2)/3+(6/2+8)

    1+2*(3+4*5)/6-(1*(7+8)*9) = -126


    2*(3+3) = 2*6

    currStack: [1,2]
    Reached '('
    parenthesesStack: [<[1,2],*>]

    currStack: [3,20]
    Reached ')'
    [1,2] * [3,20]

    180/6=30

    currStack: [30]

    parenthesesStack: [<[30],->]

    currStack: [1]

    parenthesesStack: [<[30],->,<[1],*>]

    7+8=15
    Reached first ')'

    1*15=15

*/

void evaluate(int curr, stack<int>& st, char op) {
    if(op == '+') {
        st.push(curr);
        cout << op << curr << endl;
    }
    else if(op == '-') {
        st.push(-curr);
        cout << op << curr << endl;
    }
    else if(op == '*') {
        cout << st.top() << op << curr << endl;
        curr = st.top() * curr;
        st.pop();
        st.push(curr);
    }
    else if(op == '/') {
        cout << st.top() << op << curr << endl;
        curr = st.top() / curr;
        st.pop();
        st.push(curr);
    }
}

int calculate(string s) {
    char op = '+';
    int curr = 0;
    stack<int> st;
    stack<pair<stack<int>,char>> parenthesesStack;
    s += '+';
    for(auto& ch: s) {
        if(isdigit(ch)) {
            curr = curr * 10 + (ch - '0');
        }
        else if(ch == ' ') {
            continue;
        }
        else if(ch == '(') {
            if(st.empty()) {
                // If s=(1+2), then push 0
                st.push(0);
            }
            parenthesesStack.push(make_pair(st, op));
            op = '+';
            st = stack<int>(); // Empty stack
        }
        else if(ch == ')') {
            // Need to evaluate remaining digit first
            evaluate(curr, st, op);

            // Evaluate both current and parenthesesStack
            stack<int> prevs = parenthesesStack.top().first;
            op = parenthesesStack.top().second;
            parenthesesStack.pop();

            int right = 0;
            while(!st.empty()) {
                right += st.top();
                st.pop();
            }
            // Consider 1+1+2*(1+1) --> cannot evaluate entire left stack first
            int left = prevs.top();
            prevs.pop();

            st.push(left);
            evaluate(right, st, op);
            curr = st.top();
            cout << curr << endl;
            st.pop(); // This handles multi/division after closing bracket

            while(!prevs.empty()) {
                st.push(prevs.top());
                prevs.pop();
            }

            op = '+';
            // 2*(3+4)-5 = 2*7 - 5
            // st: [14], but ch='-'. Will be fine b/c curr=0

            // 2*(15)/3 --> cannot push 0 necessarily
        }
        else {
            evaluate(curr, st, op);
            op = ch;
            curr = 0;
        }
    }
    int res = 0;
    while(!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}





///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// HARD BASIC CALCULATOR I


/*
    (1-(2+3)-4) = -8

    i=0: (
    i=1: 1
    i=2: -

    i=3: ( --> Push to stack
    [<1,(-)>]

    i=6: 2+3=5
    i=7: ) --> Pop stack, 1-5=-4
    i=9: -4-4 = -8
    i=10: Stack is empty. That's okay

*/
int calculate(string s) {
    stack<pair<int,int>> st;
    int sign = 1;
    int curr = 0;
    int currSum = 0;
    s += '+';
    for(auto& ch: s) {
        if(isdigit(ch)) {
            curr = curr * 10 + (ch - '0');
        }
        else if(ch == '+') {
            currSum += sign*curr;
            curr = 0;
            sign = 1;
        }
        else if(ch == '-') {
            currSum += sign*curr;
            curr = 0;
            sign = -1;
        }
        else if(ch == '(') {
            st.push(make_pair(currSum, sign));
            currSum = 0;
            curr = 0;
            sign = 1;
        }
        else if(ch == ')') {
            // Evaluate from top of stack
            int top = st.top().first;
            int prev_sign = st.top().second;
            st.pop();
            currSum = top + prev_sign * (currSum + sign*curr);
            sign = 1;
            curr = 0;
        }
        else {
            continue;
        }
    }
    return currSum;
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// MEDIUM BASIC CALCULATOR II

int basicCalculatorII(string s) {
    stack<int> st;
    int curr = 0;
    char op = '+';
    s += '+'; // Finale is necessary

    for(int i = 0; i < s.length(); i++) {
        if(isdigit(s[i])) {
            curr = curr * 10 + int(s[i] - '0');
        }
        else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/') {
            if(op == '+') {
                st.push(curr);
            }
            else if(op == '-') {
                st.push(-curr);
            }
            else if(op == '*') {
                int num = st.top() * curr;
                st.pop();
                st.push(num);
            }
            else if(op == '/') {
                int num = st.top() / curr;
                st.pop();
                st.push(num);
            }
            op = s[i];
            curr = 0;
        }

    }

    int res = 0;
    while(!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}

int main() {
    // cout << calculator("10+4-3") << endl;
    // cout << calculator("205+310-105") << endl;

// 	int ans = basicCalculatorII("3+2*2");
// 	cout << "INPUT: 3+2*2; OUTPUT: " << ans << "; EXPECTED: 7";

    int ans = basicCalculatorII("1337");
    cout << "INPUT: 1337; OUTPUT: " << ans << "; EXPECTED: 1337";
}
