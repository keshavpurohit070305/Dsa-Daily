class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums.front();
        while (left < right) {
            int mid = (left + right) / 2, count = 0;
            for (int i = 1; i < nums.size(); ++i) {
                if (nums[i] - nums[i - 1] <= mid) {
                    ++count;
                    ++i;
                }
            }
            if (count >= p) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
