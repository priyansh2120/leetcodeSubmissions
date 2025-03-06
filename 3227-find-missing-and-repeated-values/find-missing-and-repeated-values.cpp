class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        map<int, int>mpp;
        vector<int>ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                mpp[grid[i][j]]++;
                if(mpp[grid[i][j]]==2){
                    ans.push_back(grid[i][j]);
                }
            }
        }
        for(int i=1; i<=n*n; i++){
            if(mpp[i]==0){
                ans.push_back(i);
            }
        }
        return ans;

    }
};