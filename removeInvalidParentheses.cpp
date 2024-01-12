/*

BFS vs DFS:
BFS is good if the required minimal deletions is small. However,
if there is a huge number of deletions required, then the queue
takes up O(2^N).
DFS space is O(N) because the call stack space is just the
number of characters that can be removed at a time.

N = length of string

For each parentheses, we can either:
1) Remove
2) Keep

There are 2^N possible sets.

Time: O(2^N)
--> We only call isValid() function based on the
SPACE: O(2^N)

The maximum size of the queue can be at most O(2^n), as there
can be up to 2^n valid combinations of parentheses

The size of the visited set can also be up to O(2^n), as each
valid combination can potentially be a unique string.

s = "()())", N=5
We have 2^5=32 possible subsets to explore

However, we only call isValid() to the unique subsets:
"("
")"
"()"
"(())"
"()()"

2^N = number of subsets

*/
vector<string> removeInvalidParentheses(string s) {
    vector<string> res;
    queue<string> q;
    unordered_set<string> visited;
    q.push(s);


    while(!q.empty()) {
        string curr = q.front();
        q.pop();

        if(!res.empty() && curr.length() < res[0].length()) {
            // Terminate since shorter than the minimum removals
            continue;
        }

        if(isValid(curr)) {
            res.push_back(curr);
            continue;
        }

        for(int i = 0; i < curr.length(); i++) {
            // Remove the current character and attempt again
            string attempt = curr.substr(0, i) + curr.substr(i+1);
            if(visited.find(attempt) == visited.end()) {
                visited.insert(attempt);
                q.push(attempt);
            }
        }
    }
    return res;
}

bool isValid(string s) {
    int open_parentheses = 0;
    for(auto& ch: s) {
        if(ch == '(') {
            open_parentheses++;
        }
        else if(ch == ')') {
            open_parentheses--;
            if(open_parentheses < 0) {
                return false;
            }
        }
        else {
            continue;
        }
    }
    return open_parentheses == 0;
}
