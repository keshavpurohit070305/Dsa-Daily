class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        int mod = 1e9 + 7;
        vector<long long> fact(n), inv(n);
        fact[0] = 1;
        for (int i = 1; i < n; i++) fact[i] = fact[i - 1] * i % mod;
        inv[n - 1] = power(fact[n - 1], mod - 2, mod);
        for (int i = n - 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
        
        long long choose = fact[n - 1] * inv[k] % mod * inv[n - 1 - k] % mod;
        long long powPart = power(m - 1, n - 1 - k, mod);
        long long ans = m * choose % mod * powPart % mod;
        return ans;
    }

private:
    long long power(long long a, long long b, int mod) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }
};
