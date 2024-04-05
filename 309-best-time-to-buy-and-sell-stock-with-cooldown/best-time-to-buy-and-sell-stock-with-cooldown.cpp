class Solution {
private:
    int helper(int index, int cool, vector<int>& prices, vector<vector<int>>&dp){
        if(index>=prices.size()){
            return 0;
        }
        if(dp[index][cool]!=-1){
            return dp[index][cool];
        }
        if(cool==0){
            int l = -prices[index]+helper(index+1, 2, prices, dp);
            int r = helper(index+1, 0, prices, dp);
            return dp[index][cool]=max(l,r);
        }
        else if(cool == 2){
            int l = prices[index]+helper(index+1, 1, prices, dp);
            int r = helper(index+1, 2, prices, dp);
            return dp[index][cool]=max(l,r);
        }
        else if(cool==1){
            return dp[index][cool]=helper(index+1, 0, prices, dp);
        }
        return 0;
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(), vector<int>(3, -1));
        return helper(0, 0, prices, dp);
    }
};