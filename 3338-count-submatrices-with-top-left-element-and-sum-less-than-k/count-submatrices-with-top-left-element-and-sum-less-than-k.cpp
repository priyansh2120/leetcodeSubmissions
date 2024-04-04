class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                dp[i][j]= grid[i-1][j-1]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            }
        }
        int cnt=0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(dp[i][j]<=k){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};