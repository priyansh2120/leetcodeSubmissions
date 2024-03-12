class Solution {
private: 
    int helper(int r, int c, int m , int n, vector<vector<int>>&dp){
        if(r==m-1 and c==n-1){
            return 1;
        }
        if(r>=m or c>=n){
            return 0;
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        // down
        int d = helper(r+1, c, m ,n, dp);
        // right
        int ri = helper(r, c+1, m, n, dp);
        return dp[r][c]=d+ri;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        return helper(0, 0, m, n, dp);
    }
};