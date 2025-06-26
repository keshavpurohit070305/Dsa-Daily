class Solution {
public:
    int longestSubsequence(string s, int k) {
        int count = 0, zeros = 0;
        long long val = 0, pow2 = 1;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '0') {
                ++zeros;
            } else {
                if (pow2 <= k && val + pow2 <= k) {
                    val += pow2;
                    ++count;
                }
            }
            if (pow2 <= k) pow2 <<= 1;
        }
        return count + zeros;
    }
};
