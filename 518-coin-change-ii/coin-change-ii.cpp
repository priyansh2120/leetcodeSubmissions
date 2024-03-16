class Solution {
private:
    int helper(int index, int amount, vector<int>&coins, vector<vector<int>>&dp){
        if( amount<0){
            return 0;
        }
        if(index<0){
            if(amount==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }
        int l = helper(index, amount-coins[index], coins, dp);
        int r = helper(index-1, amount, coins, dp);
        return dp[index][amount]=l+r;
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(), vector<int>(amount+1, -1));
        return helper(coins.size()-1, amount, coins, dp);
    }
};