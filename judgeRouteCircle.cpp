// Determine if the robot moves in a circle
// i.e. moves back to its original position of (0,0)

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
		int x = 0;
		int y = 0;

		// Convert string to an array of char's
		int n = moves.length();
		char char_array[n+1];
		strcpy(char_array, moves.c_str());

		for (int i = 0; i < n; i++) {
			cout << char_array[i] << endl;
		}

        for (unsigned i = 0; i < n; i++) {
			if (char_array[i] == 'U')
				y++;
			else if (char_array[i] == 'D')
				y--;
			else if (char_array[i] == 'R')
				x++;
			else if (char_array[i] == 'L')
				x--;
			else
				continue;
        }

		if (x == 0 && y == 0) {
			return true;
		}
		else
			return false;
    }
};

int main() {
	Solution answer;

	if (answer.judgeCircle("UD")) {
		cout << "Solution works!" << endl;
	}
	else
		cout << "Solution failed." << endl;
}