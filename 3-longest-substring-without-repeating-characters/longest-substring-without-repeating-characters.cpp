class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i =0;
        int j=0;
        map<char, int>mpp;
        int n = s.size();
        int ans = 0;
        while(j<n){
            mpp[s[j]]++;
            for(auto it:mpp){
                if(it.second>1){
                    while(mpp[it.first]>1){
                        mpp[s[i]]--;
                        i++;
                    }
                    break;
                }
            }
            ans = max(j-i+1, ans);
            j++;
        }
        return ans;
    }
};