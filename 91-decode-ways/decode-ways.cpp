class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        int n = s.size();
        if (n==1){
            return 1;
        }
        if (s[n-1] == '0' && (s[n-2] - '0') > 2) {
            return 0;
        }
        if (n==2){
            if (s[1] == '0' || (s[0] - '0') > 2 || ((s[0] == '2') && ((s[1] - '0') > 6))) return 1;
            return 2;
        }
        vector<int> dp(n);
        dp[0] = 1;
        if (s[1] == '0'){
            if (s[0] - '0' > 2) return 0;
                dp[1] = 1;
        }
        else if ((s[0] - '0') > 2 || ((s[0] == '2') && ((s[1] - '0') > 6)) || s[2] == '0') dp[1] = 1;
        else dp[1] = 2;
        for (int i = 2; i< n; i++){
            if (s[i-1] == '0'){
                if (s[i] == '0') return 0;
                dp[i] = dp[i-1];
            }else if (s[i]== '0'){
                if (s[i-1] - '0' > 2) return 0;
                dp[i] = dp[i-1];
            }
            else if ((s[i-1] - '0') > 2 || ((s[i-1] == '2') && ((s[i] -'0') > 6))) {
                dp[i] = dp[i-1];
            }else if ((i < n-1) && (s[i+1] == '0')){
                if (s[i] - '0' > 2) return 0;
                dp[i] = dp[i-1];
            }
            else dp[i] = dp[i-1] + dp[i-2];
                
        }
        return dp.back();
    }
};