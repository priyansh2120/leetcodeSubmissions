class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cnt0=0;
        int s=0, e=0, ans =0;
        while(e<nums.size()){
            if(nums[e]==0){
                cnt0++;
            }
            while(cnt0>k){
                if(nums[s]==0){
                    cnt0--;
                }
                s++;
            }
            ans = max(ans, e-s+1);
            e++;
        }
        return ans;
    }
};