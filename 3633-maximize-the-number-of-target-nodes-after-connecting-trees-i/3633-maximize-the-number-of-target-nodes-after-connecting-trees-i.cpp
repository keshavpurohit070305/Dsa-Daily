class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        
        vector<vector<int>> tree1(n), tree2(m);
        
        for (auto& edge : edges1) {
            tree1[edge[0]].push_back(edge[1]);
            tree1[edge[1]].push_back(edge[0]);
        }
        
        for (auto& edge : edges2) {
            tree2[edge[0]].push_back(edge[1]);
            tree2[edge[1]].push_back(edge[0]);
        }
        
        auto countReachable = [](const vector<vector<int>>& tree, int start, int maxDist) {
            if (maxDist < 0) return 0;
            
            vector<bool> visited(tree.size(), false);
            queue<pair<int, int>> q;
            q.push({start, 0});
            visited[start] = true;
            
            int count = 0;
            while (!q.empty()) {
                auto [node, dist] = q.front();
                q.pop();
                count++;
                
                if (dist < maxDist) {
                    for (int neighbor : tree[node]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push({neighbor, dist + 1});
                        }
                    }
                }
            }
            return count;
        };
        
        vector<int> tree1Counts(n);
        for (int i = 0; i < n; i++) {
            tree1Counts[i] = countReachable(tree1, i, k);
        }
        
        vector<int> tree2Counts(m);
        for (int i = 0; i < m; i++) {
            tree2Counts[i] = countReachable(tree2, i, k - 1);
        }
        
        int maxTree2Count = 0;
        for (int count : tree2Counts) {
            maxTree2Count = max(maxTree2Count, count);
        }
        
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = tree1Counts[i] + maxTree2Count;
        }
        
        return result;
    }
};