class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int s=0;
        int e = 0;
        map<int, int>mpp;
        int curr= 0;
        int ans = -1e5;
        while(e<nums.size()){
            mpp[nums[e]]++;
            curr+=nums[e];
            while(mpp[nums[e]]>1){
                mpp[nums[s]]--;
                curr-=nums[s];
                s++;

            }
            ans= max(ans, curr);
            e++;
        }
        return ans;
    }
};