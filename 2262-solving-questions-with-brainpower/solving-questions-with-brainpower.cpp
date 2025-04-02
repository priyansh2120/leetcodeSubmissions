
class Solution {
public:
    long long helper(vector<vector<int>>& questions, int index, int size, vector<long long>&dp){
        if (index>=questions.size()){
            return 0;
        }
         
        if (dp[index]!=-1) return dp[index];
        long long pt=questions[index][0];
        int skip=questions[index][1];
        dp[index]=max(pt+helper(questions, index+skip+1, size, dp), helper(questions, index+1, size, dp));
        return dp[index];
    }
    long long mostPoints(vector<vector<int>>& questions ) {
        int n =  questions.size();
        vector<long long>dp(n+1, -1);
        return helper(questions, 0, n, dp);   
    }
};
