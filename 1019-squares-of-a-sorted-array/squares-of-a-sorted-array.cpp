class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans(nums.size(), 0);
        int i=0;
        int j= nums.size()-1;
        int k = nums.size()-1;
        while(j>=i and i<nums.size() and j>=0 and k>=0){
            if(abs(nums[i])>=abs(nums[j])){
                ans[k]= nums[i]*nums[i];
                k--;
                i++;
            }
            else{
                ans[k]= nums[j]*nums[j];
                k--;
                j--;
            }
        }
        return ans;
    }
};