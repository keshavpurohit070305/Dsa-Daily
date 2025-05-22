class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        
        vector<vector<int>> starts(n);
        for (int i = 0; i < m; i++) {
            starts[queries[i][0]].push_back(i);
        }
        
        vector<int> diff(n + 1, 0);
        priority_queue<int> available;
        int currentDec = 0;
        int used = 0;
        
        for (int i = 0; i < n; i++) {
            currentDec += diff[i];
            
            for (int idx : starts[i]) {
                available.push(queries[idx][1]);
            }
            
            int needed = nums[i] - currentDec;
            
            while (needed > 0 && !available.empty()) {
                int endPos = available.top();
                available.pop();
                
                if (endPos >= i) {
                    currentDec++;
                    diff[endPos + 1]--;
                    needed--;
                    used++;
                }
            }
            
            if (needed > 0) {
                return -1;
            }
        }
        
        return m - used;
    }
};