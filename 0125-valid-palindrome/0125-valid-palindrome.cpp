class Solution {
public:
    bool isPalindrome(string s) {
        int lo = 0;
        int hi = s.size()-1;
        while (lo<hi){
            if(!isalnum(s[lo])){
                lo++;
                continue;
            }
            if(!isalnum(s[hi])){
                hi--;
                continue;
            }
            if (toupper(s[lo]) != toupper(s[hi])) return false;
            lo++;
            hi--;
        }
        return true;
    }
};