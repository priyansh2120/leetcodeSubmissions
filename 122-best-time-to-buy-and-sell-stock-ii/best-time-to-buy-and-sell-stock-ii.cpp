class Solution {
private:
    int helper(int index, int buy, vector<int>&prices, vector<vector<int>>&dp){
        // buy
        if(index>=prices.size()){
            return 0;
        }
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        if(buy){
            int l = -prices[index]+helper(index+1, 0, prices, dp);
            int r = helper(index+1, 1, prices, dp);

            return dp[index][buy]=max(l, r);
        }
        else{
            int l = prices[index]+helper(index+1, 1, prices, dp);

            int r = helper(index+1, 0, prices, dp);
            return dp[index][buy]=max(l,r);
        }

        return 0;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return helper(0, 1, prices, dp);
    }
};