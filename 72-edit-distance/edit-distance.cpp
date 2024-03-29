class Solution {
private:
    int helper(int index1, int index2, string word1, string word2, vector<vector<int>>&dp){
        if(index1<0 and index2<0){
            return 0;
        }
        if(index1<0  ){
            return index2+1;
        }
        if(index2<0){
            return index1+1;
        }
        if(dp[index1][index2]!=-1){
            return dp[index1][index2];
        }
        int t1= INT_MAX;
        int t2= INT_MAX;
        int t3= INT_MAX;
        int t4= INT_MAX;
        // case 1 match
        if(word1[index1]==word2[index2]){
            t1 = helper(index1-1, index2-1, word1, word2, dp);
        }
        else{
            // insert
            t2 = 1+helper(index1, index2-1, word1, word2, dp);
            // delete
            t3 = 1+helper(index1-1, index2, word1, word2, dp);
            // replace 
            t4= 1+helper(index1-1, index2-1, word1, word2, dp);
        }
        return dp[index1][index2]=min({t1, t2, t3, t4});
        
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return helper(n-1, m-1, word1, word2, dp);
    }
};