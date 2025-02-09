
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<long long, long long>mpp;
        int n = nums.size();
        long long bad_pairs = n;
        bad_pairs*=(n-1);
        bad_pairs/=2;

        mpp[nums[0]]++;
        // cout<<mpp.count(1);
        for(int i=1; i<n; i++){
            long long curr = nums[i]-i;
            if(mpp.count(curr)>0){
                bad_pairs-=mpp[curr];
            }
            mpp[curr]++;
        }
        return bad_pairs;
    }
};