class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long val = 0, lo = 0, hi = 0;
        for (int dif: differences){
            val += dif;
            lo = min(lo, val);
            hi = max(hi, val);
            if (abs(dif)>abs(upper-lower)) return 0;
        }
        int lowerlimit = lower + (hi - lo);
        return ((upper - lowerlimit + 1) > 0)? (upper - lowerlimit + 1) : 0;
    }
};