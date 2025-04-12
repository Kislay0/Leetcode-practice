class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i = low; i <= high; i++) {
            if (!((int)log10(i) & 1)) {
                i = pow(10, (int)log10(i)+1);
                continue;
            }
            int s = 0;
            int temp = i;
            int n = (log10(i)+1)/2;
            // cout<<i<<" N: "<<n<<endl;
            for (int j = 0; j<n; j++){
                s += temp%10;
                temp /= 10;
                // cout<<"HERE"<<endl;
            }
            // cout<<s<<endl;
            for (int j = 0; j<n; j++){
                s -= temp%10;
                temp /= 10;
            }
            if (!s) ans++;
        }
        return ans;
    }
};