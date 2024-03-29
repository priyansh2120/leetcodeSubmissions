class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
          // i have two option at every index
        // so what to include in the answer
        // we have to decide greedily
        // so whatever makes up for the smallest scs if taken that particular element in the scs
        // so we need to know the length of scs if taken

        // suppose thats there in dp array at index i, j
        // Fill the DP table
        // tabulation as recusive is somewhere fucking up
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // Construct the shortest common supersequence
        string result;
        int i = n, j = m;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                result = str1[i - 1] + result;
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                result = str1[i - 1] + result;
                i--;
            } else {
                result = str2[j - 1] + result;
                j--;
            }
        }
        while (i > 0) {
            result = str1[i - 1] + result;
            i--;
        }
        while (j > 0) {
            result = str2[j - 1] + result;
            j--;
        }
        return result;
    }
};
