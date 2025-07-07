class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long fst = LLONG_MIN, sec = LLONG_MIN, thrd = LLONG_MIN;

        for (int num : nums) {
            if (num == fst || num == sec || num == thrd) continue;

            if (num > fst) {
                thrd = sec;
                sec = fst;
                fst = num;
            } else if (num > sec) {
                thrd = sec;
                sec = num;
            } else if (num > thrd) {
                thrd = num;
            }
        }

        return thrd == LLONG_MIN ? fst : thrd;
    }
};