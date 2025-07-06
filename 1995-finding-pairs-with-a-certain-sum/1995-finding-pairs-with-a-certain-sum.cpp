class FindSumPairs {
    vector<int> nums1, nums2;
    unordered_map<int, int> freq;

public:
    FindSumPairs(vector<int>& n1, vector<int>& n2) {
        nums1 = n1;
        nums2 = n2;
        for (int num : nums2) freq[num]++;
    }

    void add(int index, int val) {
        freq[nums2[index]]--;
        nums2[index] += val;
        freq[nums2[index]]++;
    }

    int count(int tot) {
        int res = 0;
        for (int x : nums1) {
            int target = tot - x;
            if (freq.count(target)) res += freq[target];
        }
        return res;
    }
};
