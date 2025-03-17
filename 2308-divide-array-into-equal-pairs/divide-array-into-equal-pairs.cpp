class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int>mpp;
        int n= nums.size();
        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }
        for(auto it:mpp){
            if(it.second&1){
                return false;
            }
        }
        return true;
    }
};