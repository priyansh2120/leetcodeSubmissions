class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // matrix containing 0 and 1
        // m x n
        // nearest 0 to every 1
        // 0 0 0
        // 0 1 0
        // 0 0 0
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>ans = mat;

        queue<pair<int, int>>q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==1){
                    ans[i][j]=m*n;
                }
                else{
                    q.push({i,j});
                }
            }
        }
        int dr[] = {0, 0, 1, -1};
        int dc[] = {-1, 1, 0, 0};
        while(!q.empty()){
            auto it = q.front();
            int cr = it.first;
            int cc = it.second;
            q.pop();

            for(int i=0; i<4; i++){
                int nr = cr+dr[i];
                int nc = cc+dc[i];

                if(nr>=0 and nr<n and nc>=0 and nc<m and ans[nr][nc]>ans[cr][cc]+1){
                    ans[nr][nc]=ans[cr][cc]+1;
                    q.push({nr, nc});
                }
            }
            
        }
        return ans;
    }
};