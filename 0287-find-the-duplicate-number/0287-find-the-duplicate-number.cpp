class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        do{
            fast = nums[nums[fast]];
            slow = nums[slow];
        }while( slow!= fast);
        slow = 0;
        while(slow!= fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

