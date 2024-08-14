class Solution {
private:
    bool check(int mid, vector<int>& nums){
        int cnt =0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<=mid){
                cnt++;
            }
        }
        cout<<mid<<' '<<cnt<<endl;
        return cnt>mid;
    }
public:
    int findDuplicate(vector<int>& nums) {
        // bs approach
        int n = nums.size();
        int low =1;
        int high = n-1;

        int ans = 0;
        for(int i=0; i<20; i++){

            int mid = (low+high)/2;
            
            if(check(mid, nums)){
                ans= mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }   
        }
        return ans;
    }
};