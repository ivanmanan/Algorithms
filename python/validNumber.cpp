bool isNumber(string s) {
    // There must be at least one digit in either the base or exponent to be valid
    bool seenDigit = false;
    bool seenExponent = false;
    bool seenDecimal = false;

    for(int i = 0; i < s.length(); i++) {

        if(s[i] == '+' || s[i] == '-') {
            // Must be 0th index OR exponent is preceding
            if(i == 0 || tolower(s[i-1]) == 'e') {
                continue;
            }
            else {
                return false;
            }
        }
        else if(isdigit(s[i])) {
            seenDigit = true;
            continue;
        }
        else if(s[i] == '.') {
            if(seenExponent) {
                return false;
            }
            if(seenDecimal) {
                return false;
            }
            seenDecimal = true;
        }
        else if(tolower(s[i]) == 'e') {
            if(seenExponent) {
                return false;
            }
            seenExponent = true;
            if(!seenDigit) {
                return false;
            }
            seenDigit = false;
        }
        else {
            return false;
        }
    }
    if(!seenDigit) {
        return false;
    }
    return true;
}
