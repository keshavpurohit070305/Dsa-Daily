class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<bool> hasBox(n, false);
        vector<bool> hasKey(n, false);
        vector<bool> opened(n, false);
        
        for (int box : initialBoxes) {
            hasBox[box] = true;
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (hasBox[i] && (status[i] == 1 || hasKey[i])) {
                q.push(i);
                opened[i] = true;
            }
        }
        
        int totalCandies = 0;
        
        while (!q.empty()) {
            int box = q.front();
            q.pop();
            
            totalCandies += candies[box];
            
            for (int key : keys[box]) {
                hasKey[key] = true;
                if (hasBox[key] && !opened[key]) {
                    q.push(key);
                    opened[key] = true;
                }
            }
            
            for (int newBox : containedBoxes[box]) {
                hasBox[newBox] = true;
                if (!opened[newBox] && (status[newBox] == 1 || hasKey[newBox])) {
                    q.push(newBox);
                    opened[newBox] = true;
                }
            }
        }
        
        return totalCandies;
    }
};