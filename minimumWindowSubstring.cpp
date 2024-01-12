string minWindow(string s, string t) {
    string res = "";

    // Key: letter, value: frequency
    unordered_map<char,int> window;
    unordered_map<char,int> target;

    for(auto& ch: t) {
        target[ch]++;
    }
    int target_count = target.size();
    int characters_met = 0;

    string candidate = "";
    int left_window_boundary = 0;

    for(int i = 0; i < s.length(); i++) {
        candidate += s[i];
        if(target.find(s[i]) != target.end()) {
            // Character exists in target string
            window[s[i]]++;
            if(window[s[i]] == target[s[i]]) {
                characters_met++;
            }
        }
        if(characters_met == target_count) {
            if(res == "") {
                res = candidate;
            }

            while(true) {
                // Pop characters
                auto got = target.find(s[left_window_boundary]);
                if(got != target.end()) {
                    char candidate_remove = s[left_window_boundary];
                    if(window[candidate_remove]-1 < target[candidate_remove]) {
                        break;
                    }
                    else {
                        window[candidate_remove]--;
                    }
                }
                candidate = candidate.substr(1, candidate.length()-1);
                left_window_boundary++;

            }
            if(res.length() > candidate.length()) {
                res = candidate;
            }
        }
    }

    return res;
}
