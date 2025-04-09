class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        map<int, int, greater<int>> freq;
        for (int num: nums){
            freq[num]++;
        }
        int itr = 0;
        int ans = 0;
        for(auto [num, f]: freq){
            if (num>k){
                if (!f&1) return -1;
                ans++;
            }else if(num== k) continue;
            else return -1;
        }
        return ans;
    }
};