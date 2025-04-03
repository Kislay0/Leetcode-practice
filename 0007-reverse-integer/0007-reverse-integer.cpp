class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) return 0;
        int parity = (x>0) ? 1: -1;
        x = abs(x);
        long ans = 0;
        while (x>0){
            ans = 10*ans + x%10;
            x = x/10;
        }
        if (ans> INT_MAX) return 0;
        return ans*parity;
    }
};