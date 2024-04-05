class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                dp[i][j]= matrix[i-1][j-1]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            }
        }
        int ans =0;
        for(int i=1; i<=n; i++){
            for(int j=i; j<=n; j++){
                unordered_map<int, int>mpp;
                mpp[0]=1;
                for(int k =1; k<=m; k++){
                    int curr_sum = dp[j][k]-dp[i-1][k];


                    int rem = curr_sum - target;
                    if(mpp.find(rem)!=mpp.end()){
                        ans+=mpp[rem];
                    }
                    mpp[curr_sum]++;
                }
            }
        }
        return ans;
    }
};