class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0; 
        
        deque<pair<int, int>> dq;
        dq.push_front({0, 0});
        
        while (!dq.empty()) {
            auto [row, col] = dq.front();
            dq.pop_front();
            
            
            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i];
                int nc = col + dc[i];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int newDist = dist[row][col] + grid[nr][nc];
                    if (newDist < dist[nr][nc]) {
                        dist[nr][nc] = newDist;
                        if (grid[nr][nc] == 0) {
                            dq.push_front({nr, nc}); 
                        } else {
                            dq.push_back({nr, nc}); 
                        }
                    }
                }
            }
        }
        
        return dist[n - 1][m - 1]; 
    }
};