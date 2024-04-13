class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0;
        int j =0;
        int zcnt =0;
        int ans = 0;
        while(j<nums.size()){
            if(nums[j]==0){
                zcnt++; 
            }
            while(zcnt>1){
                if(nums[i]==0) {
                    zcnt--;
                }
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans-1;
    }
};