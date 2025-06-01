class Solution {
public:
    long long distributeCandies(int n, int limit) {
       
        long long total = comb(n + 2, 2);
        
        if (n > limit) {
            total -= 3 * comb(n - limit + 1, 2);
        }
        
        if (n > 2 * limit + 1) {
            total += 3 * comb(n - 2 * limit, 2);
        }
        
        if (n > 3 * limit + 2) {
            total -= comb(n - 3 * limit - 1, 2);
        }
        
        return total;
    }
    
private:
    long long comb(int n, int r) {
        if (n < 0 || r < 0 || n < r) return 0;
        if (r == 0 || r == n) return 1;
        if (r == 1) return n;
        if (r == 2) return (long long)n * (n - 1) / 2;

        long long result = 1;
        for (int i = 0; i < r; i++) {
            result = result * (n - i) / (i + 1);
        }
        return result;
    }
};