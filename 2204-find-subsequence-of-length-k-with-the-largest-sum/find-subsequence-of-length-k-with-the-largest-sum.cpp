class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> vpp;
        for(int i = 0; i < nums.size(); i++) {
            vpp.push_back({nums[i], i});
        }
        int n = nums.size();
        sort(vpp.begin(), vpp.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first; 
        });
        
        for(int i = n - 1; i >= k; i--) { // corrected loop condition
            vpp.pop_back();
        }
        sort(vpp.begin(), vpp.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second; 
        });
        vector<int> ans;
        for(auto it: vpp) {
            ans.push_back(it.first);
        }
        return ans;
    }
};
