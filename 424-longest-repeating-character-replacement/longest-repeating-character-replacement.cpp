class Solution {
public:
    int maxind (vector<int> v){
        auto maxIt = max_element(v.begin(), v.end());
        return distance(v.begin(), maxIt);
    }
    int characterReplacement(string s, int k) {
        vector<int> freq (26);
        int i = 0, j = 0;
        int len = 0;
        while (j<s.size()){
            freq[s[j++]-'A']++;
            while ((j - i - *max_element(freq.begin(), freq.end()))> k && i<=j){
                freq[s[i++]-'A']--;
            }
            len = max(len, j-i);
        }
        return len;
    }
};