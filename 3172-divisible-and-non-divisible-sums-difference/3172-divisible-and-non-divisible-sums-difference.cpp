class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum_divisible = 0;
        int sum_not_divisible = 0;

        for (int i = 1; i <= n; ++i) {
            if (i % m == 0) {
                sum_divisible += i;
            } else {
                sum_not_divisible += i;
            }
        }

        return sum_not_divisible - sum_divisible;
    }
};
