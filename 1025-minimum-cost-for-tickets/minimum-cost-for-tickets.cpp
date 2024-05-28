class Solution {
private:
    int minCostHelper(int ind, vector<int>& days, vector<int>&costs, vector<int>&dp){
        if(ind>=days.size()){
            return 0;
        }
        int ans = 1e9;
        if(dp[ind]!=-1){
            return dp[ind];
        }

        for(int i=0; i<3; i++){
            int newEle = days[ind];
            if(i==0){
                newEle+=1;
            }
            if(i==1){
                newEle+=7;
            }
            if(i==2){
                newEle+=30;
            }
            
            int newInd = ind;
            while(newInd<days.size() and days[newInd]<newEle){
                newInd++;
            }
            
            ans = min(ans, costs[i]+minCostHelper(newInd, days, costs, dp));
        }
        ans = min(ans, costs[0]+minCostHelper(ind+1, days, costs, dp));
        return dp[ind]=ans;

    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // at each index i have three options 
        // and based on that i can return the minimum cost
        vector<int>dp(days.size(), -1);
        return minCostHelper(0, days, costs, dp);
    }
};