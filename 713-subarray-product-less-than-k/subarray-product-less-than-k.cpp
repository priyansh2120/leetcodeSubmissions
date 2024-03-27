class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // approach 1 
        // brute find all the subarray using O(n^2) and check if product is less than k
        // more optimal
        // use sliding window and find the subarrays with product<k and then add up no of subarray for that particular subarray

        // pointers
        int start = 0;
        int end =0;
        int product = 1;
        int ans = 0;
        int n = nums.size();
        if(k==0){
            return 0;
        }
        while(end<n){
            // operation
            product *= nums[end];

            end++;

            
            while(product>=k && start<end){
                product/= nums[start];
                start++;
            }
            ans+=(end-start);
        }
        
     

        
        return ans;
    }
};