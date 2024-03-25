class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        // negate the visited kind of problem
        // predefined technique to solve the problem
        vector<int>freq = nums;
        vector<int>ans;
        for(int i=0; i<nums.size(); i++){
            if(freq[nums[i]-1]<0){
                ans.push_back(nums[i]);
            }
            else{
                freq[nums[i]-1]= -1*freq[nums[i]-1];
            }
        }
        return ans;
    }
};