class Solution {
private:
    int helper(int index, int buy, int tran, vector<int>& prices, vector<vector<vector<int>>>&dp){
        if(index>=prices.size() or tran<=0){
            return 0;
        }
        if(dp[index][buy][tran]!=-1){
            return dp[index][buy][tran];
        }
        if(buy){
            int l = -prices[index]+helper(index+1, 0, tran, prices, dp);
            int r = helper(index+1, 1, tran, prices, dp);
            return dp[index][buy][tran]=max(l, r);
        }
        else{
            int l = prices[index]+helper(index+1, 1, tran-1, prices, dp);
            int r = helper(index+1, 0, tran, prices, dp);
            return dp[index][buy][tran]=max(l,r);
        }
        return 0;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(), vector<vector<int>>(2, vector<int>(k+1, -1)));
        return helper(0, 1, k, prices, dp);
    }
};
