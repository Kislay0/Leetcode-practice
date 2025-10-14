class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mid = 0, lo = 0, hi = *max_element(piles.begin(), piles.end());
        auto caneat= [&](int val){
            long long ans = 0;
            for (int x: piles) ans+= x/val + (x%val != 0);
            // cout<<val<<" "<<ans<<"\n";
            if (ans <= h) return true;
            return false;
        };
        int cur = 0;
        while(lo<hi){
            mid = hi - (hi-lo)/2;
            if(!caneat(mid)) {
                lo = mid;
            }
            else {
                hi = mid -1;
                cur = mid;
            }
        }
        return cur;
    }
};