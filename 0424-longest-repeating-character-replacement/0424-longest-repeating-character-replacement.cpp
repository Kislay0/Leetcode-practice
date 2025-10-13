class Solution {
public:
    int characterReplacement(string s, int k) {
        int mlen = 0, mcnt = 0;
        vector<int> freq(26,0);
        int lo = 0;
        for (int hi = 0; hi< (int) s.size(); hi++){
            freq[s[hi]-'A']++;
            mcnt = max(mcnt, freq[s[hi]- 'A']);
            while((hi - lo + 1) - mcnt > k){
                // cout<<lo<<" "<<hi<<" ";
                // cout<<mcnt<<endl;
                freq[s[lo++]-'A']--;
            }
            mlen = max(mlen, hi - lo + 1);
        }
        return mlen;
    }
};