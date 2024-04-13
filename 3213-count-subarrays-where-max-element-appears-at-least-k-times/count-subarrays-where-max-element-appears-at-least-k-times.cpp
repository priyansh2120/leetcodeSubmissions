class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = ((long long )n*(long long)(n+1))/2;
        int i=0; 
        int j=0; 
        int maxi= *max_element(nums.begin(), nums.end());
        unordered_map<long long, long long>mpp;
        while(j<n){
            mpp[nums[j]]++;

            while(mpp[maxi]>=k){
                mpp[nums[i]]--;
                i++;
            }
            ans-=(j-i+1);
            j++;
        }
        return ans;
    }
};