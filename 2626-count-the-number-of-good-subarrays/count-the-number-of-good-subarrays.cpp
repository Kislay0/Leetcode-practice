const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {

        long long ans = 0;
        long long pairs = 0;
        unordered_map<int,int> mp;
        int left = 0;
        int n = nums.size();
        for (int i = 0; i< n; i++){
            mp[nums[i]]++;
            if (mp[nums[i]] > 2){
                pairs += mp[nums[i]] - 1;
            }
            else if (mp[nums[i]] > 1) {
                pairs += (mp[nums[i]] * (mp[nums[i]]-1))>>1;
            }
            while (pairs >= k){
                ans += n-i;
                mp[nums[left]]--;
                if (mp[nums[left]] < 1) mp.erase(nums[left]);
                else if (mp[nums[left]] > 1) pairs -=  mp[nums[left]];
                else pairs -= mp[nums[left]] * (mp[nums[left]] + 1) / 2;
                left++;
            }
        }
        return ans;
    }
};