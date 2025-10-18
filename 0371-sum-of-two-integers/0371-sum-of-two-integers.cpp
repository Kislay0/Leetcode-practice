class Solution {
public:
    int getSum(int a, int b) {
        int bit = 0, ans = 0;
        int c = 0;
        for (int i = 0; i<32; i++){
            bit = (a&1)^(b&1)^c;
            c = ((a&1)&(b&1)) | ((a&1)&c) | ((b&1)&c);
            ans |= (bit<<i);
            a>>=1;
            b>>=1;
        }
        return ans;
    }
};