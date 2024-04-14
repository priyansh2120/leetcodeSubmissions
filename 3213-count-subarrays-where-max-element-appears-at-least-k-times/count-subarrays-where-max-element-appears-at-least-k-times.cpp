class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = ((long long )n*(long long)(n+1))/2;
        int i=0; 
        int j=0; 
        int maxi= *max_element(nums.begin(), nums.end());
        int cnt=0;

        while(j<n){
            if(nums[j]==maxi){
                cnt++;
            }

            while(cnt>=k){
                if(nums[i]==maxi){
                    cnt--;
                }
                i++;
            }
            ans-=(j-i+1);
            j++;
        }
        return ans;
    }
};