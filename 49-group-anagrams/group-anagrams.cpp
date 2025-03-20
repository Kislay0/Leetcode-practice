class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size()==1) return {strs};
        unordered_map<string, vector<string>> mp;
        for (string s : strs){
            string temp = s;
            sort(temp.begin(), temp.end());
                mp[temp].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto element : mp){
            ans.push_back(element.second);
        }
        return ans;
        
    }
};