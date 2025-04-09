class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        map<int, int, greater<int>> freq;
        for (int num: nums){
            freq[num]++;
        }
        auto itr = freq.begin();
        // if (itr->second == 1) {
        //     cout<<"HOW??"<<endl;
        //     cout<<itr->second;
        //     return -1;
        // }
        int ans = 0;
        for(auto [num, f]: freq){
            if (num>k){
                ans++;
            }else if(num== k) continue;
            else return -1;
        }
        return ans;
    }
};