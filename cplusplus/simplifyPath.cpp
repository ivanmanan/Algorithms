string simplifyPath(string path) {
    stack<string> st;

    string curr = "";
    path += "/"; // Easier to debug "/path/to/.."
    for(int i = 0; i < path.length(); i++) {
        if(path[i] == '/') {
            if(i-1 >= 0) {
                if(path[i-1] == '/') {
                    // Consecutive //
                    continue;
                }
                else if(curr == ".") {
                    // e.g. /path/./trail
                    curr = "";
                    continue;
                }
                else if(curr == "..") {
                    // e.g. /path/../ -> /
                    // stack contains:
                    // ["/", "path", "/"]
                    curr = "";
                    if(!st.empty()) {
                        cout << st.top() << endl;
                        st.pop();
                    }
                    if(!st.empty()) {
                        st.pop();
                    }
                    if(st.empty()) {
                        // Make up in case of "/../"
                        st.push("/");
                    }
                    continue;
                }
            }
            st.push(curr);
            st.push(string(1,path[i])); // char->str
            curr = "";
        }
        else {
            curr += path[i];
        }
    }
    if(path[path.length()-1] != '/') {
        // Need to push last string
        // e.g. "/path/." OR "/path/hello.txt"
        st.push(curr);
    }
    string res = "";

    while(!st.empty()) {
        res = st.top() + res;
        st.pop();
    }
    // Remove trailing '/'
    if(res != "" && res[res.length()-1] == '/' && res.length() != 1) {
        res = res.substr(0, res.length()-1);
    }
    return res;
}
