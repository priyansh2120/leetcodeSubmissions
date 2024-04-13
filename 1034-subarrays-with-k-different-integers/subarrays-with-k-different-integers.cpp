class Solution {
private:
    int atmost(vector<int>&nums, int k){
        int i=0; 
        int j=0; 
        map<int, int>mpp;
        int ans=0;
        int n = nums.size();
        while(j<n){
            mpp[nums[j]]++;

            while(mpp.size()>k){
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0){
                    mpp.erase(nums[i]);
                }
                i++;
                
            }

            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k)- atmost(nums, k-1);
    }
};