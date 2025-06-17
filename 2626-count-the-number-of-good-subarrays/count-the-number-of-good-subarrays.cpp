// const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {

        long long ans = 0;
        long long pairs = 0;
        unordered_map<int,int> mp;
        int left = 0;
        const int n = nums.size();
        for (int i = 0; i< n; i++){
            pairs  += mp[nums[i]]++;
            while (pairs >= k){
                ans += n-i;
                pairs -= --mp[nums[left]];
                left++;
            }
        }
        return ans;
    }
};