class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        vector<vector<int>> count(n, vector<int>(26, 0));
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) q.push(i);
        }

        int visited = 0;
        int result = 0;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            visited++;

            int c = colors[u] - 'a';
            count[u][c]++;
            result = max(result, count[u][c]);

            for (int v : graph[u]) {
                for (int i = 0; i < 26; ++i) {
                    count[v][i] = max(count[v][i], count[u][i]);
                }
                if (--indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return visited == n ? result : -1;
    }
};
