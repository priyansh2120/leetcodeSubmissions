class Solution {
public:
    int rows, cols;

    int getBoundValue(int i, int j, const vector<vector<int>>& dp) {
        if (i < 0 || j < 0)
            return 0;
        if (i >= rows)
            i = rows - 1;
        if (j >= cols)
            j = cols - 1;
        return dp[i + 1][j + 1];
    }

    vector<vector<int>> matrixBlockSum(vector<vector<int>>& matrix, int k) {
        rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp;
        dp.resize(rows + 1, vector<int>(cols + 1, 0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dp[i + 1][j + 1] =
                    dp[i + 1][j] + matrix[i][j] + dp[i][j + 1] - dp[i][j];
            }
        }
        // cout << getBoundValue(1, 1, dp); 
        vector<vector<int>> ans(rows, vector<int>(cols));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                ans[i][j] = getBoundValue(i + k, j + k, dp) -
                            getBoundValue(i - k - 1, j + k, dp) -
                            getBoundValue(i + k, j - k - 1, dp) +
                            getBoundValue(i - k - 1, j - k - 1, dp);
            }
        }
        return ans;
    }
};