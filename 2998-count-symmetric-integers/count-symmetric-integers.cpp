class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i = low; i <= high; i++) {
            // if (i<10 || (i>=100 && i<1000)) {
            //     i = pow(10, (int)log10(i)+1);
            //     continue;
            // }
            if(10<=i && i<100 && i%11==0){
                ans++;
            }else if(1000<i && i<10000){
                int left=(i/1000)+(i%1000/100);
                int right=(i%100/10)+(i%10);
                if(left==right){
                    ans++;
                }
            }
        }
        return ans;
    }
};