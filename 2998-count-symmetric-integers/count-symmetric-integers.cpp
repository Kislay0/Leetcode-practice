class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i = low; i <= high; i++) {
            // if (!((int)log10(i) & 1)) {
            //     i = pow(10, (int)log10(i)+1);
            //     continue;
            // }
            if ((i>10 && i<100) ||(i>1000 && i <10000)){
                int s = 0;
                int temp = i;
                int n = (log10(i)+1)/2;
                for (int j = 0; j<n; j++){
                    s += temp%10;
                    temp /= 10;
                }
                for (int j = 0; j<n; j++){
                    s -= temp%10;
                    temp /= 10;
                }
                if (!s) ans++;
            }
        }
        return ans;
    }
};