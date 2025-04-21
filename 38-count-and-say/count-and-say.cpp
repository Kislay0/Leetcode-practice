class Solution {
public:
    string countAndSay(int n) {
        if (n==1) return "1";
        string ans = "", str = countAndSay(n - 1);
        int cnt = 0;
        char curr = str[0];
        for (char s : str){
            if (s == curr){
                cnt ++;
            }
            else{
                ans +=  to_string(cnt) + curr;
                curr = s;
                cnt = 1;
            }
        }
        ans +=  to_string(cnt) + curr;
        return ans;
    }
};