int maxNumberOfBalloons(string text) {
    unordered_map<char,int> freq;
    for(auto& ch: text) {
        freq[ch]++;
    }
    int b = freq['b'];
    int a = freq['a'];
    int l = freq['l'];
    int o = freq['o'];
    int n = freq['n'];

    int ba = min(b,a);
    int ban = min(ba,n);
    int ln = min(l,o)/2;

    return min(ban,ln);
}
