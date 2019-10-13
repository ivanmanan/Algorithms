#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'getSpreadsheetNotation' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts LONG_INTEGER n as parameter.
 */

 // Every new row begins with (r-1)*702 multiplier

string getSpreadsheetNotation(long n) {

    // Find the row number
    int r = n/702 + 1;
    // Edge case if number is fully divisible
    if(n % 702 == 0) {
        r--;
    }

    // Find the column label
    int c = n % 702;

    // First column letter:
    int division = c / 26;
    string firstLetter = "";
    if(division != 0) {
        char letterOne = (char) (division + 64);
        firstLetter = string(1, letterOne);
    }
    // Edge case if number is fully divisible
    if(c == 0) {
        firstLetter = "Z";
    }

    // Second column letter
    int remainder = c % 26;
    string secondLetter = "";
    // Edge case if number is fully divisible
    if(c == 0) {
        secondLetter = "Z";
    }
    else {
        char letterTwo = (char) (remainder + 64);
        secondLetter = string(1, letterTwo);
    }
    return to_string(r) + firstLetter + secondLetter;
}

int main()