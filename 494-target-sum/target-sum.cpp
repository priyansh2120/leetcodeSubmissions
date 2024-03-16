class Solution {
private:
    int helper(int index, int sum, int target, vector<int>&nums){
        if(index<0){
            if(sum==target){
                return 1;
            }
            else{
                return 0;
            }
        }
        // take 
        int l = helper(index-1, sum-nums[index], target, nums);
        // not take 
        int r = helper(index-1, sum+nums[index], target, nums);
        return l+r;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // can give the index to either + or -
        target= abs(target);
        return helper(nums.size()-1, 0, target, nums);
    }
};