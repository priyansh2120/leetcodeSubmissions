class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long int product =1;
        int s=0, e=0, ans =0;
        while(e<nums.size()){
            product *= nums[e];
            while(product>=k and s<=e){
                product/=nums[s];
                s++;
            }
            // cout<<s<<' '<<e<<endl;
            ans +=(e-s+1);
            e++;
        }
        return ans;
    }
};