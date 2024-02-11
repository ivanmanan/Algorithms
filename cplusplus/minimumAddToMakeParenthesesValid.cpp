/*
    EXAMPLE:
    ))(()(
    Output: 4
    )) --> count=2
    STACK: [(, (]
    ) --> pop top of stack
    STACK: [(, (]
    Sum leftover open parenthesis and stack size
*/
int minAddToMakeValid(string s) {
    stack<char> st;
    int unclosed_parentheses = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') {
            st.push(s[i]);
        }
        else if(s[i] == ')') {
            if(st.empty()) {
                unclosed_parentheses++;
            }
            else {
                st.pop();
            }
        }
    }
    return st.size() + unclosed_parentheses;
}
