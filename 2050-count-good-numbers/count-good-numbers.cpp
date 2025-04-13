class Solution {
private:
    long long mod_pow(long long base, long long exp) {
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
    static const long long mod = 1e9 + 7;
    int countGoodNumbers(long long n) {
        return (int)((mod_pow(5, ((n+1)>>1)) * mod_pow(4, (n>>1))) % mod);
    }
};