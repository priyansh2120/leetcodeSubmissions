class Solution {
private:
    int helper(int index, int n, int k, vector<int>&arr, vector<int>&dp){
        if(index>=n){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int i = index;
        int res = -1e5;
        int maxi = arr[index];
        while(i-index+1<=k and i<n){
            maxi = max(maxi, arr[i]);
            res = max(res,maxi*(i-index+1)+helper(i+1, n, k, arr, dp));
            i++;
        }
        return dp[index]=res;

    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // looks like partition dp
        // first take the whole array and pass it to a helper function 
        // since the length of array can be maximum of k
        // make the partition and dont let the length exceed k
        vector<int>dp(arr.size(), -1);
        return helper(0, arr.size(), k, arr, dp);
    }
};