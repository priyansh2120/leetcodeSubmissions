class Solution {
private:
    int helper(int index1, int index2, string s, string t, vector<vector<int>>&dp){
        if(index2<0){
            return 1;
        }
        if(index1<0){
            return 0;
        }
        if(dp[index1][index2]!=-1){
            return dp[index1][index2];
        }
        // case 1 match
        int t1=0;
        int t2=0;
        // int t3 =0;
        if(s[index1]==t[index2])
            t1 = helper(index1-1, index2-1, s, t, dp);
            
        t2 = helper(index1-1, index2, s, t, dp);
        
        return dp[index1][index2]=t1+t2;
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n, vector<int>(m, -1));

        return helper(n-1, m-1, s, t, dp);
    }
};