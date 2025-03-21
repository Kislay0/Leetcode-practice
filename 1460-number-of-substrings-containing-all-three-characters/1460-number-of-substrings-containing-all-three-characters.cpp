class Solution {
public:
    int numberOfSubstrings(string s) {
        int left =0, right = 0, ans = 0;
        int a = 0, b = 0, c = 0, n = s.length();
        while(right < n){
            if (s[right] == 'a') a++;
            else if (s[right] == 'b') b++;
            else c++;
            // cout<<"1: "<<ans<<endl;
            // cout<<s.substr(left,right+1)<<" "<<a<<" "<<b<<" "<<c<<endl;
                while (a>0 && b >0 && c > 0) {
                    if (s[left] == 'a') a--;
                    else if (s[left] == 'b') b--;
                    else c--;
                    left++;
                    ans += n - right ;
                    // cout<<"3: "<<ans<<endl;
                    // cout<<s.substr(left,right+1)<<" "<<a<<" "<<b<<" "<<c<<endl;
                }
            right++;
        }
        return ans;
    }
};