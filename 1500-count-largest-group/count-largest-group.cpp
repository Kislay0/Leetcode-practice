class Solution {
private:
    int digsum (int n){
        int sum = 0;
        while (n){
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
public:
    int countLargestGroup(int n) {
        if (n < 10) return n;
        vector<int> grp (37,0);
        for (int i = 0; i< 10; i++){
            grp[i] ++;
        }
        int i = 10;
        while (i <= n){
            int k = digsum(i);
            for (int j = i; (j <= n)&& (j < i+10); j++){
                // cout<<j<<" 1: "<<k<<endl;
                grp[k++]++;
            }
            i+= 10;
        }

        sort(grp.begin(), grp.end(), greater<int>());

        int ans = 0;
        // for (int val: grp){
        //     cout<<val<<" ";
        // }
        for (int val: grp){
            if (val != grp[0]) return ans;
            ans++;
        }
        return ans;

    }
};