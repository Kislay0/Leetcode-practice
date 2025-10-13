class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s=="") return 0;
        int lo = 0, hi = 1, ans = 1;
        unordered_set<char> mp;
        mp.insert(s[0]);
        while(hi<s.size()){
            while(mp.find(s[hi]) != mp.end()){
                mp.erase(s[lo++]);
            }
            mp.insert(s[hi]);
            int n = mp.size();
            ans = max(hi-lo+1, ans);
            hi++;
        }
        return ans;
    }
};