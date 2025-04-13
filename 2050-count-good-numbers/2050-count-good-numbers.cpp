class Solution {
private:
    long long mod_pow(long long base, long long exp, int mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }
public:
    int countGoodNumbers(long long n) {
        long long e_num = (n+1)/2;
        long long o_num = n/2;
        long long mod = 1e9 + 7;

        long long ans = mod_pow(5, e_num, mod);
        long long ans1 =mod_pow(4, o_num, mod);
        long long an = (ans * ans1) % mod;

        return (int)(an);
    }
};