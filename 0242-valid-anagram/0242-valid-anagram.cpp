class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map <char, int> characs;

        for( auto str : s ){
            characs[str]++;
        }
        for (auto str: t){
            characs[str]--;
        }
        for (auto str : characs){
            if (str.second != 0) return false;
        }
        return true;
    }
};