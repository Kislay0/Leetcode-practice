class Solution {
public:
    int reverse(int x) {
        if (x == -2147483648) return 0;
        int parity;
        if (x>0) parity = 1;
        else {
            parity = -1;
            x = -x;
        }
        long ans = 0;
        while (x>0){
            ans = 10*ans + x%10;
            x = x/10;
        }
        if (ans> INT_MAX) return 0;
        return ans*parity;
    }
};