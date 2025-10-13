class Solution {
    int checker(vector<int> seen, vector<int> freq){
        bool flag = true;
        for (int i = 0; i<26; i++){
            if (seen[i]>freq[i]) return -1;
            if (seen[i] < freq[i]) flag = false;
        }
        return (int) flag;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size()>s2.size()) return false;
        vector<int> freq(26,0), seen(26,0);
        for (char ch: s1){
            freq[ch-'a']++;
        }
        int lo = 0, j = 0;;
        for (int i = 0; i < s1.size(); ++i) seen[s2[i] - 'a']++;
        int cnt = 0;
        for (int i = 0; i<26; i++){
            if (freq[i] == seen[i]) cnt++;
        }
        if (cnt == 26) return true;
        for (int i = s1.size(); i< (int) s2.size(); i++){
            seen[s2[i]-'a']++;
            if(seen[s2[i]-'a'] == freq[s2[i]-'a']) cnt++;
            else if ( seen[s2[i]-'a'] == freq[s2[i]-'a'] + 1)cnt--;
            if(seen[s2[lo] - 'a'] == freq[s2[lo] - 'a']) cnt--;
            else if(seen[s2[lo] - 'a'] == freq[s2[lo] - 'a'] + 1) cnt++;
            seen[s2[lo]-'a']--;
            lo++;
            if (cnt == 26) return true;
        }
        return false;
    }
};