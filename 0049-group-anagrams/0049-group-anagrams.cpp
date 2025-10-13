class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;
        for (string str: strs){
            vector<int> temp(26,0);
            for (char ch: str){
                temp[ch-'a']++;
            }
            if(mp.find(temp) == mp.end()) mp[temp]={str};
            else mp[temp].push_back(str);
        }
        vector<vector<string>> ans;
        for (const auto& pair : mp){
            ans.push_back(pair.second);
        }
        return ans;
    }
};