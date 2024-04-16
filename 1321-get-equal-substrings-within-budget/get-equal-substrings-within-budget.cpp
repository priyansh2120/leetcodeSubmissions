class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int st =0, e=0;
        int ans = 0;
        int n = s.size();
        int cost = 0;
        while(e<n){
            cost += abs((int)(s[e]-t[e]));

            while(cost>maxCost){
                cost -= abs((int)(s[st]-t[st]));
                st++;
            }

            ans = max(ans, e-st+1);
            e++;
        }
        return ans;
    }
};