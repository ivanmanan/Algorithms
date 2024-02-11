bool validWordAbbreviation(string word, string abbr) {
    int i = 0;
    int j = 0;
    int nums = 0;
    if(abbr == "") {
        return false;
    }
    while(i < word.length() && j < abbr.length()) {
        if(isdigit(abbr[j])) {
            if(nums == 0 && abbr[j] == '0') {
                // No leading zeros
                return false;
            }
            while(j < abbr.length() && isdigit(abbr[j])) {
                nums = nums * 10 + (abbr[j] - '0');
                j++;
            }
            i += nums;
            nums = 0;
        }
        else {
            if(word[i] != abbr[j]) {
                return false;
            }
            i++;
            j++;
        }
    }
    return i == word.length() && j == abbr.length();
}
