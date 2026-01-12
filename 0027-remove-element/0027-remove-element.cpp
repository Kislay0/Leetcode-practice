class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> sol;
        for (int num: nums){
            if (num == val) continue;
            sol.push_back(num);
        }
        nums = sol;
        return (int)sol.size();
    }
};