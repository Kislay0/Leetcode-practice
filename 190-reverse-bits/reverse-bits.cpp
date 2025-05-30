class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rbits = 0;
        for (int i = 0; i<32; i++){
            rbits = (rbits<<1);
            if (n & 1) rbits = rbits | 1;
            n = n>>1;
            if (!n) {
                rbits = rbits<<(31-i);
                break;
            }
        }
        return rbits;        
    }
};