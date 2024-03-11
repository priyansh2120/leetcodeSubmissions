class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mpp;
        for (auto it : order) {
            mpp[it] = 0;
        }
        
        for (auto it : s) {
            if (mpp.find(it) != mpp.end()) {
                mpp[it]++;
            }
        }
        
        string ans;
        for (auto it : order) {
            ans.append(mpp[it], it);
        }
        
        for (auto it : s) {
            if (mpp.find(it) == mpp.end()) {
                ans.push_back(it);
            }
        }
        
        return ans;
    }
};