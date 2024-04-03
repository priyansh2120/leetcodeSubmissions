class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prevMin = 1e9;
        int ans = 0;
        int n = prices.size();
        for(int i=0; i<n; i++){
            prevMin = min(prevMin, prices[i]);
            ans = max(ans, prices[i]-prevMin);
        }
        return ans;
    }
};