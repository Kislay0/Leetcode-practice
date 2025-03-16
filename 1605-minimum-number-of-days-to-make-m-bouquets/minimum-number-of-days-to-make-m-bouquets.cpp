class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (bloomDay.size()/k < m) return -1;
        auto canmake = [&] (int day){
            int cnt = 0, total = 0;
            for (int bloom: bloomDay){
                if (bloom>day) {
                    cnt = 0;
                    continue;
                }
                cnt ++;
                if (cnt>= k){
                    total ++;
                    cnt = 0;
                }
            }
            return (total>=m) ? true : false;
        };
        int mid, lo = INT_MAX, hi = 0;
        for (int bloom: bloomDay){
            lo = min(lo, bloom);
            hi = max(hi, bloom);
        }
        while(lo<hi){
            mid = lo + ((hi-lo)>>1);
            if (canmake(mid)){
                hi = mid;
            }
            else{
                lo = mid+1;
            }
        }
        return lo;
    }
};