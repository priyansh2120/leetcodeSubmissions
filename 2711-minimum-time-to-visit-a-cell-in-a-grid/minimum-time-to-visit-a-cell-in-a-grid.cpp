class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // -1 condition
        
        if(grid[0][1] > 1 and grid[1][0] > 1){
            return -1;
        }
        
        // main code
        vector<vector<int>> dis(n + 1, vector<int> (m + 1, 1e6));
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> q;
        
        q.push({0,{0,0}}); // dist, src_x, src_y
        
        dis[0][0] = 0;
        
        while(!q.empty()){
            int d = q.top().first;
            int x = q.top().second.first;
            int y = q.top().second.second;
            q.pop();
            if (d > dis[x][y]) continue; // Skip if `d` is not updated to latest version!
            
            // move down
            if(x + 1 < n){
                if(dis[x + 1][y] > d + 1){
                    
                    if(grid[x + 1][y] <= d + 1){
                        dis[x + 1][y] = d + 1;
                    }
                    else{
                        dis[x + 1][y] = ((grid[x + 1][y] % 2) == (d % 2) ? (grid[x + 1][y] + 1) : grid[x + 1][y]);
                    }
                    q.push({dis[x + 1][y],{x + 1, y}});
                    
                }
                
            }
            
            // move up
            if(x - 1 >= 0){
                if(dis[x - 1][y] > d + 1){
                    
                    if(grid[x - 1][y] <= d + 1){
                        dis[x - 1][y] = d + 1;
                    }
                    else dis[x - 1][y] = ((grid[x - 1][y] % 2) == (d % 2) ? (grid[x - 1][y] + 1) : grid[x - 1][y]);
                    q.push({dis[x - 1][y], {x - 1, y}});
                }
                
            }
            
            // move right
            if(y + 1 < m){
                if(dis[x][y + 1] > d + 1){
                    
                    if(grid[x][y + 1] <= d + 1){
                        dis[x][y + 1] = d + 1;
                    }
                    else dis[x][y + 1] = (dis[x][y + 1], (grid[x][y + 1] % 2) == (d % 2) ? (grid[x][y + 1] + 1) : grid[x][y + 1]);
                    q.push({dis[x][y + 1], {x, y + 1}});
                }
                
            }
            
            // move left
            if(y - 1 >= 0){
                if(dis[x][y - 1] > d + 1){
                    
                    if(grid[x][y - 1] <= d + 1){
                        dis[x][y - 1] = d + 1;
                    }
                    else dis[x][y - 1] = ((grid[x][y - 1] % 2) == (d % 2) ? (grid[x][y - 1] + 1) : grid[x][y - 1]);
                    q.push({dis[x][y - 1],{x, y - 1}});
                }
                
            }
            
            
        }
        
        return dis[n - 1][m - 1];
    }
};