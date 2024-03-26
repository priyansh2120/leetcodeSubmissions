class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // first approach in the interview iterate by taking some no i over all the elements presented as j
        // second approach sort the array and look for the missing no
        // first look for 1 if not found return 
        // then subsequent diff if not 1 return 
        // if not return maxi+1;

        // O(n)time and O(n) space is easy
        // can we use the spaces by nos except between 1 and n+1 as extra space

        // observation 1 : no lies between 1 and n+1
        
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]>0 and nums[i]<=n and nums[i]!=nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
            }
            // cases can be the new number is also not in range
            while(nums[i]>0 and nums[i]<=n and nums[i]!=nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for(int i=0; i<n; i++){
            if(nums[i]!=i+1){
                return i+1;
            }

        }
        return n+1;
    }
};