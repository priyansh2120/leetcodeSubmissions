class Solution {
private:
    int atmost(vector<int>&nums, int goal){
        int s=0, e=0; 
        int ans =0;
        int sum =0;
        while(e<nums.size()){
            sum+=nums[e];
            
            while(sum>goal){
                sum-=nums[s];
                s++;
            }
            ans += (e-s+1);
            e++;
        }
        return ans;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if(goal==0){
            return atmost(nums, goal);
        }
        return atmost(nums, goal)-atmost(nums, goal-1);
    }
};