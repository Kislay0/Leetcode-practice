auto _ = cin.tie(nullptr) -> sync_with_stdio(false);
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        while (i <nums.size()){
            while (nums[i]>0 && nums[i] <= nums.size() && nums[i] != nums[nums[i]-1]){
                (swap (nums[i], nums[nums[i]-1]));
            }
            i++;
        }
        for (int i = 0; i< nums.size(); i++){
            if ( i+1 != nums[i]) {
                return i+1;
            }
        }
        return nums.size()+1;
    }
};