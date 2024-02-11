/*
abc: 1-2-3
bcd: 2-3-4

Take difference between values
abc: 2-1=1, 3-2=1 --> 1-1
bcd: 3-2=1, 4-3=1 --> 1-1

cba: 3-2-1
2-3=-1, 1-2=-1 --> 25-25

Edge case
yza: 25-26-1
26-25=1, 1-26=-25
If negative, then add by 26

Key: "1-1"
map: {
    "1-1": [abc, bcd]
}
*/
vector<vector<string>> groupStrings(vector<string>& strings) {
    vector<vector<string>> res;
    unordered_map<string, vector<string>> ma;

    for(auto& s: strings) {
        string key = "";
        if(s.length() == 1) {
            key = "1";
        }
        for(int i = 1; i < s.length(); i++) {
            int val = s[i] - s[i-1]; // Calculate ASCII code
            if(val < 0) {
                val += 26;
            }
            key += (val + '0') + '-';
        }
        ma[key].push_back(s);
    }

    for(auto& it: ma) {
        cout << "KEY: " << it.first;
        cout << "; CONTENTS: ";
        for(auto& temp: it.second) {
            cout << temp << " ";
        }
        cout << endl;
        res.push_back(it.second);
    }
    return res;
}
