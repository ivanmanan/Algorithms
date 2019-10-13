#include <iostream>
#include <vector>
#include <stack>
using namespace std;

string parseBraces(string braces) {

    stack<char> s;

    for (int i = 0; i < braces.length(); i++) {

        // If brace is either of '[({'
        if (braces[i] == '[' || braces[i] == '(' || braces[i] == '{') {
            s.push(braces[i]);
        }
        // Otherwise, brace is '})]'
        else {

            // No corresponding brace exists
            if (s.empty()) {
                return "NO";
            }

            // Check if top of stack corresponds to the closing brace
            // If not, then continue through the for-loop
            char top = s.top();
            switch(braces[i]) {
                case ']':
                    if (top == '[') {
                        s.pop();
                    }
                    else {
                        return "NO";
                    }
                    break;
                case '}':
                    if (top == '{') {
                        s.pop();
                    }
                    else {
                        return "NO";
                    }
                    break;
                case ')':
                    if (top == '(') {
                        s.pop();
                    }
                    else {
                        return "NO";
                    }
                    break;
                default:
                    continue;
            }


        }
    }

    // This indicates an imbalanced brace expression
    if (!s.empty()) {
        return "NO";
    }
    else {
        return "YES";
    }
}


vector<string> braces(vector<string> values) {

    vector<string> solution;

    // For each string in the vector, parse the braces
    for (auto s = values.begin(); s != values.end(); s++) {
        string answer = parseBraces(*s);
        solution.push_back(answer);
    }
    return solution;
}



int main() {
	vector<string> input;
	string s1 = "[][][]{}(){([[([{}])]])}";
	string s2 = "[({})][";
	string s3 = "[([)]]";


	input.push_back(s1);
	input.push_back(s2);
	input.push_back(s3);

	vector<string> solution = braces(input);

	for (auto it = solution.begin(); it != solution.end(); it++) {
		cout << *it << endl;
	}
}