class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<int>temp;
        vector<vector<int>>ans;
        for(int i=0; i<nums.size(); i++){
            if((i)%3==0 and i!=0){
                if(temp[2]-temp[0]>k){
                    return {};
                }
                ans.push_back(temp);
                temp.clear();
            }
            temp.push_back(nums[i]);
        }
        if(temp[2]-temp[0]>k){
                    return {};
        }
        ans.push_back(temp);
        return ans;
    }
};