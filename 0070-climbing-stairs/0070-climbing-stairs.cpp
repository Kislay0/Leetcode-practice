class Solution {
public:
    int climbStairs(int n) {
        int prev = 1;
        int next = 1;
        if (n<= 3) return n;
        for (int i = 1; i< n; i++){
            int temp = next + prev;
            prev = next;
            next = temp;
        }
        return next;
    }
};