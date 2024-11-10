class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> v(32, 0);
        int i, j = 0;
        int val = 0;
        int ans = INT_MAX;

        for (i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int idx = 0;
            while (num > 0) {
                int rem = num % 2;
                if (rem == 1) {
                    v[idx] += 1;
                }
                num = num / 2;
                idx++;
            }

            val |= nums[i];
            while (i >= j && val >= k) {
                ans = min(ans, (i - j + 1));
                int numToReset = nums[j];
                int idx = 0;
                while (numToReset > 0) {
                    int rem = numToReset % 2;
                    if (rem == 1) {
                        v[idx] -= 1;
                    }
                    numToReset = numToReset / 2;
                    idx++;
                }
                val = 0;
                for (int l = 0; l < v.size(); l++) {
                    if (v[l] >= 1) {
                        val |= (1 << l);
                    }
                }
                j++;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};