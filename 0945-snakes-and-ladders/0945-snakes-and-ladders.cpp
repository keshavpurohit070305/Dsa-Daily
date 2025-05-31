class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int target = n * n;
        vector<bool> visited(target + 1, false);
        queue<pair<int, int>> q;
        
        q.push({1, 0});
        visited[1] = true;
        
        while (!q.empty()) {
            auto [pos, moves] = q.front();
            q.pop();
            
            if (pos == target) {
                return moves;
            }
            
            for (int dice = 1; dice <= 6; dice++) {
                int next = pos + dice;
                if (next > target) break;
                
                auto [row, col] = getCoordinates(next, n);
                if (board[row][col] != -1) {
                    next = board[row][col];
                }
                
                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }
        
        return -1;
    }
    
private:
    pair<int, int> getCoordinates(int num, int n) {
        num--;
        int row = n - 1 - num / n;
        int col = (num / n) % 2 == 0 ? num % n : n - 1 - num % n;
        return {row, col};
    }
};