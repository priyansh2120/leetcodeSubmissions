class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long ans = 0;
        
        for (int i = 0; i < n; i++) {
            int new_lower = lower - nums[i];
            int new_upper = upper - nums[i];
            
            int left = lower_bound(nums.begin() + i + 1, nums.end(), new_lower) - nums.begin();
            int right = upper_bound(nums.begin() + i + 1, nums.end(), new_upper) - nums.begin() - 1;
            

            if (left <= right) {
                ans += right - left + 1;
            }
        }
        
        return ans;
    }
};