class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int npi = -1;
        int maxi = -1;
        int mini = -1;
        int n = nums.size();
        int i= 0;
        long long ans = 0;
        while(i<n){
            if(nums[i]==minK){
                mini = i;
            }
            if(nums[i]==maxK){
                maxi=i;
            }
            if(nums[i]>maxK or nums[i]<minK){
                npi = i;
            }
            ans+= max(0LL, min((long long)maxi, (long long)mini)-(long long)npi);
            i++;
        }
        return ans;
    }
};