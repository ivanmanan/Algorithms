#include <iostream>
#include <string>
#include <vector>
#include <unorderd_map>

using namespace std;


// Complete the decode function below.
string decode(vector<string> codes, string encoded) {

    string solution = "";
    unordered_map<string, string> code_map;

    for (auto code = codes.begin(); code != codes.end(); code++) {

        string s = *code;

        int index = s.find("\t");
        string value = s.substr(0, index);

        if (value == "[newline]") {
            value = "\n";
        }

        string key = s.substr(index+1, s.length());

        //cout << "Key: " << key << ", Value: " << value << endl;

        code_map.insert({key, value});
    }

    int start_index = 0;
    //cout << "Encoded Length: " << encoded.length() << endl;
    for (int i = 0; start_index + i <= encoded.length(); i++) {

        //cout << start_index << endl;
        string potential_code = encoded.substr(start_index, i);

        cout << potential_code << endl;

        auto got = code_map.find(potential_code);
        if (got != code_map.end()) {
            solution += got->second;
            start_index += i;
            i = 0;
        }

    }

    return solution;

}

