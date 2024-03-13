class Solution {
// helper func to do the thing babe
private:
    bool helper(int index, int sum, vector<int>&nums, int total, vector<vector<int>>&dp){
        if(sum*2==total){
            return 1;
        }
        if(sum*2>total or index>=nums.size()){
            return 0;
        }
        if(dp[index][sum]!=-1){
            return dp[index][sum];
        }
        
        // take
        bool l = helper(index+1, sum+nums[index],nums, total, dp);
        bool r = helper(index+1, sum,nums, total, dp);
        return dp[index][sum]=l||r;
    }
public:
    bool canPartition(vector<int>& nums) {
        
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
        }
        vector<vector<int>>dp(nums.size(), vector<int>(sum+1, -1));
        return helper(0,0,  nums, sum, dp);
    }
};