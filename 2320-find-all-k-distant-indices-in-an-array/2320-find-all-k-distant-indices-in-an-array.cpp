class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res, pos;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == key) pos.push_back(i);
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < pos.size(); j++) {
                if (abs(i - pos[j]) <= k) {
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};
