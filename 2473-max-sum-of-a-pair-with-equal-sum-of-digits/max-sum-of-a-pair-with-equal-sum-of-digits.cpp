class Solution {
private:
    int digitSum(int num){
        int ans =0;

        while(num>0){
            ans+=(num%10);
            num/=10;
        }
        return ans;
    }
public:
    int maximumSum(vector<int>& nums) {
        int n= nums.size();
        map<int, vector<int>>mpp;
        for(int i=0; i<n; i++){
            int digSum = digitSum(nums[i]);
            mpp[digSum].push_back(nums[i]);
        }
        int ans = -1e5;
        for(auto it:mpp){
            vector<int>sums = it.second;
            sort(sums.begin(), sums.end());
            if(sums.size()>=2){
                int temp = 0;
                temp+=sums[sums.size()-1];
                temp+=sums[sums.size()-2];
                ans = max(ans, temp);
            }
        }
        return (ans==-1e5)?-1:ans;
    }
};