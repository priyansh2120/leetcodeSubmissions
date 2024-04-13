class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0;
        int j =0;
        int zcnt =0;
        int ans = 1;
        
        while(j<nums.size()){
            if(nums[j]==0){
                zcnt++;
                j++;
            }
            else{
               j++; 
            }
            
            if(zcnt>1){
                while(nums[i]!=0){
                    i++;
                }
                i++;
                zcnt--;
            }
            ans=max(ans, j-i+1);
        }
        return ans-2;
    }
};