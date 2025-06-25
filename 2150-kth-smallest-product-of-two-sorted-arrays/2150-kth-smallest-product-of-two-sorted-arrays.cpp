class Solution {
public:
    long long countLessEqual(vector<int>& nums1, vector<int>& nums2, long long x) {
        int n = nums1.size(), m = nums2.size();
        long long count = 0;
        for (int i = 0; i < n; ++i) {
            long long a = nums1[i];
            if (a > 0) {
                int l = 0, r = m;
                while (l < r) {
                    int mid = (l + r) / 2;
                    if (a * (long long)nums2[mid] <= x) l = mid + 1;
                    else r = mid;
                }
                count += l;
            } else if (a < 0) {
                int l = 0, r = m;
                while (l < r) {
                    int mid = (l + r) / 2;
                    if (a * (long long)nums2[mid] <= x) r = mid;
                    else l = mid + 1;
                }
                count += m - l;
            } else {
                if (x >= 0) count += m;
            }
        }
        return count;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long l = -1e10, r = 1e10;
        while (l < r) {
            long long mid = l + (r - l) / 2;
            if (countLessEqual(nums1, nums2, mid) < k) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};
