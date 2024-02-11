// Easy: Verify Alien dictionary

bool isAlienSorted(vector<string>& words, string order) {
    // Key: letter, value: weight
    unordered_map<char,int> ma;
    for(int i = 0; i < order.size(); i++) {
        ma[order[i]] = i;
    }

    for(int i = 0; i < words.size(); i++) {
        if(i+1 < words.size()) {
            string word1 = words[i];
            string word2 = words[i+1];

            // Compare each char in the word
            int j = 0;
            while(j < word1.length() && j < word2.length()) {
                int weight1 = ma[word1[j]];
                int weight2 = ma[word2[j]];
                cout << "CH: " << word1[j] << ", W1: " << weight1 << "; CH: " << word2[j] << ", W2: " << weight2 << endl;
                if(weight1 < weight2) {
                    break;
                }
                if(weight1 > weight2) {
                    return false;
                }
                j++;
            }
            // leetcodeg, leetcode
            if(word1.substr(0,j) == word2.substr(0,j)) {
                if(word1.length() > word2.length()) {
                    return false;
                }
            }
        }
    }
    return true;
}

// Hard: Alien dictionary
