class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // new approach 
        // O(n^2) time O(n) space
        int n = nums.size();
        int maxi = -1e5;
        vector<int>dp(n, 1);
        for(int i=0; i<n; i++){
            for(int j= 0; j<i; j++){
                if(nums[j]<nums[i]){
                    dp[i]= max(dp[i], 1+dp[j]);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};