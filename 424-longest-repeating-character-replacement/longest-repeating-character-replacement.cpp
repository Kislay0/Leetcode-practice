class Solution {
public:
    int maxind (vector<int> v){
        auto maxIt = max_element(v.begin(), v.end());
        return distance(v.begin(), maxIt);
    }
    int characterReplacement(string s, int k) {
        vector<int> freq (26);
        int i = 0, j = 0;
        int len = 0, maxlen = 0;
        while (j<s.size()){
            freq[s[j++]-'A']++;
            len++;
            while ((len - *max_element(freq.begin(), freq.end()))> k && i<=j){
                cout<<i<<" "<<j<<endl;
                freq[s[i++]-'A']--;
                len--;
            }
            maxlen = max(len, maxlen);
        }
        return maxlen;
    }
};