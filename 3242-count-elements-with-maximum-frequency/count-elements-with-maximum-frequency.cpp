class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int>mpp;
        int ans =0;
        int maxi = -1e5;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;
            maxi = max(mpp[nums[i]], maxi);
        }
        for(auto it:mpp){
            if(it.second == maxi){
                ans+=it.second;
            }
        }
        return ans;
    }
};