class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int s=0, e=0;
        int ans = 0;
        int prev=nums[s];
        long long op =0;
        while(e<nums.size()){
            op+=(long long)((long long)nums[e]-(long long)prev)*(long long)((long long)e-(long long)s);
            prev= nums[e];

            while(op>k){
                op-=(long long)((long long)nums[e]-(long long)nums[s]);
                s++;
            }
            ans = max(ans, e-s+1);
            e++;
        }
        return ans;
    }
};