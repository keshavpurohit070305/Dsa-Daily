class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, -1), dist2(n, -1);
        
        auto bfs = [&](int start, vector<int>& dist) {
            queue<int> q;
            q.push(start);
            dist[start] = 0;
            
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                
                if (edges[curr] != -1 && dist[edges[curr]] == -1) {
                    dist[edges[curr]] = dist[curr] + 1;
                    q.push(edges[curr]);
                }
            }
        };
        
        bfs(node1, dist1);
        bfs(node2, dist2);
        
        int result = -1;
        int minMax = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minMax) {
                    minMax = maxDist;
                    result = i;
                }
            }
        }
        
        return result;
    }
};