class Solution {
private:
    int helper(int row, int col, vector<vector<int>>& grid, int dr[], int dc[],
                vector<vector<int>>&dp){

        int maxi = 0;
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        for(int i=0; i<3; i++){
            if(row+dr[i]<grid.size() and row+dr[i]>=0 and col+dc[i]<grid[0].size() 
                and grid[row][col]<grid[row+dr[i]][col+dc[i]]){

                maxi = max(maxi, 1+helper(row+dr[i], col+dc[i], grid, dr, dc, dp));
            }
            
        }
        return dp[row][col]=maxi;
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        // at each we have an option of exploring either (row - 1, col + 1), (row, col + 1) or (row + 1, col + 1)
        int n = grid.size();
        int m = grid[0].size();
        int dr[]={-1,0,1};
        int dc[]={1,1,1};
        int ans = -1e6;
        vector<vector<int>>dp(n, vector<int>(m, -1));
        for(int i=0; i<n; i++){
            ans = max(ans, helper(i, 0, grid, dr, dc, dp));
        }
        return ans;
    }
};