/*
    encoded1 = [[1,3],[2,1],[3,2]] -> [1,1,1,2,3,3]
    encoded2 = [[2,3],[3,3]]       -> [2,2,2,3,3,3]
    product =                         [2,2,2,6,9,9]
    output = [[2,3],[6,1],[9,2]]
*/
vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
    vector<vector<int>> encoded;
    int i = 0;
    int j = 0;
    int prev_num;

    while(i < encoded1.size() && j < encoded2.size()) {
        int num1 = encoded1[i][0];
        int freq1 = encoded1[i][1];

        int num2 = encoded2[j][0];
        int freq2 = encoded2[j][1];

        int prod = num1 * num2;
        int freq = min(freq1,freq2);
        if(encoded.empty() || prod != prev_num) {
            encoded.push_back({prod, freq});
        }
        else {
            encoded[encoded.size()-1][1] = encoded[encoded.size()-1][1] + freq;
        }
        prev_num = prod;

        if(freq1 == freq2) {
            i++;
            j++;
        }
        else if(freq1 > freq2) {
            // In-place edit of freq
            encoded1[i][1] = freq1 - freq2;
            j++;
        }
        else {
            encoded2[j][1] = freq2 - freq1;
            i++;
        }
    }

    return encoded;
}
