/*
    s="leetcode"

    s.length()=8
    dp[8] = true # Always true

    dp[7] = false # no word found
    dp[6] = false
    dp[5] = false
    dp[4] = dp[4+4] --> i=4, i=4+4=8
    dp[3] = false
    dp[2] = false
    dp[1] = false
    dp[0] = dp[0+4] # word is found

    N = length of string s
    M = number of words in wordDict
    k = largest length of words in wordDict
    SPACE: O(N) --> bool dp array
    TIME: O(N * M * K)

    It takes O(M*K) time to calculate each state since we cycle through
    every word in the word dictionary, get its length, and take substring.
    Calling s.substr() takes O(K) time.
    We calculate O(N) states in total

*/
bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.length()+1, false);
    dp[s.length()] = true;
    for(int i = s.length()-1; i >= 0; i--) {
        // Attempt every word in the dictionary
        for(auto& word: wordDict) {
            int word_length = word.length();
            if(i + word_length <= s.length()) {
                if(s.substr(i, word_length) == word) {
                    dp[i] = dp[i + word_length];
                }
            }
            if(dp[i]) {
                break;
            }
        }
    }
    return dp[0];
}


/*
    WORD BREAK II
*/

/*
    s = "catsanddog"
    Dict = {"cat","cats","and","sand","dog"}
    Output: ["cats and dog","cat sand dog"]

    DFS s="catsanddog"

    1) dfs("catsanddog", "", {Dict}, [])

    i=1: "c" does not exist in the dict
    i=2: "ca" does not exist in the dict
    i=3: "cat" exists in the dict
    dfs("sanddog", "cat ")
    i=4: "cats" exists in the dict
    dfs("anddog", "cats ")
    ...
    i=10: "catsanddog" not in dict

    2) dfs("sanddog", "cat ")
    i=1: "s" does not exist in the dict
    ...
    i=4: "sand" exists in the dict
    dfs("dog", "cat sand ")

    3) dfs("anddog", "cats ")
    i=1: "a" does not exist in the dict
    ...
    i=3: "and" exists in the dict
    dfs("dog", "cats and ")
*/
vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> words(wordDict.begin(), wordDict.end());
    vector<string> sentences;
    dfs(s, "", words, sentences);
    return sentences;
}

void dfs(string s, string sentence, unordered_set<string>& words, vector<string>& sentences) {
    if(s.empty()) {
        sentence.pop_back();
        sentences.push_back(sentence);
        return;
    }
    for(int i = 1; i <= s.length(); i++) {
        if(!words.count(s.substr(0,i))) {
            continue;
        }
        dfs(s.substr(i), sentence + s.substr(0,i) + " ", words, sentences);
    }
}
