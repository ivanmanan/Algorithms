bool isPalindrome(string s) {
    int j = s.length()-1;
    int i = 0;
    while(i < j) {
        if((isalpha(s[i]) && isalpha(s[j])) || isdigit(s[i]) && isdigit(s[j])) {
            if(tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        else if((isalpha(s[i]) && isdigit(s[j])) || (isdigit(s[i]) && isalpha(s[j]))) {
            return false;
        }
        while(i < s.length() && !(isalpha(s[i]) || isdigit(s[i]))) {
            i++;
        }
        while(j >= 0 && !(isalpha(s[j]) || isdigit(s[j]))) {
            j--;
        }
    }
    return true;
}
