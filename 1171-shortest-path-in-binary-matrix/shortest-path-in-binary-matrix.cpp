class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        queue<pair<int,pair<int,int>>> q;
        int n=grid.size();
        q.push({0,{0,0}});
        if(grid[0][0]==0 && n==1)   
            return 1;

        vector<vector<int>> dist(n,vector<int>(n,1e5));

        dist[0][0]=1;

        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;

        while(!q.empty()){
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            for(int dr=-1;dr<=1;dr++){
                for(int dc=-1;dc<=1;dc++){
                    int nrow=row+dr;
                    int ncol=col+dc;
                    if(nrow>=0 && nrow<n && ncol>=0 && 
                    ncol<n && grid[nrow][ncol]==0 && dis+1<dist[nrow][ncol]){
                        dist[nrow][ncol]=dis+1;
                        if(nrow==n-1 && ncol==n-1){
                            return dis+2;
                        }
                        q.push({dis+1,{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};