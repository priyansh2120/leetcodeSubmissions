class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // o(n) space approch
        // keep a prefix mul array and a suffix mul array
        // keep  using it for the ans pre[i-1]*suffix[i+1]
        // answer array will be returned
        // o(1) space approach
        int n = nums.size();
        // O(1) solution 
        vector<int> output(n);
        output[0] = 1;
        int left = 1;
        // prefix multipler is stored in output array
        for(int i=1; i<n; i++){
            output[i] = left* nums[i-1];
            left *= nums[i-1];
        }
        int right = 1;
        for(int i=n-1; i>=0; i--){
            output[i] *= right;
            right *= nums[i];
        }
        return output;
    }
};