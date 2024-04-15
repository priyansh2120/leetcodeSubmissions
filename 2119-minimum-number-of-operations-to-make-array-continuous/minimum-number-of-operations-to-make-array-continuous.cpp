class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<int>s;
        for(auto it: nums){
            s.insert(it);
        }
        int n = nums.size();
        int uni = s.size();
        vector<int>v(s.begin(), s.end());
        int st =0;
        int e =0;
        int ans =0;
        while(e<v.size()){
            while(v[e]-v[st]>n-1){
                st++;
            }
            ans = max(ans, e-st+1);
            e++;
        }
        return n-ans;
    }
};