/*
stack is FILO

[
    (, t
    (, lee
]

Encounter "c)", so pop and append top of stack
t(c).

Stack:
[
    (, lee
]
curr = "t(c)"

curr = "t(c)o)"
Pop stack.
curr = "lee(t(c)o)"
curr =lee(t(c)o)de
--> run into unclosed ")", but stack is empty.
So, we can discard

What if we have excess "((("
s="(((hello)(b"

curr = "(hello)"
[
    (hello)
    ""
    ""
]

curr = "b" --> "(hello)b"

If stack is not empty, then we want to discard the open parentheses and prepend to res string

*/
string minRemoveToMakeValid(string s) {
    stack<string> st;
    string res = "";
    for(auto& ch: s) {
        if(ch == '(') {
            st.push(res);
            res = "";
        }
        else if(ch == ')') {
            if(st.empty()) {
                // Discard unclosed parenthesis
                continue;
            }
            else {
                res = st.top() + '(' + res + ')';
                st.pop();
            }
        }
        else {
            res += ch;
        }
    }
    while(!st.empty()) {
        res = st.top() + res;
        st.pop();
    }
    return res;
}
