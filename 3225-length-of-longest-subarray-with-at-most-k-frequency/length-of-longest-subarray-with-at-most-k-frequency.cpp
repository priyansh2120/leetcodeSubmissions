class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i =0;
        int j=0;
        unordered_map<int, int>mpp;
        int ans =0;
        int n = nums.size();
        while(j<n){
            mpp[nums[j]]++;
            
                
            while(mpp[nums[j]]>k){
                mpp[nums[i]]--;
                i++;
            }
                
            
            ans = max(j-i+1, ans);
            j++;
        }
        return ans;
    }
};