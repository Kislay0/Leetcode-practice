class Solution {
    public int getSum(int a, int b) {
        int c = a&b;
        int ans = a^b;
        while (c != 0){
            int temp = c<<1;
            c = ans & temp;
            ans ^= temp;
        }
        return ans;
    }
}