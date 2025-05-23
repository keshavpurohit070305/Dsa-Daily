class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int nodeCount = nums.size();
        vector<int> profitFromFlip;
        long long currentSum = 0;
        
        for (int node = 0; node < nodeCount; node++) {
            currentSum += nums[node];
            int valueAfterOperation = nums[node] ^ k;
            int benefit = valueAfterOperation - nums[node];
            profitFromFlip.push_back(benefit);
        }
        
        sort(profitFromFlip.rbegin(), profitFromFlip.rend());
        
        for (int idx = 0; idx < nodeCount - 1; idx += 2) {
            if (profitFromFlip[idx] + profitFromFlip[idx + 1] > 0) {
                currentSum += profitFromFlip[idx] + profitFromFlip[idx + 1];
            } else {
                break;
            }
        }
        
        return currentSum;
    }
};