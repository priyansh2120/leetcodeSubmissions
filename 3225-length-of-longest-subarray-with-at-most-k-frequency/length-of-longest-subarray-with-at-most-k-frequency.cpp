class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        // maintaining a sliding window and for each sliding window having a map that helps me keep track of frequency in array

        int start =0;
        int end = 0;
        int ans = 0;
        unordered_map<int, int>mpp;
        while(end<nums.size()){
            // operation 
            mpp[nums[end]]++;
            

            // check condition
            // fucked it up
            // whatever is increasing frequency is always the current element

            
            int ele = nums[end];
            end++;
            while(mpp[ele]>k){
                mpp[nums[start]]--;
                start++;
            }

                

            
            ans = max(ans, end-start);
        }
        return ans;
    }
};