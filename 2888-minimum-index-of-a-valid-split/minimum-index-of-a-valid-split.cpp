auto _ = cin.tie(nullptr)->sync_with_stdio(false);
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int dif = -1;
        unordered_map<int,int> mp;
        for (int num : nums){
            mp[num]++;
        }
        int n = nums.size();
        int cnt = 0;
        int major = INT_MIN;
        for (auto row : mp){
            if (row.second>cnt){
                cnt = row.second;
                major = row.first;
            }
        }
        int val = 0;
        for (int i = 0; i< n; i++){
            if (nums[i] == major) val++;
            if ((val > (i+1)/2) && (cnt-val > (n-i-1)/2)) return i;
        }
        return -1;

    }
};